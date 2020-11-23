#include "image_manager.h"
#include "image_object.h"

#ifdef _CONSOLE
#include "_genesis.h"
#else
#include <genesis.h>
#endif

void engine_image_manager_draw_eddie( unsigned char index, unsigned char x, unsigned char y )
{
	unsigned short *data = NULL;
	const Image image = *image_eddie[ index ];

	if( NULL != image.palette )
	{
		data = image.palette->data;
	}

	VDP_setPalette( PAL2, data );
	VDP_drawImageEx( BG_A, &image, TILE_ATTR_FULL( PAL2, 0, 0, 0, 240 ), x, y, 0, CPU );
}