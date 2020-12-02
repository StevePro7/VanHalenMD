#include "begin_screen.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "graphics_manager.h"
#include "image_manager.h"
#include "input_manager.h"
#include "locale_manager.h"
#include "timer_manager.h"

#ifdef _CONSOLE
#include <string.h>
#else
#include <genesis.h>
#endif

static void draw_texter();

void screen_begin_screen_load()
{
	engine_graphics_manager_clear_full();
	draw_texter();
	engine_font_manager_text( LOCALE_BUILD_VERSION, 36, 27 );

	// TODO render image after pause...
	engine_image_manager_draw_header();
}

void screen_begin_screen_update( unsigned char *screen_type )
{
	//unsigned char delay;
	unsigned char input;
	unsigned char input2;

	input = engine_input_manager_hold_buttonA();
	input2 = engine_input_manager_hold_buttonStart();
	if( input || input2 )
	{
		*screen_type = screen_type_intro;
		return;
	}

	*screen_type = screen_type_begin;
}

static void draw_texter()
{
	unsigned short length;
	unsigned char index;
	const unsigned char start = 8;
	const unsigned char step = 4;
	const unsigned char y = 6;

	length = strlen( LOCALE_TITLE_VINTAGE );
	for( index = 0; index < length; index++ )
	{
		engine_font_manager_char( LOCALE_TITLE_VINTAGE[ index ], start + ( index * step ), y );
	}

	//engine_font_manager_char( 'V', 8, 4 );
	//engine_font_manager_char( 'I', 12, 4 );
	//engine_font_manager_char( 'N', 16, 4 );
	//engine_font_manager_char( 'T', 20, 4 );
	//engine_font_manager_char( 'A', 24, 4 );
	//engine_font_manager_char( 'G', 28, 4 );
	//engine_font_manager_char( 'E', 32, 4 );
}

