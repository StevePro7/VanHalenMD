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
	struct_quiz_object *qo = &global_quiz_object;
	engine_graphics_manager_clear_half();

	engine_text_manager_draw_lines( 0, 2 );
	engine_text_manager_draw_lines_extra( 2, 2, 9 );

	engine_font_manager_text( LOCALE_READY_INFOTEXT, 1, 24 );
	engine_text_manager_draw_lines( 4, 6 );

	engine_font_manager_text( LOCALE_BULLET_POINT, 2, 11 );
	engine_font_manager_text( LOCALE_BULLET_POINT, 2, 20 );

	// Alternate color text.
	engine_text_manager_draw_lines_palette( riff_line1[ qo->quiz_riff_numbs ], 4, 11 );
	engine_text_manager_draw_lines_palette( riff_line2[ qo->quiz_riff_numbs ], 4, 12 );
	engine_text_manager_draw_lines_palette( diff_line1[ qo->quiz_difficulty ], 4, 20 );
	engine_text_manager_draw_lines_palette( diff_line2[ qo->quiz_difficulty ], 4, 21 );
}

void screen_ready_screen_update( unsigned char *screen_type )
{
	unsigned char input;

	engine_sprite_manager_update();
	input = engine_input_manager_hold_buttonA();
	if( input )
	{
		//engine_font_manager_text( "begin", 0, 0 );
		//engine_quiz_manager_set_quiz_saved_all();

		*screen_type = screen_type_load;
		return;
	}

	engine_sprite_manager_update();
	*screen_type = screen_type_ready;
}