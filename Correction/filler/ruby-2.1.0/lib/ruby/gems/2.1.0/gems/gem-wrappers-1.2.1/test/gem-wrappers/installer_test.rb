require 'test_helper'
require 'tempfile'
require 'gem-wrappers/installer'

describe GemWrappers::Installer do
  describe "configuration" do
    it "uses default file" do
      Gem.configuration[:wrappers_path] = nil
      GemWrappers::Installer.wrappers_path.must_equal(File.join(Gem.dir, 'wrappers'))
      GemWrappers::Installer.new(nil).wrappers_path.must_equal(GemWrappers::Installer.wrappers_path)
    end
    it "reads configured file" do
      Gem.configuration[:wrappers_path] = "/path/to/wrappers"
      GemWrappers::Installer.wrappers_path.must_equal("/path/to/wrappers")
      GemWrappers::Installer.new(nil).wrappers_path.must_equal("/path/to/wrappers")
      Gem.configuration[:wrappers_path] = nil
    end
  end

  describe "instance" do
    subject do
      GemWrappers::Installer.new('/path/to/environment')
    end

    before do
      file = Tempfile.new('wrappers')
      @test_path = file.path
      file.close
      file.unlink
    end

    after do
      FileUtils.rm_rf(@test_path)
    end

    it "doe not prefix for .sh scripts" do
      subject.instance_variable_set(:@executable, "/path/to/test.sh")
      subject.executable_expanded.must_equal("/path/to/test.sh")
    end

    it "adds ruby prefix for .rb scripts" do
      subject.instance_variable_set(:@executable, "/path/to/test.rb")
      subject.executable_expanded.must_equal("ruby /path/to/test.rb")
    end

    it "does create target dir" do
      subject.instance_variable_set(:@wrappers_path, @test_path)
      File.exist?(subject.wrappers_path).must_equal(false)
      subject.ensure
      File.exist?(subject.wrappers_path).must_equal(true)
    end

    it "creates wrapper" do
      subject.instance_variable_set(:@wrappers_path, @test_path)
      full_path = File.join(subject.wrappers_path, "rake")
      File.exist?(full_path).must_equal(false)
      subject.ensure
      subject.install("rake")
      File.open(full_path, "r") do |file|
        file.read.must_equal(<<-EXPECTED)
#!/usr/bin/env bash

if
  [[ -s "/path/to/environment" ]]
then
  source "/path/to/environment"
  exec rake "$@"
else
  echo "ERROR: Missing RVM environment file: '/path/to/environment'" >&2
  exit 1
fi
EXPECTED
      end
    end

    it "creates shell script wrapper" do
      subject.instance_variable_set(:@wrappers_path, @test_path)
      script_path = File.join(subject.wrappers_path, "example", "test.sh")
      FileUtils.mkdir_p(File.join(subject.wrappers_path, "example"))
      File.open(script_path, "w") do |file|
        file.write("echo test")
      end
      full_path = File.join(subject.wrappers_path, "test.sh")
      File.exist?(full_path).must_equal(false)
      subject.ensure
      subject.install(script_path)
      File.open(full_path, "r") do |file|
        file.read.must_equal(<<-EXPECTED)
#!/usr/bin/env bash

if
  [[ -s "/path/to/environment" ]]
then
  source "/path/to/environment"
  exec #{script_path} "$@"
else
  echo "ERROR: Missing RVM environment file: '/path/to/environment'" >&2
  exit 1
fi
EXPECTED
      end
    end

    it "creates ruby script wrapper" do
      subject.instance_variable_set(:@wrappers_path, @test_path)
      script_path = File.join(subject.wrappers_path, "example", "test.rb")
      FileUtils.mkdir_p(File.join(subject.wrappers_path, "example"))
      File.open(script_path, "w") do |file|
        file.write("puts :test")
      end
      full_path = File.join(subject.wrappers_path, "test.rb")
      File.exist?(full_path).must_equal(false)
      subject.ensure
      subject.install(script_path)
      File.open(full_path, "r") do |file|
        file.read.must_equal(<<-EXPECTED)
#!/usr/bin/env bash

if
  [[ -s "/path/to/environment" ]]
then
  source "/path/to/environment"
  exec ruby #{script_path} "$@"
else
  echo "ERROR: Missing RVM environment file: '/path/to/environment'" >&2
  exit 1
fi
EXPECTED
      end
    end

    it "removes wrapper" do
      subject.instance_variable_set(:@wrappers_path, @test_path)
      full_path = File.join(subject.wrappers_path, "rake")
      subject.ensure
      File.open(full_path, "w") do |file|
        file.puts "empty"
      end
      File.exist?(full_path).must_equal(true)
      subject.uninstall("rake")
      File.exist?(full_path).must_equal(false)
    end

  end
end
