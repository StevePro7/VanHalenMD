#include "func_screen.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "global_manager.h"
#include "input_manager.h"
#include "locale_manager.h"

void screen_func_screen_load()
{
	//engine_font_manager_text( "FUNC SCREEN", 10, 2 );
	engine_font_manager_text( LOCALE_BLANK_SIZE30, 5, BANNER_Y );

	//engine_font_manager_text( "Riff 01/05  Score 00    OK   0%", 5, 4 );

	//engine_quiz_manager_load_testing();
	//engine_quiz_manager_load_normal();
	//engine_quiz_manager_load_mixing();
	//engine_quiz_manager_load_random();
}

void screen_func_screen_update( unsigned char *screen_type )
{
	unsigned char input;
	unsigned char input2;
	input = engine_input_manager_hold_buttonA();
	input2 = engine_input_manager_hold_buttonStart();
	if( input || input2 )
	{
		//TODO testing
		//engine_quiz_manager_set_riffs_play( 0 );
		//engine_quiz_manager_set_difficulty( difficulty_type_hard );
		//TODO testing

		//*screen_type = screen_type_load;
		*screen_type = screen_type_title;
		return;
	}

	//*screen_type = screen_type_init;
	//*screen_type = screen_type_begin;
	*screen_type = screen_type_func;
}
