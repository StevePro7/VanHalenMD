#include "debug_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "quiz_manager.h"
#include "score_manager.h"

void engine_debug_manager_cheat( unsigned char select )
{
	// TODO replace hard coded co-ordinates.
	engine_font_manager_data( select, 15, 27 );
}

void engine_debug_manager_answer( unsigned char answer )
{
	// TODO replace hard coded co-ordinates.
	const char *str = sprite_type_right == answer ? "RIGHT" : "WRONG";
	engine_font_manager_text( str, 35, 1 );
}

void engine_debug_manager_eddie()
{
	struct_quiz_object *qo = &global_quiz_object;
	engine_font_manager_text( "12345678901234567890", 20, 6 );
	engine_font_manager_data( qo->quiz_riff_index+1, 30, 20 );
	engine_font_manager_text( "12345678901234567890", 20, 27 );
}

void engine_debug_manager_score()
{
	struct_quiz_object *qo = &global_quiz_object;
	struct_score_object *so = &global_socre_object;
	unsigned char save_index = quiz_saving[ qo->quiz_riff_index ];

	engine_font_manager_zero( so->saved_correct[ save_index ], 30, 0 );
	engine_font_manager_zero( so->saved_answerd[ save_index ], 30, 1 );
}