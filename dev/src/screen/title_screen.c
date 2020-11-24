#include "title_screen.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "graphics_manager.h"
#include "image_manager.h"
#include "input_manager.h"
#include "locale_manager.h"
#include "quiz_manager.h"
#include "timer_manager.h"

void screen_title_screen_load()
{
	//engine_graphics_manager_clear_plane();

	// TODO delete
	engine_image_manager_draw_banner();
	// TODO delete

	engine_graphics_manager_clear_area();
	engine_image_manager_draw_eddie( 0, 20, 6 );


	engine_font_manager_text( LOCALE_BANNER_TITLE, 5, BANNER_Y );

//	engine_font_manager_text( "TITLE SCREEN!!", 10, 2 );
}

void screen_title_screen_update( unsigned char *screen_type )
{
	unsigned char input;
	unsigned char input2;
	input = engine_input_manager_hold_buttonA();
	input2 = engine_input_manager_hold_buttonStart();
	if( input || input2 )
	{
		//TODO testing
		engine_quiz_manager_set_riffs_play( 0 );
		engine_quiz_manager_set_difficulty( difficulty_type_hard );
		//TODO testing

		//*screen_type = screen_type_load;
		*screen_type = screen_type_func;
		return;
	}

	*screen_type = screen_type_title;
}
