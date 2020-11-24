#include "image_manager.h"
#include "global_manager.h"
#include "image_object.h"
#include "gfx_tiles.h"

#ifdef _CONSOLE
#include "_genesis.h"
#else
#include <genesis.h>
#endif

static void draw_image( const Image image, unsigned char palette, unsigned short tiles, unsigned char x, unsigned char y )
{
	unsigned short *data = NULL;
	//const Image image = gfx_banner;

	if( NULL != image.palette )
	{
		data = image.palette->data;
	}

	VDP_setPalette( palette, data );
	VDP_drawImageEx( BG_A, &image, TILE_ATTR_FULL( palette, 0, 0, 0, tiles ), x, y, 0, CPU );
}

void engine_image_manager_draw_splash()
{
	//unsigned short *data = NULL;
	//const Image image = gfx_splash;

	//if( NULL != image.palette )
	//{
	//	data = image.palette->data;
	//}

	//VDP_setPalette( PAL1, data );
	//VDP_drawImageEx( BG_A, &image, TILE_ATTR_FULL( PAL1, 0, 0, 0, PALETTE1_TILES ), 0, 0, 0, CPU );

	draw_image( gfx_splash, PAL1, PALETTE1_TILES, 4, 2 );
}

void engine_image_manager_draw_banner()
{
	unsigned short *data = NULL;
	const Image image = gfx_banner;

	if( NULL != image.palette )
	{
		data = image.palette->data;
	}

	VDP_setPalette( PAL1, data );
	VDP_drawImageEx( BG_A, &image, TILE_ATTR_FULL( PAL1, 0, 0, 0, PALETTE1_TILES ), 0, 0, 0, CPU );
}

void engine_image_manager_draw_eddie( unsigned char index, unsigned char x, unsigned char y )
{
	unsigned short *data = NULL;
	const Image image = *image_eddie[ index ];

	if( NULL != image.palette )
	{
		data = image.palette->data;
	}

	VDP_setPalette( PAL2, data );
	VDP_drawImageEx( BG_A, &image, TILE_ATTR_FULL( PAL2, 0, 0, 0, PALETTE2_TILES ), x, y, 0, CPU );
}