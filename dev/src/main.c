#include "main.h"

int main()
{
	unsigned char open_screen_type;

	//u16 *data = NULL;
	//unsigned char input;
	//Image image;

	//image = gfx_eddie_04;
	//if( NULL != image.palette )
	//{
	//	data = image.palette->data;
	//}

	//VDP_setPalette( PAL1, data );
	//VDP_drawImageEx( BG_A, &image, TILE_ATTR_FULL( PAL1, 0, 0, 0, 1 ), 0, 0, 0, CPU );

	open_screen_type = screen_type_splash;
	engine_screen_manager_init( open_screen_type );
	while( 1 )
	{
		engine_input_manager_update();
		engine_screen_manager_update();

		//input = engine_input_manager_hold_right();
		//if( input )
		//{
		//	VDP_drawImageEx( BG_A, &image, TILE_ATTR_FULL( PAL1, 0, 0, 0, 1 ), 0, 0, 0, CPU );
		//}

		VDP_waitVSync();
	}

	return 0;
}