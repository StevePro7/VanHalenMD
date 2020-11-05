#include "image_manager.h"
#include "gfx.h"

//void engine_image_manager_test()
//{
//	unsigned short *data = NULL;
//	//Image image = gfx_splash;
//
//	if( NULL != gfx_splash.palette )
//	{
//		data = gfx_splash.palette->data;
//	}
//
//	VDP_setPalette( PAL1, data );
//	VDP_drawImageEx( BG_A, &gfx_splash, TILE_ATTR_FULL( PAL1, 0, 0, 0, 1 ), 4, 2, 0, CPU );
//}

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

void engine_image_manager_draw2( Image image, unsigned char palette, unsigned char index, unsigned char x, unsigned char y )
{
	unsigned short *data = NULL;
	if( NULL != image.palette )
	{
		data = image.palette->data;
	}

	VDP_setPalette( palette, data );
	VDP_drawImageEx( BG_A, &image, TILE_ATTR_FULL( palette, 0, 0, 0, 240 ), x, y, 0, CPU );
}