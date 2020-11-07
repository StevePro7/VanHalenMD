#include "test_screen.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "global_manager.h"
#include "input_manager.h"
#include "quiz_manager.h"

static unsigned char quiz;

void screen_test_screen_load()
{
	unsigned char diffulty = difficulty_type_easy;
	//unsigned char diffulty = difficulty_type_hard;

	engine_quiz_manager_load_normal( diffulty );
	//engine_quiz_manager_load_mixing( diffulty );
	//engine_quiz_manager_load_random( diffulty );

	quiz = 0;

	engine_quiz_manager_draw( quiz );
	engine_quiz_manager_debug_stats( quiz );		// TODO delete!!

	//engine_quiz_manager_debug_option( 0 );
	//engine_quiz_manager_debug_riffs();
}

void screen_test_screen_update( unsigned char *screen_type )
{
	unsigned char input = engine_input_manager_hold_right();
	if( input )
	{
		quiz++;
		if( quiz >= MAX_RIFFS )
		{
			quiz = 0;
		}

		engine_font_manager_data( ( quiz + 1 ), 30, 20 ); // TODO delete!!
		engine_quiz_manager_draw( quiz );
		engine_quiz_manager_debug_stats( quiz );		// TODO delete!!
	}

	*screen_type = screen_type_test;
}