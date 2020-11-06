#include "intro_screen.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "global_manager.h"
#include "image_manager.h"
#include "input_manager.h"
#include "sprite_manager.h"
#include "gfx.h"

void screen_intro_screen_load()
{
	engine_image_manager_draw( gfx_banner, PAL1, PALETTE1_TILES, 0, 0 );
	engine_image_manager_draw( gfx_eddie_17, PAL2, PALETTE2_TILES, 20, 6 );
}

void screen_intro_screen_update( unsigned char *screen_type )
{
	unsigned char input;
	input = engine_input_manager_hold_left();
	if( input )
	{
		engine_font_manager_text( "TEST!!", 2, 15 );
		engine_sprite_manager_test0();
	}

	input = engine_input_manager_hold_right();
	if( input )
	{
		engine_font_manager_text( "BLAH!!", 2, 15 );
		engine_sprite_manager_test1();
	}

	engine_sprite_manager_update();
	*screen_type = screen_type_intro;
}
