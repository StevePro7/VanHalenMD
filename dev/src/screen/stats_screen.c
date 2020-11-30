#include "stats_screen.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "graphics_manager.h"
#include "input_manager.h"

void screen_stats_screen_load()
{
	engine_graphics_manager_clear_half();
	engine_font_manager_text( "STATS SCREEN!!", 5, 7 );
}

void screen_stats_screen_update( unsigned char *screen_type )
{
	unsigned char input;
	input = engine_input_manager_hold_buttonB();
	if( input )
	{
		*screen_type = screen_type_start;
		return;
	}

	*screen_type = screen_type_stats;
}
