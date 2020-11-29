#include "title_screen.h"
#include "eddie_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "graphics_manager.h"
#include "hack_manager.h"
#include "image_manager.h"
#include "input_manager.h"
#include "locale_manager.h"
#include "quiz_manager.h"
#include "text_manager.h"
#include "timer_manager.h"

void screen_title_screen_load()
{
	//struct_hack_object *ho = &global_hack_object;
	unsigned char eddie_image;

	//if( ho->hack_navigation )
	//{
	//}

	engine_image_manager_draw_banner();
	engine_font_manager_text( LOCALE_BANNER_TITLE, 5, BANNER_Y );
	engine_graphics_manager_clear_area();
	eddie_image = engine_eddie_manager_next();
	engine_image_manager_draw_eddie( eddie_image, 20, 6 );


	//engine_font_manager_text( "TITLE SCREEN...!", 4, 10 );
	engine_font_manager_text( "123456789A123456789A", 0, 6 );

	engine_font_manager_text( LOCALE_TITLE_VINTAGE,7, 7 );
	engine_font_manager_text( LOCALE_TITLE_VANHALEN, 6, 8 );

	engine_text_manager_draw_lines( 30, 5 );
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
		//engine_quiz_manager_set_riffs_play( 0 );
		//engine_quiz_manager_set_difficulty( difficulty_type_easy );
		//TODO testing

		//*screen_type = screen_type_load;
		//*screen_type = screen_type_riff;
		//*screen_type = screen_type_ready;
		//*screen_type = screen_type_func;
		return;
	}


	*screen_type = screen_type_title;
	//*screen_type = screen_type_riff;
	//*screen_type = screen_type_load;
	//*screen_type = screen_type_ready;
}
