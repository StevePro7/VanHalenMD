#include "over_screen.h"
#include "cursor_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "graphics_manager.h"
#include "input_manager.h"
#include "locale_manager.h"
#include "quiz_manager.h"
#include "score_manager.h"
#include "sprite_manager.h"
#include "text_manager.h"

void screen_over_screen_load()
{
	struct_quiz_object *qo = &global_quiz_object;
	engine_font_manager_text( "OVER SCREEN!!", 10, 2 );

	engine_cursor_manager_hide();
	engine_graphics_manager_clear_half();

	engine_font_manager_text( LOCALE_SUMMARY_OVER, 1, 7 );
	engine_text_manager_draw_lines( 4, 4 );
	engine_text_manager_draw_lines( 12, 2 );
	engine_score_manager_draw_summary( qo->quiz_riffs_play );
}

void screen_over_screen_update( unsigned char *screen_type )
{
	unsigned char input;
	//unsigned char input2;		// TODO delete

	input = engine_input_manager_hold_buttonA();
	//input2 = engine_input_manager_hold_right();		// TODO delete
	if( input ) // || input2 )
	{
		*screen_type = screen_type_riff;
		return;
	}

	engine_sprite_manager_update();
	*screen_type = screen_type_over;
}
