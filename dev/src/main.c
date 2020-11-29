#include "main.h"

int main()
{
	unsigned char open_screen_type;

	//TODO move into init_screen.
	//engine_eddie_manager_init();
	//engine_game_manager_init();
	//engine_hack_manager_init();
	//engine_quiz_manager_init();
	//engine_score_manager_init();
	//engine_sprite_manager_init();
	//TODO move into init_screen.

	//open_screen_type = screen_type_func;
	open_screen_type = screen_type_splash;
	//open_screen_type = screen_type_init;
	//open_screen_type = screen_type_title;
	//open_screen_type = screen_type_begin;
	//open_screen_type = screen_type_intro;
	//open_screen_type = screen_type_riff;
	//open_screen_type = screen_type_diff;
	//open_screen_type = screen_type_ready;
	//open_screen_type = screen_type_load;
	//open_screen_type = screen_type_prep;
	//open_screen_type = screen_type_score;
	//open_screen_type = screen_type_over;
	//open_screen_type = screen_type_test;
	engine_screen_manager_init( open_screen_type );
	while( 1 )
	{
		engine_input_manager_update();
		engine_screen_manager_update();

		VDP_waitVSync();
	}

	return 0;
}