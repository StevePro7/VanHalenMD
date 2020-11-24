#include "title_screen.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "graphics_manager.h"
#include "image_manager.h"
#include "input_manager.h"
#include "locale_manager.h"
#include "text_manager.h"
#include "timer_manager.h"

void screen_title_screen_load()
{
	engine_graphics_manager_clear_area();

	// TODO delete
	engine_image_manager_draw_banner();
	// TODO delete

	engine_font_manager_text( LOCALE_BANNER_TITLE, 5, 4 );
	//engine_font_manager_text( "TITLE SCREEN!!", 10, 2 );

	engine_image_manager_draw_eddie( 0, 20, 6 );
}

void screen_title_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_title;
}
