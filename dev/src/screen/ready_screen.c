#include "ready_screen.h"
//#include "cursor_manager.h"
#include "eddie_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "hack_manager.h"
#include "graphics_manager.h"
#include "image_manager.h"
#include "input_manager.h"
#include "locale_manager.h"
#include "quiz_manager.h"
#include "sprite_manager.h"
#include "storage_manager.h"
#include "text_manager.h"
//#include "timer_manager.h"

void screen_ready_screen_load()
{
	struct_hack_object *ho = &global_hack_object;
	struct_quiz_object *qo = &global_quiz_object;
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

	engine_text_manager_draw_lines( 0, 2 );
	engine_text_manager_draw_lines_extra( 2, 2, 7 );
	//engine_text_manager_draw_lines_extra( 8, 2, -5 );

	engine_font_manager_text( LOCALE_BULLET_POINT, 2, 10 );
	engine_font_manager_text( LOCALE_BULLET_POINT, 2, 17 );

	engine_font_manager_text( riff_line1[ qo->quiz_riff_numbs ], 4, 10 );
	engine_font_manager_text( riff_line2[ qo->quiz_riff_numbs ], 4, 11 );

	engine_font_manager_text( diff_line1[ qo->quiz_difficulty ], 4, 17 );
	engine_font_manager_text( diff_line2[ qo->quiz_difficulty ], 4, 18 );

	//TODO delete
	//engine_font_manager_text( "GET READY...", 4, 20 );
}

void screen_ready_screen_update( unsigned char *screen_type )
{
	unsigned char input;
	unsigned char input2;		// TODO delete

	engine_sprite_manager_update();

	input = engine_input_manager_hold_buttonA();
	input2 = engine_input_manager_hold_right();		// TODO delete
	if( input || input2 )
	{
		//engine_font_manager_text( "begin", 0, 0 );
		engine_quiz_manager_set_quiz_saved_all();

		// TODO re-instate!!
		//*screen_type = screen_type_load;
		// TODO re-instate!!

		*screen_type = screen_type_test;
		return;
	}


	engine_sprite_manager_update();
	*screen_type = screen_type_ready;
}