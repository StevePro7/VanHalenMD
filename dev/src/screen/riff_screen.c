#include "riff_screen.h"
#include "audio_manager.h"
#include "cursor_manager.h"
#include "eddie_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "game_manager.h"
#include "hack_manager.h"
#include "global_manager.h"
#include "graphics_manager.h"
#include "image_manager.h"
#include "input_manager.h"
#include "locale_manager.h"
#include "quiz_manager.h"
#include "sprite_manager.h"
#include "text_manager.h"
#include "timer_manager.h"

#define RIFF_SCREEN_DELAY		100
#define RIFF_SCREEN_PAUSE		20

static unsigned char stage;

void screen_riff_screen_load()
{
	struct_game_object *go = &global_game_object;
	struct_hack_object *ho = &global_hack_object;
	unsigned char eddie_image;
	//engine_font_manager_text( "RIFF SCREEN!!", 10, 2 );

	// TODO delete
	if( ho->hack_navigation )
	{
		engine_image_manager_draw_banner();
		engine_font_manager_text( LOCALE_BANNER_TITLE, 5, BANNER_Y );
		eddie_image = engine_eddie_manager_next();
		engine_image_manager_draw_eddie( eddie_image, 20, 6 );
	}
	// TODO delete

	engine_graphics_manager_clear_half();

	//engine_graphics_manager_clear_area();

	engine_text_manager_draw_lines( 0, 2 );
	engine_cursor_manager_load_small( MAX_OPTION, go->riff_selections, OPTION_X, riff_yPos, riff_line1, riff_line2 );
	engine_cursor_manager_draw();

	stage = event_stage_start;
}

void screen_riff_screen_update( unsigned char *screen_type )
{
	struct_cursor_object *co = &global_cursor_object;
	unsigned char delay;
	unsigned char input;
	//unsigned char input2;		// TODO delete

	engine_sprite_manager_update();
	if( event_stage_menus == stage )
	{
		delay = engine_delay_manager_update();
		if( delay )
		{
			*screen_type = screen_type_diff;
		}

		return;
	}

	if( event_stage_pause == stage )
	{
		delay = engine_delay_manager_update();
		if( delay )
		{
			engine_cursor_manager_hide();
			engine_delay_manager_load( RIFF_SCREEN_PAUSE );
			stage = event_stage_menus;
		}

		return;
	}

	input = engine_input_manager_hold_buttonA();
	//input2 = engine_input_manager_hold_right();		// TODO delete
	if( input )// || input2 )
	{
		engine_audio_manager_play_effect( effects_type_right );

		engine_game_manager_set_riff_select( co->selects );
		engine_quiz_manager_set_riffs_play( co->selects );
		engine_cursor_manager_action( sprite_type_right );

		engine_delay_manager_load( RIFF_SCREEN_DELAY );
		stage = event_stage_pause;
		return;
	}

	input = engine_input_manager_hold_up();
	if( input )
	{
		engine_cursor_manager_move_up();
	}
	input = engine_input_manager_hold_down();
	if( input )
	{
		engine_cursor_manager_move_down();
	}

	engine_sprite_manager_update();
	*screen_type = screen_type_riff;
}