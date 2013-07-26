#!/usr/bin/env rake
require "bundler/gem_tasks"



  task :compile => [:clean, :check_gdal, :build_cc_stuff]

  task :clean do
	["add_mask","masker","no_data_check","get_gcp","modis_natural_color_stretch","image_info","npp_natural_color_stretch"].each do |x|
		system("rm -v bin/#{x}") if (File.exists?("bin/"+x))
	end
  end

  task :check_gdal do
    gdal = `which gdal-config`
    raise ("Gdal not found - are you sure your enviroment is setup properly?") if (gdal=="")
    gdal_version =  `gdal-config --version`
    raise ("Your gdal version is pretty old (#{gdal_version}) - get a new one") if (gdal_version<"1.8.0")
  end

  task :build_cc_stuff => [:add_mask, :masker,:no_data_check, :get_gcp, :modis_natural_color_stretch, :image_info, :npp_natural_color_stretch]

  task :add_mask do
    puts("Building \"add_mask\"")
    system("gcc $(gdal-config --cflags) -o ./bin/add_mask ext/jays_geo_tools/add_mask.c $(gdal-config --libs)")
  end

  task :masker do
    puts("Building \"masker\"")
    system("gcc $(gdal-config --cflags) -o ./bin/masker ext/jays_geo_tools/masker.c $(gdal-config --libs)")
  end

  task :no_data_check do
    puts("Building \"no_data_check\"")
    system("gcc $(gdal-config --cflags) -o  ./bin/no_data_check ext/jays_geo_tools/no_data_check.c $(gdal-config --libs)")
  end

  task :get_gcp do
    puts("Building \"get cgp\"")
    system("gcc -g $(gdal-config --cflags) -o ./bin/get_gcp ext/jays_geo_tools/get_gcp.c $(gdal-config --libs)")
  end

  task :modis_natural_color_stretch do
    puts("Building \":modis_natural_color_stretch\"")
    system("gcc $(gdal-config --cflags) -o ./bin/modis_natural_color_stretch ext/jays_geo_tools/modis_natural_color_stretch.c $(gdal-config --libs)")
  end

  task :image_info  do
    puts("Building image_info..")
    system("g++ -Wno-conversion-null  $(gdal-config --cflags) -o ./bin/image_info ext/jays_geo_tools/image_info.cpp $(gdal-config --libs)")
  end

  task :npp_natural_color_stretch do
    system(" gcc -O3  $(gdal-config --cflags) -o ./bin/npp_natural_color_stretch ext/jays_geo_tools/npp_natural_color_stretch.c $(gdal-config --libs)")
  end



task :test do
	true
end
