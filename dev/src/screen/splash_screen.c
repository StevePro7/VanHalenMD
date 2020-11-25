#include "splash_screen.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "graphics_manager.h"
#include "image_manager.h"

void screen_splash_screen_load()
{
	//engine_graphics_manager_clear_plane();
	engine_image_manager_draw_splash();
}

void screen_splash_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_splash;
}
