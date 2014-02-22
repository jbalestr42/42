# Simulate require_relative - it's required as the plugin can be called in wrong version or from bundler.
require File.expand_path('../gem-wrappers/specification.rb', __FILE__)

called_path, called_version = __FILE__.match(/^(.*\/gem-wrappers-([^\/]+)\/lib).*$/)[1..2]

# continue only if loaded and called versions all the same, and not shared gems disabled in bundler
if
  ( $:.include?(called_path) || GemWrappers::Specification.version == called_version ) and
  ( !defined?(Bundler) || ( defined?(Bundler) && Bundler::SharedHelpers.in_bundle? && !Bundler.settings[:disable_shared_gems]) )

  require 'gem-wrappers'
  require 'gem-wrappers/command'

  Gem.post_install do |installer|
    GemWrappers.install(installer.spec.executables)
  end

  Gem.post_uninstall do |installer|
    GemWrappers.uninstall(installer.spec.executables)
  end

  Gem::CommandManager.instance.register_command :wrappers
end
