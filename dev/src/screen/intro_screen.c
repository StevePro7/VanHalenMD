#include "intro_screen.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "graphics_manager.h"

void screen_intro_screen_load()
{
	engine_graphics_manager_clear_bottom();
	//engine_font_manager_text( "INTRO SCREEN!!", 10, 2 );
	engine_font_manager_text( "Continue on to the next screens...!", 5, 24 );
}

void screen_intro_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_intro;
}
