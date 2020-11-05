#include "main.h"

int main()
{
	u16 *data = NULL;
	Image image;

	image = gfx_eddie_09;
	if( NULL != image.palette )
	{
		data = image.palette->data;
	}

	VDP_setPalette( PAL1, data );
	VDP_drawImageEx( BG_A, &image, TILE_ATTR_FULL( PAL1, 0, 0, 0, 1 ), 0, 0, 0, CPU );
	while( 1 )
	{
		//wait for screen refresh
		VDP_waitVSync();
	}

	return 0;
}