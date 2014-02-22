require 'test_helper'
require 'tempfile'
require 'gem-wrappers/environment'

describe GemWrappers::Environment do
  describe "configuration" do
    it "uses default file" do
      Gem.configuration[:wrappers_environment_file] = nil
      GemWrappers::Environment.file_name.must_equal(File.join(Gem.dir, "environment"))
      GemWrappers::Environment.new.file_name.must_equal(GemWrappers::Environment.file_name)
    end
    it "reads configured file" do
      Gem.configuration[:wrappers_environment_file] = "/path/to/environment"
      GemWrappers::Environment.file_name.must_equal("/path/to/environment")
      GemWrappers::Environment.new.file_name.must_equal("/path/to/environment")
      Gem.configuration[:wrappers_environment_file] = nil
    end
    it "uses default take" do
      Gem.configuration[:wrappers_path_take] = nil
      GemWrappers::Environment.new.path_take.must_equal(Gem.path.size + 1)
    end
    it "reads configured take" do
      Gem.configuration[:wrappers_path_take] = 0
      GemWrappers::Environment.new.path_take.must_equal(Gem.path.size)
      Gem.configuration[:wrappers_path_take] = nil
    end
  end

  describe "instance" do
    subject do
      GemWrappers::Environment.new
    end

    before do
      @test_file = Tempfile.new('environment-file')
    end

    after do
      @test_file.close
      @test_file.unlink if @test_file.path
    end

    it "calculates path part 1" do
      subject.instance_variable_set(:@path_take, 1)
      subject.path("/one/bin:/two/bin:/three/bin:/four/bin").must_equal(["/one/bin"])
    end

    it "calculates path part 3" do
      subject.instance_variable_set(:@path_take, 3)
      subject.path("/one/bin:/two/bin:/three/bin:/four/bin").must_equal(["/one/bin", "/two/bin", "/three/bin"])
    end

    it "does not overwrite existing file" do
      subject.instance_variable_set(:@file_name, @test_file.path)
      File.open(subject.file_name, "w") do |file|
        file.write("something")
      end
      subject.ensure
      File.open(subject.file_name, "r") do |file|
        file.read.must_equal("something")
      end
    end

    it "creates environment file" do
      subject.instance_variable_set(:@path, ["/one/bin", "/two/bin"])
      subject.instance_variable_set(:@gem_path, ["/one", "/two"])
      subject.instance_variable_set(:@gem_home, "/one")
      subject.instance_variable_set(:@file_name, @test_file.path)
      @test_file.close
      @test_file.unlink
      subject.ensure
      File.open(subject.file_name, "r") do |file|
        file.read.must_equal(<<-EXPECTED)
export PATH="/one/bin:/two/bin:$PATH"
export GEM_PATH="/one:/two"
export GEM_HOME="/one"
EXPECTED
      end
    end

  end
end
