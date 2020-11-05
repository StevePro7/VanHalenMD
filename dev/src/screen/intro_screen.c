#include "intro_screen.h"
#include "enum_manager.h"
#include "image_manager.h"
#include "gfx.h"

void screen_intro_screen_load()
{
	engine_image_manager_draw( gfx_banner, PAL1, 0, 0 );
	engine_image_manager_draw( gfx_eddie_09, PAL2, 20, 6 );
}

void screen_intro_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_intro;
}
