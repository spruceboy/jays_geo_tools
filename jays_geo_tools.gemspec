# -*- encoding: utf-8 -*-
require File.expand_path('../lib/jays_geo_tools/version', __FILE__)

Gem::Specification.new do |gem|
  gem.authors       = ["JC"]
  gem.email         = ["jay@spruceboy.net"]
  gem.description   = %q{TODO: Write a gem description}
  gem.summary       = %q{TODO: Write a gem summary}
  gem.homepage      = ""

  gem.files         = `git ls-files`.split($\)
  gem.extensions = ['ext/jays_geo_tools/extconf.rb']
  gem.executables   = gem.files.grep(%r{^bin/}).map{ |f| File.basename(f) } +  ["add_mask","masker","no_data_check","get_gcp","modis_natural_color_stretch","image_info","npp_natural_color_stretch"]
  gem.test_files    = gem.files.grep(%r{^(test|spec|features)/})
  gem.name          = "jays_geo_tools"
  gem.require_paths = ["lib"]
  gem.version       = JaysGeoTools::VERSION
end
