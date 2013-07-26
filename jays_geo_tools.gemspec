# -*- encoding: utf-8 -*-
require File.expand_path('../lib/jays_geo_tools/version', __FILE__)

Gem::Specification.new do |gem|
  gem.authors       = ["JC"]
  gem.email         = ["jay@spruceboy.net"]
  gem.description   = %q{A handful of tools that are supposed to be helfull in processing of geospacial data.}
  gem.summary       = %q{fill this out}
  gem.homepage      = ""

  gem.files         = `git ls-files`.split($\)
  gem.extensions = ['ext/jays_geo_tools/extconf.rb']
  gem.executables   = gem.files.grep(%r{^bin/}).map{ |f| File.basename(f) } +  ["add_mask","masker","no_data_check","get_gcp","modis_natural_color_stretch","image_info","npp_natural_color_stretch"]
  gem.test_files    = gem.files.grep(%r{^(test|spec|features)/})
  gem.name          = "jays_geo_tools"
  gem.require_paths = ["lib"]
  gem.version       = JaysGeoTools::VERSION
end
