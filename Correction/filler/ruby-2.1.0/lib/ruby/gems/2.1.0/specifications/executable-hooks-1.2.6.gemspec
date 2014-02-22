# -*- encoding: utf-8 -*-
# stub: executable-hooks 1.2.6 ruby lib
# stub: ext/wrapper_installer/extconf.rb

Gem::Specification.new do |s|
  s.name = "executable-hooks"
  s.version = "1.2.6"

  s.required_rubygems_version = Gem::Requirement.new(">= 0") if s.respond_to? :required_rubygems_version=
  s.require_paths = ["lib"]
  s.authors = ["Michal Papis"]
  s.date = "2013-10-21"
  s.email = ["mpapis@gmail.com"]
  s.executables = ["executable-hooks-uninstaller"]
  s.extensions = ["ext/wrapper_installer/extconf.rb"]
  s.files = ["bin/executable-hooks-uninstaller", "ext/wrapper_installer/extconf.rb"]
  s.homepage = "https://github.com/mpapis/executable-hooks"
  s.licenses = ["Apache 2.0"]
  s.post_install_message = "# In case of problems run the following command to update binstubs:\ngem regenerate_binstubs\n"
  s.rubygems_version = "2.2.0"
  s.summary = "Hook into rubygems executables allowing extra actions to be taken before executable is run."

  s.installed_by_version = "2.2.0" if s.respond_to? :installed_by_version

  if s.respond_to? :specification_version then
    s.specification_version = 4

    if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
      s.add_development_dependency(%q<tf>, [">= 0"])
    else
      s.add_dependency(%q<tf>, [">= 0"])
    end
  else
    s.add_dependency(%q<tf>, [">= 0"])
  end
end
