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
	engine_image_manager_draw( gfx_eddie_05, PAL2, PALETTE2_TILES, 20, 6 );

	engine_sprite_manager_draw( sprite_type_actor );
}

void screen_intro_screen_update( unsigned char *screen_type )
{
	unsigned char input;
	input = engine_input_manager_hold_buttonA();
	if( input )
	{
		engine_sprite_manager_draw( sprite_type_actor );
	}

	input = engine_input_manager_hold_up();
	if( input )
	{
		engine_sprite_manager_move_up();
	}
	input = engine_input_manager_hold_down();
	if( input )
	{
		engine_sprite_manager_move_down();
	}

	input = engine_input_manager_hold_left();
	if( input )
	{
		engine_font_manager_text( "1234123412341234", 4, 15 );
		engine_sprite_manager_draw( sprite_type_right );
	}
	input = engine_input_manager_hold_right();
	if( input )
	{
		engine_font_manager_text( "BLAH!!", 3, 15 );
		engine_sprite_manager_draw( sprite_type_wrong );
	}

	//input = engine_input_manager_hold_right();
	//if( input )
	//{
	//	engine_font_manager_text( "BLAH!!", 2, 15 );
	//	engine_sprite_manager_draw( sprite_type_right );
	//}

	//input = engine_input_manager_hold_down();
	//if( input )
	//{
	//	engine_font_manager_text( "DOWN!!", 2, 15 );
	//	engine_sprite_manager_draw( sprite_type_wrong );
	//}

	engine_sprite_manager_update();
	*screen_type = screen_type_intro;
}
