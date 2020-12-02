#include "intro_screen.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "graphics_manager.h"
#include "image_manager.h"
#include "input_manager.h"
#include "locale_manager.h"
#include "random_manager.h"
#include "text_manager.h"
#include "timer_manager.h"

#define INTRO_SCREEN_DELAY		350

static unsigned char eddie;
static void print_text( unsigned char index );

void screen_intro_screen_load()
{
	engine_graphics_manager_clear_full();

	engine_image_manager_draw_banner();
	engine_image_manager_draw_eddie( MAX_EDDIES - 1, 14, 6 );

	engine_delay_manager_load( INTRO_SCREEN_DELAY );

	// TODO replace hard coded co-ordinates.
	engine_font_manager_text( LOCALE_EDWARD_TITLE, 12, 4 );
	engine_font_manager_text( LOCALE_BIRTH_DEATH, 14, 22 );

	eddie = 0;
	print_text( eddie );
}

void screen_intro_screen_update( unsigned char *screen_type )
{
	unsigned char delay;
	unsigned char input;
	unsigned char input2;

	delay = engine_delay_manager_update();
	if( delay )
	{
		engine_delay_manager_load( INTRO_SCREEN_DELAY );
		eddie++;
		if( eddie > 2 )
		{
			*screen_type = screen_type_title;
			return;
		}

		print_text( eddie );
	}

	input = engine_input_manager_hold_buttonA();
	input2 = engine_input_manager_hold_buttonStart();
	if( input || input2 )
	{
		*screen_type = screen_type_title;
		return;
	}

	engine_random_manager_rand();
	*screen_type = screen_type_intro;
}

static void print_text( unsigned char index )
{
	const unsigned char start = 18 + index * 4;
	const unsigned char lines = 4;

	engine_graphics_manager_clear_bottom();
	engine_text_manager_draw_lines( start, lines );

	if( 2 != index )
	{
		engine_font_manager_text( LOCALE_BUILD_VERSION, 36, 27 );
	}
}
