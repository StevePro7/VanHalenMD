#include "test_screen.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "image_manager.h"
//#include "sprite_manager.h"

void screen_test_screen_load()
{
	//engine_font_manager_char( '1', 2, 6 ); engine_font_manager_char( '9', 2, 7 ); engine_font_manager_char( '9', 2, 8 ); engine_font_manager_char( '1', 2, 9 );
	//engine_sprite_manager_draw( sprite_type_chose, 64, 128 );

	////engine_font_manager_char( '*', 2, 6 ); engine_font_manager_char( '*', 2, 7 );
	////engine_sprite_manager_draw( sprite_type_chose );

	engine_image_manager_draw_banner();
}

void screen_test_screen_update( unsigned char *screen_type )
{
	//engine_sprite_manager_update();
	*screen_type = screen_type_test;
}