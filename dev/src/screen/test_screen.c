#include "test_screen.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "graphics_manager.h"
#include "image_manager.h"
#include "input_manager.h"
#include "sprite_manager.h"

void screen_test_screen_load()
{
	engine_graphics_manager_clear_area();
	engine_image_manager_draw_banner();
	engine_image_manager_draw_eddie( 0, 20, 6 );
}

void screen_test_screen_update( unsigned char *screen_type )
{
	engine_sprite_manager_update();
	*screen_type = screen_type_test;
}
