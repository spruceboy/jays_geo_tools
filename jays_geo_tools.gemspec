# -*- encoding: utf-8 -*-
require File.expand_path('../lib/jays_geo_tools/version', __FILE__)

Gem::Specification.new do |gem|
  gem.authors       = ["JC"]
  gem.email         = ["jay@spruceboy.net"]
  gem.description   = %q{A handful of tools that are supposed to be helfull in processing of geospacial data.}
  gem.summary       = %q{fill this out}
  gem.homepage      = ""

  #gem.files         = `git ls-files`.split($\)
  gem.files =  [".gitignore", "Gemfile", "LICENSE", "README.md", "Rakefile", "bin/add_mask", "bin/add_overviews", "bin/copy_geo_info", "bin/do_several_at_once", "bin/get_gcp", "bin/image_info", "bin/mapserver_layer_maker", "bin/masker", "bin/modis_natural_color_stretch", "bin/no_data_check", "bin/npp_natural_color_stretch", "bin/reformat", "bin/rgb_to_jpeg_tif", "bin/tile_image", "bin/to_jpeg_tif", "bin/warp_with_mask", "examples/sample_handler_for_do_several_at_once.rb", "ext/jays_geo_tools/add_mask.c", "ext/jays_geo_tools/Rakefile", "ext/jays_geo_tools/get_gcp.c", "ext/jays_geo_tools/image_info.c", "ext/jays_geo_tools/image_info.cpp", "ext/jays_geo_tools/masker.c", "ext/jays_geo_tools/modis_filter.c", "ext/jays_geo_tools/modis_natural_color_stretch.c", "ext/jays_geo_tools/no_data_check.c", "ext/jays_geo_tools/npp_natural_color_stretch.c", "jays_geo_tools.gemspec", "lib/jays_geo_tools.rb", "lib/jays_geo_tools/version.rb", "test/test_jays_geo_tools.rb"]
  gem.extensions = ['ext/jays_geo_tools/Rakefile']
  gem.executables   = gem.files.grep(%r{^bin/}).map{ |f| File.basename(f) } 
  gem.test_files    = gem.files.grep(%r{^(test|spec|features)/})
  gem.name          = "jays_geo_tools"
  gem.require_paths = ["lib"]
  gem.version       = JaysGeoTools::VERSION
end
