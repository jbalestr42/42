require 'test_helper'
require 'tempfile'
require 'gem-wrappers/command'

describe WrappersCommand do
  subject do
    WrappersCommand.new
  end

  before do
    $stdout = StringIO.new
    $stderr = StringIO.new
  end

  after do
    $stdout = STDOUT
    $stderr = STDERR
  end

  it "has some strings" do
    subject.arguments.class.must_equal(String)
    subject.usage.class.must_equal(String)
    subject.defaults_str.class.must_equal(String)
    subject.description.class.must_equal(String)
    subject.program_name.class.must_equal(String)
  end

  it "shows help on unknown command" do
    subject.options[:args] = ['wrong']
    subject.execute
    $stderr.string.must_equal("Unknown wrapper subcommand: wrong\n")
    $stdout.string.must_equal(subject.description)
  end

  it "does show" do
    Gem.configuration[:wrappers_environment_file] = "/path/to/environment"
    Gem.configuration[:wrappers_path] = "/path/to/wrappers"

    subject.options[:args] = []
    subject.execute

    Gem.configuration[:wrappers_environment_file] = nil
    Gem.configuration[:wrappers_path] = nil

    $stderr.string.must_equal("")
    $stdout.string.must_equal(<<-EXPECTED)
#{subject.description.strip}
   Wrappers path: /path/to/wrappers
Environment file: /path/to/environment
EXPECTED
  end


  describe "wrappers" do
    before do
      file = Tempfile.new('command-wrappers')
      @test_path = file.path
      file.close
      file.unlink
    end

    after do
      FileUtils.rm_rf(@test_path)
    end

    it "regenerates wrappers" do
      Gem.configuration[:wrappers_environment_file] = File.join(@test_path, "environment")
      Gem.configuration[:wrappers_path] =             File.join(@test_path, "wrappers")

      subject.instance_variable_set(:@executables, %w{rake})
      subject.options[:args] = ['regenerate']
      subject.execute

      Gem.configuration[:wrappers_environment_file] = nil
      Gem.configuration[:wrappers_path] = nil

      File.exist?(File.join(@test_path, "environment")).must_equal(true)
      File.exist?(File.join(@test_path, "wrappers", "gem")).must_equal(true)
      File.exist?(File.join(@test_path, "wrappers", "rake")).must_equal(true)
      File.exist?(File.join(@test_path, "wrappers", "ruby")).must_equal(true)
      File.exist?(File.join(@test_path, "wrappers", "test")).must_equal(false)

      $stderr.string.must_equal("")
      $stdout.string.must_equal("")
    end

    it "generates script wrapper" do
      FileUtils.mkdir_p(@test_path)
      test_file = File.join(@test_path, "test_file.sh")
      File.open(test_file, "w") do |file|
        file.puts "echo test"
      end
      Gem.configuration[:wrappers_environment_file] = File.join(@test_path, "environment")
      Gem.configuration[:wrappers_path] =             File.join(@test_path, "wrappers")

      subject.options[:args] = [test_file]
      subject.execute

      Gem.configuration[:wrappers_environment_file] = nil
      Gem.configuration[:wrappers_path] = nil

      File.exist?(File.join(@test_path, "environment")).must_equal(true)
      File.exist?(File.join(@test_path, "wrappers", "test_file.sh")).must_equal(true)

      $stderr.string.must_equal("")
      $stdout.string.must_equal("")
    end
  end

  it "finds gem executables" do
    subject.send(:executables).must_include('rake')
  end

end
