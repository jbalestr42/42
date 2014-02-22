# Fake building extension
File.open('Makefile', 'w') { |f| f.write("all:\n\ninstall:\n\n") }
File.open('make', 'w') do |f|
  f.write('#!/bin/sh')
  f.chmod(f.stat.mode | 0111)
end
File.open('wrapper_generator.so', 'w') {}
File.open('wrapper_generator.dll', 'w') {}
File.open('nmake.bat', 'w') { |f| }

# add the gem to load path
$: << File.expand_path("../../../lib", __FILE__)

# load the command
require 'rubygems'
require 'gem-wrappers/command'

# call the actions
command = WrappersCommand.new
command.options[:args] = ['regenerate']
command.execute

# unload the path, what was required stays ... but there is that much we can do
$:.pop

# just in case - it worked
true
