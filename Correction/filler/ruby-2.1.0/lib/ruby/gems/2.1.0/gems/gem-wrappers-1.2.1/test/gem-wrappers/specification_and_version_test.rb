require 'test_helper'
require 'gem-wrappers/specification'
require 'gem-wrappers/version'

describe GemWrappers::Specification do

  before do
    GemWrappers::Specification.instance_variable_set(:@gem_wrappers_spec, nil)
  end

  it "finds specification" do
    GemWrappers::Specification.find.name.must_equal("gem-wrappers")
  end

  it "gets specification version" do
    GemWrappers::Specification.version.must_equal(GemWrappers::VERSION)
  end

  it "does not find imaginary gems" do
    GemWrappers::Specification.find("imaginary-gem").must_equal(nil)
  end

end
