require 'erb'

module GemWrappers
  class Environment

    def self.file_name
      path = Gem.configuration && Gem.configuration[:wrappers_environment_file]
      if path.nil? || path == ""
        path = File.join(Gem.dir, 'environment')
      end
      path
    end

    def file_name
      @file_name ||= self.class.file_name
    end

    def path_take
      return @path_take if @path_take
      @path_take = Gem.configuration && Gem.configuration[:wrappers_path_take] || 1
      @path_take += gem_path.size
    end

    def ensure
      return if File.exist?(file_name)
      FileUtils.mkdir_p(File.dirname(file_name)) unless File.exist?(File.dirname(file_name))
      content = ERB.new(template).result(binding)
      File.open(file_name, 'w') do |file|
        file.write(content)
      end
      File.chmod(0644, file_name)
    end

    def template
      @template ||= <<-TEMPLATE
export PATH="<%= path.join(":") %>:$PATH"
export GEM_PATH="<%= gem_path.join(":") %>"
export GEM_HOME="<%= gem_home %>"
TEMPLATE
    end

    def gem_path
      @gem_path ||= Gem.path
    end

    def gem_home
      @gem_home ||= Gem.dir
    end

    def path(base = ENV['PATH'])
      @path ||= base.split(":").take(path_take)
    end

  end
end
