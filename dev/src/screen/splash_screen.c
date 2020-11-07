#include "splash_screen.h"
#include "enum_manager.h"
#include "image_manager.h"
#include "input_manager.h"
#include "gfx.h"

void screen_splash_screen_load()
{
	engine_image_manager_draw( gfx_splash, PAL1, 0, 4, 2 );
}

void screen_splash_screen_update( unsigned char *screen_type )
{
	unsigned char input;
	input = engine_input_manager_hold_right();
	if( input )
	{
		*screen_type = screen_type_intro;
		return;
	}

	*screen_type = screen_type_splash;
}
