#include "main.h"

int main()
{
	//unsigned char input;

	u16 *data = NULL;
	if( NULL != gfx_banner.palette )
	{
		data = gfx_banner.palette->data;
	}

	VDP_setPalette( PAL1, data );
	VDP_drawImageEx( BG_A, &gfx_banner, TILE_ATTR_FULL( PAL1, 0, 0, 0, 1 ), 0, 0, 0, CPU );
	while( 1 )
	{
		//wait for screen refresh
		VDP_waitVSync();
	}

	return 0;
}