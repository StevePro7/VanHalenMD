#include "test_screen.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "graphics_manager.h"
#include "image_manager.h"
#include "input_manager.h"
#include "sprite_manager.h"

static unsigned short title;
static unsigned short image;

static void print_data();

void screen_test_screen_load()
{
	title = 1;
	image = 240;

	engine_graphics_manager_clear_area();
	engine_image_manager_draw_banner2( title );
	engine_image_manager_draw_eddie2( image, 0, 20, 6 );
	print_data();
}

void screen_test_screen_update( unsigned char *screen_type )
{
	unsigned char input;
	input = engine_input_manager_move_up();
	if( input )
	{
		title--;
		print_data();
	}
	input = engine_input_manager_move_down();
	if( input )
	{
		title++;
		print_data();
	}
	input = engine_input_manager_move_left();
	if( input )
	{
		image--;
		print_data();
	}
	input = engine_input_manager_move_right();
	if( input )
	{
		image++;
		print_data();
	}

	input = engine_input_manager_move_buttonA();
	if( input )
	{
		engine_image_manager_draw_banner2( title );
		engine_image_manager_draw_eddie2( image, 0, 20, 6 );
	}

	engine_sprite_manager_update();
	*screen_type = screen_type_test;
}

static void print_data()
{
	engine_font_manager_data( title, 10, 10 );
	engine_font_manager_data( image, 10, 15 );
}