#include "test_screen.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "graphics_manager.h"
//#include "input_manager.h"
//#include "quiz_manager.h"
//#include "storage_manager.h"
//
//static void display();
//
void screen_test_screen_load()
{
//	//engine_font_manager_char( '1', 2, 6 ); engine_font_manager_char( '9', 2, 7 ); engine_font_manager_char( '9', 2, 8 ); engine_font_manager_char( '1', 2, 9 );
//	//engine_sprite_manager_draw( sprite_type_chose, 64, 128 );
//
//	//engine_font_manager_char( '*', 2, 6 ); engine_font_manager_char( '*', 2, 7 );
//	//engine_sprite_manager_draw( sprite_type_chose );
//
	engine_graphics_manager_clear_full();
	engine_font_manager_text( "TEST SCREEN", 10, 2 );
}

void screen_test_screen_update( unsigned char *screen_type )
{
//	struct_quiz_object *qo = &global_quiz_object;
//	unsigned char input;
//
//	input = engine_input_manager_hold2_down();
//	if( input )
//	{
//	}
//
//	//engine_sprite_manager_update();
	*screen_type = screen_type_test;
}
//
//static void display()
//{
//	struct_quiz_object *qo = &global_quiz_object;
//}