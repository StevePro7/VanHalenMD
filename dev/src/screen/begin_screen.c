#include "begin_screen.h"
#include "enum_manager.h"
#include "font_manager.h"

void screen_begin_screen_load()
{
	engine_font_manager_text( "BEGIN SCREEN!!", 2, 10 );
}

void screen_begin_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_begin;
}
