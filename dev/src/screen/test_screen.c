#include "test_screen.h"
#include "enum_manager.h"
#include "quiz_manager.h"

void screen_test_screen_load()
{
	unsigned char diffulty = difficulty_type_easy;

	//engine_quiz_manager_load_normal( diffulty );
	//engine_quiz_manager_load_mixing( diffulty );
	engine_quiz_manager_load_random( diffulty );

	//engine_quiz_manager_draw2();

	engine_quiz_manager_debug_option( 0 );
	//engine_quiz_manager_debug_riffs();
}

void screen_test_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_test;
}