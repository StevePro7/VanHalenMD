#include "start_screen.h"
#include "eddie_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "game_manager.h"
#include "graphics_manager.h"
#include "hack_manager.h"
#include "image_manager.h"
#include "input_manager.h"
#include "locale_manager.h"
#include "quiz_manager.h"
#include "random_manager.h"
#include "sprite_manager.h"
#include "text_manager.h"
#include "timer_manager.h"

#define START_FLASH_DELAY	50
#define LOCAL_CHEAT_TOTAL	5

//static unsigned char event_stage;
//static unsigned char flash_count;
//static unsigned char cheat_count;

void screen_start_screen_load()
{
	struct_hack_object *ho = &global_hack_object;

	//engine_font_manager_text( "START SCREEN!!", 4, 12 );
	engine_font_manager_text( LOCALE_TITLE_VINTAGE, 7, 7 );
	engine_font_manager_text( LOCALE_TITLE_VANHALEN, 6, 8 );
	engine_text_manager_draw_lines( 30, 5 );

	engine_game_manager_set_local_cheat( completion_type_nop );
	if( ho->hack_invincible )
	{
		engine_font_manager_text( LOCALE_CHEAT_MARKER, 18, 27 );
		engine_game_manager_set_local_cheat( completion_type_yes );
	}

	//engine_font_manager_text( LOCALE_TITLE_START, 5, 24 );
	//engine_delay_manager_load( START_FLASH_DELAY );
	//event_stage = event_stage_start;
	//flash_count = 0;
	//cheat_count = 0;
}

void screen_start_screen_update( unsigned char *screen_type )
{
	//struct_hack_object *ho = &global_hack_object;
	//unsigned char delay;
	//unsigned char input;
	//unsigned char input2;

	//engine_sprite_manager_update();
	//delay = engine_delay_manager_update();
	//if( delay )
	//{
	//	if( !ho->hack_delayspeed )
	//	{
	//		flash_count = 1 - flash_count;
	//	}

	//	if( flash_count )
	//	{
	//		engine_font_manager_text( LOCALE_BLANK_SIZE18, 2, 24 );
	//	}
	//	else
	//	{
	//		engine_font_manager_text( LOCALE_TITLE_START, 5, 24 );
	//	}
	//}

	//input = engine_input_manager_hold_buttonA();
	//input2 = engine_input_manager_hold_buttonStart();
	//if( input || input2 )
	//{
	//	//*screen_type = screen_type_load;
	//	*screen_type = screen_type_riff;
	//	//*screen_type = screen_type_ready;
	//	//*screen_type = screen_type_func;
	//	return;
	//}

	//engine_random_manager_rand();
	//engine_sprite_manager_update();
	*screen_type = screen_type_start;
	//*screen_type = screen_type_riff;
	//*screen_type = screen_type_load;
	//*screen_type = screen_type_ready;
}
