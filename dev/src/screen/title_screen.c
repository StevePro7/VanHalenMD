#include "title_screen.h"
#include "eddie_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
//#include "game_manager.h"
#include "graphics_manager.h"
//#include "hack_manager.h"
#include "image_manager.h"
//#include "input_manager.h"
#include "locale_manager.h"
//#include "quiz_manager.h"
//#include "random_manager.h"
//#include "sprite_manager.h"
//#include "text_manager.h"
//#include "timer_manager.h"

void screen_title_screen_load()
{
	unsigned char eddie_image;
	engine_image_manager_draw_banner();
	engine_font_manager_text( LOCALE_BANNER_TITLE, 5, BANNER_Y );
	engine_graphics_manager_clear_area();
	eddie_image = engine_eddie_manager_next();
	engine_image_manager_draw_eddie( eddie_image, 20, 6 );
}

void screen_title_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_start;
	//*screen_type = screen_type_title;
}
