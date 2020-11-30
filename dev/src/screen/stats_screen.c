#include "stats_screen.h"
#include "enum_manager.h"
#include "font_manager.h"

void screen_stats_screen_load()
{
	engine_font_manager_text( "STATS SCREEN!!", 10, 2 );
}

void screen_stats_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_stats;
}
