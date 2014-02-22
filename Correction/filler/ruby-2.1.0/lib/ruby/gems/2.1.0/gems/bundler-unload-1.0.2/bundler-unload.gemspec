#!/usr/bin/env ruby
# -*- encoding: utf-8 -*-

Kernel.load File.expand_path("../lib/bundler-unload/version.rb", __FILE__)

Gem::Specification.new do |s|
  s.name        = "bundler-unload"
  s.version     = BundlerUnload::VERSION
  s.licenses    = ["Apache 2.0"]
  s.authors     = ["Michal Papis"]
  s.email       = ["mpapis@gmail.com"]
  s.homepage    = "https://github.com/mpapis/bundler-unload"
  s.summary     = %q{Allow unloading bundler after Bundler.load}

  s.files       = `git ls-files`.split("\n")
  s.test_files  = `git ls-files -- {test,spec,features}/*`.split("\n")

  s.add_development_dependency "bundler"  # do not force runtime so it can be silently ignored
  #s.add_development_dependency "smf-gem"
end
