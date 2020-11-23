#include "main.h"

int main()
{
	//unsigned char open_screen_type;

	////open_screen_type = screen_type_splash;
	////open_screen_type = screen_type_intro;
	////open_screen_type = screen_type_begin;
	////open_screen_type = screen_type_quiz;
	//open_screen_type = screen_type_test;

	//engine_screen_manager_init( open_screen_type );
	//engine_quiz_manager_init();
	//engine_sprite_manager_init();
	while( 1 )
	{
		//engine_input_manager_update();
		//engine_screen_manager_update();

		VDP_waitVSync();
	}

	return 0;
}