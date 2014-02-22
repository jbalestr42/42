# Bundler Unload

Allow unloading `bundler` after `Bundler.load`.

## Installation

    gem install bundler-unload

## Example 1

    require 'bundler-unload'
    Bundler.with_bundle do |bundler|
      bundler.spec.do_the_magic
    end

## Example 2

    require 'bundler-unload'
    rubygems_spec = Bundler.rubygems.plain_specs
    begin
      Bundler.load.spec.do_the_magic
    ensure
      Bundler.unload!(rubygems_spec)
    end

## Authors

 - Michal Papis <mpapis@gmail.com>

## Thanks

 - Joshua Hull
 - Carl Lerche
