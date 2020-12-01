#include "begin_screen.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "graphics_manager.h"
#include "image_manager.h"
#include "input_manager.h"
#include "timer_manager.h"

static void draw_texter();

void screen_begin_screen_load()
{
	engine_graphics_manager_clear_full();
	draw_texter();
	engine_image_manager_draw_header();
}

void screen_begin_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_begin;
}

static void draw_texter()
{
	engine_font_manager_char( 'V', 8, 6 );
	engine_font_manager_char( 'I', 12, 6 );
	engine_font_manager_char( 'N', 16, 6 );
	engine_font_manager_char( 'T', 20, 6 );
	engine_font_manager_char( 'A', 24, 6 );
	engine_font_manager_char( 'G', 28, 6 );
	engine_font_manager_char( 'E', 32, 6 );
}

