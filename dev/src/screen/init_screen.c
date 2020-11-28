#include "init_screen.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "graphics_manager.h"
#include "quiz_manager.h"
#include "sprite_manager.h"

void screen_init_screen_load()
{
//	//struct_quiz_object *qo = &global_quiz_object;
	engine_font_manager_text( "INIT SCREEN", 10, 2 );
//	engine_graphics_manager_clear_area();
//
//	engine_quiz_manager_riff();
//
//	// TODO add hack manager to check if cheat enabled
//	//engine_quiz_manager_cheat();
//	// TODO add hack manager to check if cheat enabled
//
//	//engine_cursor_manager_load_large( MAX_OPTION, qo->quiz_selections, OPTION_X, quiz_yPos, quiz_years, quiz_line1, quiz_line2, quiz_line3, quiz_line4 );
//	////engine_cursor_manager_load_large( MAX_OPTION, 1, OPTION_X, quiz_yPos, quiz_years, quiz_line1, quiz_line2, quiz_line3, quiz_line4 );
//	//engine_cursor_manager_draw();
}

void screen_init_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_init;
}