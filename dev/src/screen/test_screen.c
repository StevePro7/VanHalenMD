#include "test_screen.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "global_manager.h"
#include "image_manager.h"
#include "input_manager.h"
#include "quiz_manager.h"
#include "random_manager.h"
#include "gfx.h"

#ifdef _CONSOLE
#include "_genesis.h"
#else
#include <genesis.h>
#endif

static unsigned char quiz;
static unsigned char eddie;

void screen_test_screen_load()
{
	unsigned char diffulty = difficulty_type_easy;
	eddie = engine_random_manager_data( MAX_EDDIES );
	//unsigned char diffulty = difficulty_type_hard;

	// Clear screen.
	VDP_clearPlane( BG_A, 0 );

	engine_image_manager_draw( gfx_banner, PAL1, PALETTE1_TILES, 0, 0 );
	engine_image_manager_eddie( eddie );
	//engine_image_manager_draw( gfx_eddie_05, PAL2, PALETTE2_TILES, 20, 6 );

	engine_quiz_manager_load_normal( diffulty );
	//engine_quiz_manager_load_mixing( diffulty );
	//engine_quiz_manager_load_random( diffulty );

	quiz = 0;

	engine_quiz_manager_clear();
	engine_quiz_manager_draw( quiz );
	engine_quiz_manager_debug_stats( quiz );		// TODO delete!!

	//engine_quiz_manager_debug_option( 0 );
	//engine_quiz_manager_debug_riffs();
}

void screen_test_screen_update( unsigned char *screen_type )
{
	unsigned char input;
	//input = engine_input_manager_hold_left();
	//if( input )
	//{
	//	if( 0 == quiz )
	//	{
	//		quiz = MAX_RIFFS - 1;
	//	}
	//	else
	//	{
	//		quiz--;
	//	}

	//	//eddie = engine_random_manager_data( MAX_EDDIES );
	//	//engine_image_manager_eddie( eddie );

	//	//engine_quiz_manager_clear();
	//	engine_quiz_manager_draw( quiz );
	//	engine_quiz_manager_debug_stats( quiz );		// TODO delete!!
	//	//engine_font_manager_data( ( quiz + 1 ), 30, 20 ); // TODO delete!!
	//}

	input = engine_input_manager_hold_right();
	if( input )
	{
		if( ( MAX_RIFFS - 1 ) == quiz )
		{
			quiz = 0;
		}
		else
		{
			quiz++;
		}

		//if( quiz >= MAX_RIFFS )
		//{
		//	quiz = 0;
		//}

		//VDP_clearPlane( BG_A, 0 );
		//VDP_resetScreen();
		BMP_clear();
		//engine_image_manager_draw( gfx_banner, PAL1, PALETTE1_TILES, 0, 0 );
		eddie = engine_random_manager_data( MAX_EDDIES );
		engine_image_manager_eddie( eddie );

		//engine_quiz_manager_clear();
		engine_quiz_manager_draw( quiz );
		engine_quiz_manager_debug_stats( quiz );		// TODO delete!!
		//engine_font_manager_data( ( quiz + 1 ), 30, 20 ); // TODO delete!!
	}


	*screen_type = screen_type_test;
}