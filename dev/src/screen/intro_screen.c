#include "intro_screen.h"
#include "enum_manager.h"
#include "global_manager.h"
#include "image_manager.h"
#include "sprite_manager.h"
#include "gfx.h"

void screen_intro_screen_load()
{
	engine_image_manager_draw( gfx_banner, PAL1, PALETTE1_TILES, 0, 0 );
	engine_image_manager_draw( gfx_eddie_17, PAL2, PALETTE2_TILES, 20, 6 );
}

void screen_intro_screen_update( unsigned char *screen_type )
{
	engine_sprite_manager_update();
	*screen_type = screen_type_intro;
}
