#include "play_screen.h"
#include "cursor_manager.h"
#include "debug_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "global_manager.h"
#include "graphics_manager.h"
#include "input_manager.h"
#include "quiz_manager.h"
#include "score_manager.h"
#include "sprite_manager.h"

void screen_play_screen_load()
{
	struct_quiz_object *qo = &global_quiz_object;
	engine_font_manager_text( "PLAY SCREEN", 10, 2 );
	engine_graphics_manager_clear_half();

	// TODO try to get the score percent working from SRAM.
	engine_score_manager_draw_percent( quiz_saving[qo->quiz_riff_index] );
	// TODO try to get the score percent working from SRAM.

	// TODO add hack manager to check if cheat enabled
	engine_debug_manager_cheat( quiz_select[ qo->quiz_riff_index ] );
	//engine_quiz_manager_cheat();
	// TODO add hack manager to check if cheat enabled

	engine_cursor_manager_load_large( MAX_OPTION, qo->quiz_selections, OPTION_X, quiz_yPos, quiz_years, quiz_line1, quiz_line2, quiz_line3, quiz_line4 );
	engine_cursor_manager_draw();
}

void screen_play_screen_update( unsigned char *screen_type )
{
	struct_cursor_object *co = &global_cursor_object;
	struct_quiz_object *qo = &global_quiz_object;

	unsigned char input;
	unsigned char input2;		// TODO delete
	unsigned char correct;
	unsigned char riff_index;
	unsigned char save_index;
	unsigned char answer;

	engine_sprite_manager_update();

	input = engine_input_manager_hold_buttonA();
	input2 = engine_input_manager_hold_right();		// TODO delete
	if( input || input2 )
	{
		riff_index = qo->quiz_riff_index;
		save_index = quiz_saving[ riff_index ];
		correct = quiz_select[ riff_index ];
		answer = co->selects == correct ? sprite_type_right : sprite_type_wrong;

		engine_score_manager_update( save_index, answer );
		engine_cursor_manager_action( answer );
		engine_debug_manager_answer( answer );

		*screen_type = screen_type_quiz;
		return;
	}

	input = engine_input_manager_hold_buttonB();
	input2 = engine_input_manager_hold_left();		// TODO delete
	if( input || input2 )
	{
		*screen_type = screen_type_score;
		return;
	}

	// TODO replay riff.
	input = engine_input_manager_hold_buttonC();
	if( input )
	{
	}
	// TODO replay riff.

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
	*screen_type = screen_type_play;
}