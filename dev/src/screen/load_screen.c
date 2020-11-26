#include "load_screen.h"
#include "banner_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "locale_manager.h"
#include "quiz_manager.h"
#include "score_manager.h"
#include "sprite_manager.h"

void screen_load_screen_load()
{
	//engine_font_manager_text( "LOAD SCREEN", 10, 2 );

	//TODO testing
	engine_quiz_manager_set_riffs_play( 3 );
	engine_quiz_manager_set_difficulty( difficulty_type_easy );
	//TODO testing

	// Reset variables.
	engine_font_manager_text( LOCALE_BLANK_SIZE30, 5, BANNER_Y );
	//engine_font_manager_text( LOCALE_BLANK_SIZE30, 5, BANNER_Y + 1);

	engine_banner_manager_stats();
	engine_score_manager_reset();
	engine_quiz_manager_reset();

	engine_score_manager_draw();
	engine_quiz_manager_draw();

	// Load quiz questions.
	//engine_quiz_manager_load_normal();
	//engine_quiz_manager_load_mixing();
	engine_quiz_manager_load_random();
}

void screen_load_screen_update( unsigned char *screen_type )
{
	engine_sprite_manager_update();

	//*screen_type = screen_type_load;
	//*screen_type = screen_type_play;
	*screen_type = screen_type_part;
}