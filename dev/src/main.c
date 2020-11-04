#include "main.h"

#define SFX_DEAD            250

int main()
{
	//unsigned char input;

	u16 *data = NULL;
	if( NULL != gfx_splash.palette )
	{
		data = gfx_splash.palette->data;
	}

	VDP_setPalette( PAL1, data );
	VDP_drawImageEx( BG_A, &gfx_splash, TILE_ATTR_FULL( PAL1, 0, 0, 0, 1 ), 4, 2, 0, CPU );
	while( 1 )
	{
		//wait for screen refresh
		VDP_waitVSync();
	}

	return 0;
}