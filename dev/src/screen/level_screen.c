//#include "level_screen.h"
//#include "cursor_manager.h"
//#include "enum_manager.h"
//#include "font_manager.h"
////#include "global_manager.h"
//#include "input_manager.h"
//#include "quiz_manager.h"
//#include "sprite_manager.h"
////#include "text_manager.h"
//
//void screen_level_screen_load()
//{
//	engine_font_manager_text( "LVeL SCREEN", 10, 2 );
//}
//
//void screen_level_screen_update( unsigned char *screen_type )
//{
//	struct_cursor_object *co = &global_cursor_object;
//	struct_quiz_object *qo = &global_quiz_object;
//	unsigned char input;
//	unsigned char correct;
//	input = engine_input_manager_hold_left();
//	if( input )
//	{
//		engine_font_manager_data( co->selects, 30, 0 );
//
//		engine_quiz_manager_decrement( co->selects );
//		*screen_type = screen_type_init;
//		return;
//	}
//	input = engine_input_manager_hold_right();
//	if( input )
//	{
//		engine_font_manager_data( co->selects, 30, 0 );
//		correct = quiz_select[ qo->quiz_riff_index ];
//		if( co->selects == correct )
//		{
//			engine_font_manager_text( "RIGHT", 30, 1 );
//			engine_cursor_manager_action( sprite_type_right );
//		}
//		else
//		{
//			engine_font_manager_text( "WRONG", 30, 1 );
//			engine_cursor_manager_action( sprite_type_wrong );
//		}
//
//		//engine_quiz_manager_increment( co->selects );
//		*screen_type = screen_type_ready;
//		return;
//	}
//
//	input = engine_input_manager_hold_up();
//	if( input )
//	{
//		engine_cursor_manager_move_up();
//	}
//	input = engine_input_manager_hold_down();
//	if( input )
//	{
//		engine_cursor_manager_move_down();
//	}
//
//	engine_sprite_manager_update();
//	*screen_type = screen_type_level;
//}
