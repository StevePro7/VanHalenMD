#include "main.h"

int main()
{
	u16 *data = NULL;
	if( NULL != gfx_eddie_16.palette )
	{
		data = gfx_eddie_16.palette->data;
	}

	VDP_setPalette( PAL1, data );
	VDP_drawImageEx( BG_A, &gfx_eddie_16, TILE_ATTR_FULL( PAL1, 0, 0, 0, 1 ), 0, 0, 0, CPU );
	while( 1 )
	{
		//wait for screen refresh
		VDP_waitVSync();
	}

	return 0;
}