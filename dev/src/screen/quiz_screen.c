#include "quiz_screen.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "global_manager.h"
#include "input_manager.h"
#include "quiz_manager.h"

static unsigned char quiz;

void screen_quiz_screen_load()
{
	quiz = 0;
	engine_font_manager_data( ( quiz + 1 ), 30, 20 );
	engine_quiz_manager_draw( quiz );
	//engine_quiz_manager_draw_option();
	//engine_quiz_manager_draw_riffs();
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

	*screen_type = screen_type_quiz;
}