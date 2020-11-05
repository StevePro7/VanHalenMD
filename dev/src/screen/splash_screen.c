#include "splash_screen.h"
#include "enum_manager.h"
#include "image_manager.h"
#include "gfx.h"

void screen_splash_screen_load()
{
	engine_image_manager_draw( gfx_splash, PAL1, 4, 2 );
}

void screen_splash_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_splash;
}
