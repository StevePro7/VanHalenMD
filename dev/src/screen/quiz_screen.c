#include "quiz_screen.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "global_manager.h"
#include "image_manager.h"
#include "input_manager.h"
#include "quiz_manager.h"
#include "sprite_manager.h"
#include "gfx.h"

static unsigned char quiz;

void screen_quiz_screen_load()
{
	// Clear screen.
	VDP_clearPlane( BG_A, 0 );

	//engine_image_manager_draw( gfx_banner, PAL1, PALETTE1_TILES, 0, 0 );
	//engine_image_manager_draw( gfx_eddie_05, PAL2, PALETTE2_TILES, 20, 6 );

	quiz = 0;
	//engine_quiz_manager_load();
	//engine_quiz_manager_load_normal();
	engine_quiz_manager_load_mixing( difficulty_type_easy );

	engine_font_manager_data( ( quiz + 1 ), 30, 20 );
	engine_quiz_manager_draw( quiz );
	//engine_quiz_manager_draw_option();
	//engine_quiz_manager_draw_riffs();

	engine_sprite_manager_draw( sprite_type_actor );
}

void screen_quiz_screen_update( unsigned char *screen_type )
{
	unsigned char input = engine_input_manager_hold_right();
	if( input )
	{
		quiz++;
		if( quiz >= MAX_RIFFS )
		{
			quiz = 0;
		}

		engine_font_manager_data( ( quiz + 1 ), 30, 20 );
		engine_quiz_manager_draw( quiz );
	}

	engine_sprite_manager_update();
	*screen_type = screen_type_quiz;
}