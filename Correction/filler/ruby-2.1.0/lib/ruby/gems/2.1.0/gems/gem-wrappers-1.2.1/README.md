# Gem wrappers

[![Gem Version](https://badge.fury.io/rb/gem-wrappers.png)](http://rubygems.org/gems/gem-wrappers)
[![Code Climate](https://codeclimate.com/github/rvm/gem-wrappers.png)](https://codeclimate.com/github/rvm/gem-wrappers)
[![Coverage Status](https://coveralls.io/repos/rvm/gem-wrappers/badge.png?branch=master)](https://coveralls.io/r/rvm/gem-wrappers?branch=master)
[![Build Status](https://travis-ci.org/rvm/gem-wrappers.png?branch=master)](https://travis-ci.org/rvm/gem-wrappers)
[![Dependency Status](https://gemnasium.com/rvm/gem-wrappers.png)](https://gemnasium.com/rvm/gem-wrappers)
[![Documentation](http://b.repl.ca/v1/yard-docs-blue.png)](http://rubydoc.info/gems/gem-wrappers/frames)

Create gem wrappers for easy use of gems in cron and other system locations.

## Configuration / Defaults

In `~/.gemrc` you can overwrite this defaults:

```ruby
wrappers_path: GEM_HOME/wrappers
wrappers_environment_file: GEM_HOME/environment
wrappers_path_take: 1
```

It is not yet possible to put variables in the configuration,
only relative and full paths will work, open a ticket if you need variables.

## Generating wrappers

By default wrappers are installed when a gem is installed,
to rerun the process for all gems in `GEM_HOME` use:

```bash
gem wrappers regenerate
```

wrappers will be generated in `$GEM_HOME/wrappers/`.

## Generating scripts wrappers

It is possible to generate wrappers for custom scripts:

```bash
gem wrappers /path/to/script
```

a wrapper `$GEM_HOME/wrappers/script` will be generated.

## Showing current configuration

To see paths that are used by gem run:

```bash
gem wrappers
```

## Environment file

User can provide his own `environment` file,
in case it is not available during generating wrappers it will be created using this template:

```erb
export PATH="<%= path.join(":") %>:$PATH"
export GEM_PATH="<%= gem_path.join(":") %>"
export GEM_HOME="<%= gem_home %>"
```

The path elements are calculated using this algorithm:

```ruby
ENV['PATH'].split(":").take(Gem.path.size + path_take)
```
