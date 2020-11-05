#include "image_manager.h"
#include "gfx.h"

void engine_image_manager_draw( Image image, unsigned char palette, unsigned char index, unsigned char x, unsigned char y )
{
	unsigned short *data = NULL;
	if( NULL != image.palette )
	{
		data = image.palette->data;
	}

	VDP_setPalette( palette, data );
	VDP_drawImageEx( BG_A, &image, TILE_ATTR_FULL( palette, 0, 0, 0, index ), x, y, 0, CPU );
}