require 'test_helper'
require 'tempfile'
require 'gem-wrappers'

describe GemWrappers do
  before do
    file = Tempfile.new('gem_dir')
    @test_path = file.path
    file.close
    file.unlink
  end

  after do
    FileUtils.rm_rf(@test_path)
  end

  describe "configuration" do
    it "reads configured file" do
      Gem.configuration[:wrappers_environment_file] = "/path/to/environment"
      GemWrappers.environment_file.must_equal("/path/to/environment")
      Gem.configuration[:wrappers_environment_file] = nil
    end
    it "reads configured file" do
      Gem.configuration[:wrappers_path] = "/path/to/wrappers"
      GemWrappers.wrappers_path.must_equal("/path/to/wrappers")
      Gem.configuration[:wrappers_path] = nil
    end
  end

  it "does create environment and wrapper" do
    Gem.configuration[:wrappers_path] = File.join(@test_path, "wrappers")
    Gem.configuration[:wrappers_environment_file] = File.join(@test_path, "environment")
    Gem.configuration[:wrappers_path_take] = 0
    GemWrappers.install(%w{rake test})
    File.exist?(File.join(@test_path, "environment")).must_equal(true)
    File.exist?(File.join(@test_path, "wrappers", "gem")).must_equal(true)
    File.exist?(File.join(@test_path, "wrappers", "rake")).must_equal(true)
    File.exist?(File.join(@test_path, "wrappers", "ruby")).must_equal(true)
    File.exist?(File.join(@test_path, "wrappers", "test")).must_equal(true)
    File.exist?(File.join(@test_path, "wrappers", "other")).must_equal(false)
  end

  it "does remove wrapper" do
    Gem.configuration[:wrappers_path] = File.join(@test_path, "wrappers")
    Gem.configuration[:wrappers_environment_file] = File.join(@test_path, "environment")
    Gem.configuration[:wrappers_path_take] = 0
    GemWrappers.install(%w{rake})
    File.exist?(File.join(@test_path, "wrappers", "rake")).must_equal(true)
    GemWrappers.uninstall(%w{rake})
    File.exist?(File.join(@test_path, "wrappers", "rake")).must_equal(false)
  end

end
