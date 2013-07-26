#include "gdal.h"
#include "cpl_string.h"
#include "cpl_conv.h"

/************************************************************/
/* Simple test for no data pixels pixels.. */
/* Use like:            */
/* ./saturate <infile> <outfile> */
/* <infile> .*/
/* questions or comments? jc@alaska.edu     */
/* complile like:  gcc $(gdal-config --cflags) -o  image_info image_info.c $(gdal-config --libs) */
/************************************************************/




/* Opens a gdal dataset..*/

GDALDatasetH GDAL_open_read(char *file_name)
{
    GDALDatasetH  gdalDataset;
    gdalDataset = GDALOpen( file_name, GA_ReadOnly );
    if( gdalDataset == NULL )
    {
        printf("Hmm, could not open '%s' for reading.. this be an error, exiting..\n", file_name);
        exit(-1);
    }
}

void ussage(char *progname)
{
    fprintf(stderr, "Whooowww.. I don't work like that..");
    fprintf(stderr, "use me like:\n");
    fprintf(stderr, "%s <infile> <outfile>\n", progname);
    fprintf(stderr, "\tinfile can be any image that gdal reads\n");
    fprintf(stderr, "WARNING: This util expects nodata values of 0 - this should be fixed ASAP.\n");
    fprintf(stderr, "Problems? Questions? Complain to jay@alaska.edu so he can ignore them..\n\nBy now.\n(I realize the command line parsing on this tools sucks - improvements comming)\n");
    exit(-1);
}

int do_gdal_startup() {

}


int main( int argc, const char* argv[] )
{
    GDALDriverH   hDriver;
    GDALDatasetH  in_Dataset;
    GDALRasterBandH in_band;
    unsigned char   *data_scan_line;
    int             nBlockXSize, nBlockYSize;
    int             bGotMin, bGotMax;
    int             bands;
    int             xsize;
    double          adfMinMax[2];
    int             valid_data_pixels[10];
    int             saturated_data_pixels[10];
    int             y_index, x;
    GDALRasterBandH  out_band;
    
    
    if ( argc != 2 ) {
        ussage(argv[0]);
    }

    
    GDALAllRegister();
    
    /* Set cache to something reasonable.. - 1/2 gig*/
    CPLSetConfigOption( "GDAL_CACHEMAX", "512" );

    /* open datasets..*/
    in_Dataset = GDAL_open_read( argv[1]);
    
    /* Loop though bands, checking for saturated pixels .... */
    xsize = GDALGetRasterXSize( in_Dataset );
    data_scan_line = (char *) CPLMalloc(sizeof(char)*xsize);
    
    /* The output band... */
    out_band =  GDALGetRasterBand( out_Dataset, 1);

   
    /* wipe counters.. */ 
    for (bands=1; bands <= GDALGetRasterCount( in_Dataset ); bands ++ ) {
        valid_data_pixels[bands] = 0;
        saturated_data_pixels[bands] = 0;
    }
    
    /* loop though the lines of the data, looking for no data and saturated pixels..*/
    for (y_index = 0; y_index <GDALGetRasterYSize( in_Dataset ); y_index ++ ) {
        for (bands=1; bands <= GDALGetRasterCount( in_Dataset ); bands ++ ) {
            GDALRasterBandH data_band;
            /* Read data..*/
            data_band =  GDALGetRasterBand( in_Dataset, bands);
            GDALRasterIO( data_band, GF_Read, 0, y_index, xsize , 1, data_scan_line, xsize , 1, GDT_Byte, 0, 0 );
            /* If first band, then copy into output slice.. */
            if (bands==1) {
                unsigned char  data_value;
                for(x=0; x < xsize; x++) {
                    /*shift to make darker...*/
                   out_scan_line[x] = data_scan_line[x] >> 1 ;
                   if ( out_scan_line[x] ==0 && data_scan_line[x] != 0) {out_scan_line[x] = 1;}
                }
            }
            
            /* Loop though, looking for saturated pixels and no-data values.. */
            for(x=0; x < xsize; x++) {
                if (  data_scan_line[x] == 0 )  {
                    out_scan_line[x] = 255;
                }
            }
        }
        GDALRasterIO( out_band, GF_Write, 0, y_index, xsize , 1, out_scan_line, xsize , 1, GDT_Byte, 0, 0 );
    }
    
    GDALClose(out_Dataset);
}
