#include "ready_screen.h"
//#include "cursor_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "graphics_manager.h"
#include "input_manager.h"
//#include "locale_manager.h"
//#include "quiz_manager.h"
#include "sprite_manager.h"
//#include "timer_manager.h"

void screen_ready_screen_load()
{
	engine_font_manager_text( "READY SCREEN", 10, 2 );

	engine_graphics_manager_clear_area();
	//engine_frame_manager_load( 100 );
	//engine_sprite_manager_load( 1 );
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
		engine_font_manager_text( "begin", 0, 0 );
		*screen_type = screen_type_load;
		return;
	}

	engine_sprite_manager_update();
	*screen_type = screen_type_ready;
}