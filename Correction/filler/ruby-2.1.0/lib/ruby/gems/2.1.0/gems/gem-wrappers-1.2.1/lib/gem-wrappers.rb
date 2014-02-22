require 'gem-wrappers/environment'
require 'gem-wrappers/installer'

module GemWrappers

  def self.install(executables)
    environment = GemWrappers::Environment.new
    environment.ensure
    installer = GemWrappers::Installer.new(environment.file_name)
    installer.ensure

    # gem executables
    executables.each do |executable|
      installer.install(executable)
    end

    # ruby executables
    %w{ruby gem erb irb ri rdoc testrb}.each do |executable|
      installer.install(executable)
    end
  end

  def self.uninstall(executables)
    installer = GemWrappers::Installer.new

    # gem executables
    executables.each do |executable|
      installer.uninstall(executable)
    end
  end

  def self.wrappers_path
    GemWrappers::Installer.wrappers_path
  end

  def self.environment_file
    GemWrappers::Environment.file_name
  end

end
