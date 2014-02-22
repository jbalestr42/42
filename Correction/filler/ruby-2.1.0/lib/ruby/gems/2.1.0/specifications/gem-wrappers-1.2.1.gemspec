# -*- encoding: utf-8 -*-
# stub: gem-wrappers 1.2.1 ruby lib
# stub: ext/wrapper_generator/extconf.rb

Gem::Specification.new do |s|
  s.name = "gem-wrappers"
  s.version = "1.2.1"

  s.required_rubygems_version = Gem::Requirement.new(">= 0") if s.respond_to? :required_rubygems_version=
  s.require_paths = ["lib"]
  s.authors = ["Michal Papis"]
  s.date = "2013-12-22"
  s.email = ["mpapis@gmail.com"]
  s.extensions = ["ext/wrapper_generator/extconf.rb"]
  s.files = ["ext/wrapper_generator/extconf.rb"]
  s.homepage = "https://github.com/rvm/gem-wrappers"
  s.licenses = ["Apache 2.0"]
  s.rubygems_version = "2.2.0"
  s.summary = "Create gem wrappers for easy use of gems in cron and other system locations."

  s.installed_by_version = "2.2.0" if s.respond_to? :installed_by_version

  if s.respond_to? :specification_version then
    s.specification_version = 4

    if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
      s.add_development_dependency(%q<rake>, [">= 0"])
      s.add_development_dependency(%q<minitest>, [">= 0"])
    else
      s.add_dependency(%q<rake>, [">= 0"])
      s.add_dependency(%q<minitest>, [">= 0"])
    end
  else
    s.add_dependency(%q<rake>, [">= 0"])
    s.add_dependency(%q<minitest>, [">= 0"])
  end
end
