class WrappersCommand
  class FileExist
    def self.===(file)
      File.exist?(file)
    end
  end
end
