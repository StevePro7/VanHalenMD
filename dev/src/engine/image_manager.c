#include "image_manager.h"
#include "image_object.h"
#include "gfx.h"

void engine_image_manager_eddie( const unsigned char index )
{
	const Image image = *image_eddies[ index ];
	engine_image_manager_draw( image, PAL2, PALETTE2_TILES, 20, 6 );
}

void engine_image_manager_draw( Image image, unsigned char palette, unsigned char tiles, unsigned char x, unsigned char y )
{
	unsigned short *data = NULL;
	if( NULL != image.palette )
	{
		data = image.palette->data;
	}

	VDP_setPalette( palette, data );
	VDP_drawImageEx( BG_A, &image, TILE_ATTR_FULL( palette, 0, 0, 0, tiles ), x, y, 0, CPU );
}