#include "main.h"

int main()
{
	u16 *data = NULL;
	unsigned char input;
	Image image;

	image = gfx_eddie_17;
	if( NULL != image.palette )
	{
		data = image.palette->data;
	}

	VDP_setPalette( PAL1, data );
	//VDP_drawImageEx( BG_A, &image, TILE_ATTR_FULL( PAL1, 0, 0, 0, 1 ), 0, 0, 0, CPU );
	while( 1 )
	{
		engine_input_manager_update();
		input = engine_input_manager_hold_right();
		if( input )
		{
			VDP_drawImageEx( BG_A, &image, TILE_ATTR_FULL( PAL1, 0, 0, 0, 1 ), 0, 0, 0, CPU );
		}

		VDP_waitVSync();
	}

	return 0;
}