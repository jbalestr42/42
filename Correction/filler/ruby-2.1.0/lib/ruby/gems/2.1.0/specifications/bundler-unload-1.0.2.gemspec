# -*- encoding: utf-8 -*-
# stub: bundler-unload 1.0.2 ruby lib

Gem::Specification.new do |s|
  s.name = "bundler-unload"
  s.version = "1.0.2"

  s.required_rubygems_version = Gem::Requirement.new(">= 0") if s.respond_to? :required_rubygems_version=
  s.require_paths = ["lib"]
  s.authors = ["Michal Papis"]
  s.date = "2013-09-22"
  s.email = ["mpapis@gmail.com"]
  s.homepage = "https://github.com/mpapis/bundler-unload"
  s.licenses = ["Apache 2.0"]
  s.rubygems_version = "2.2.0"
  s.summary = "Allow unloading bundler after Bundler.load"

  s.installed_by_version = "2.2.0" if s.respond_to? :installed_by_version

  if s.respond_to? :specification_version then
    s.specification_version = 4

    if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
      s.add_development_dependency(%q<bundler>, [">= 0"])
    else
      s.add_dependency(%q<bundler>, [">= 0"])
    end
  else
    s.add_dependency(%q<bundler>, [">= 0"])
  end
end
