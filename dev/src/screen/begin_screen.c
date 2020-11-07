#include "begin_screen.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "input_manager.h"
#include "sprite_manager.h"

#ifdef _CONSOLE
#include "_genesis.h"
#else
#include <genesis.h>
#endif

void screen_begin_screen_load()
{
	VDP_setTextPalette( PAL0 );
	//engine_font_manager_text( "BEGIN SCREEN!!", 2, 10 );
	VDP_drawText( "BEGIN SCREEN!!", 2, 10 );
	engine_sprite_manager_draw( sprite_type_actor );
	//engine_sprite_manager_draw( sprite_type_right );
}

void screen_begin_screen_update( unsigned char *screen_type )
{
	u16 color;
	//unsigned char input;
	//input = engine_input_manager_hold_right();
	//if( input )
	//{
	//	color = RGB24_TO_VDPCOLOR( 0x9ACD32 );
	//	VDP_setPaletteColor( 63, color );
	//	VDP_setTextPalette( PAL3 );
	//	VDP_drawText( "SET COLOR...!", 2, 12 );
	//	//engine_font_manager_text( "SET COLOR...!", 2, 12 );
	//}

	unsigned char input;
	input = engine_input_manager_hold_buttonA();
	if( input )
	{
		engine_sprite_manager_draw( sprite_type_actor );
	}

	input = engine_input_manager_hold_up();
	if( input )
	{
		engine_sprite_manager_move_up();
	}
	input = engine_input_manager_hold_down();
	if( input )
	{
		engine_sprite_manager_move_down();
	}

	input = engine_input_manager_hold_left();
	if( input )
	{
		VDP_setTextPalette( PAL0 );
		engine_font_manager_text( "1234123412341234", 4, 15 );
		engine_sprite_manager_draw( sprite_type_right );
	}
	input = engine_input_manager_hold_right();
	if( input )
	{
		VDP_setTextPalette( PAL0 );
		engine_font_manager_text( "BLAH!!", 3, 15 );
		engine_sprite_manager_draw( sprite_type_wrong );
	}

	input = engine_input_manager_hold_buttonB();
	if( input )
	{
		VDP_setTextPalette( PAL0 );
		engine_font_manager_text( "SET COLOR...!", 2, 12 );

		color = RGB24_TO_VDPCOLOR( 0x9ACD32 );
		VDP_setPaletteColor( 63, color );
		VDP_setTextPalette( PAL3 );
		//	VDP_drawText( "SET COLOR...!", 2, 12 );
		//	//engine_font_manager_text( "SET COLOR...!", 2, 12 );
		engine_font_manager_text( "BEGIN SCREEN!!", 2, 10 );
	}

	input = engine_input_manager_hold_buttonC();
	if( input )
	{
		VDP_setTextPalette( PAL0 );
		engine_font_manager_text( "BEGIN SCREEN!!", 2, 10 ); 

		color = RGB24_TO_VDPCOLOR( 0x9ACD32 );
		VDP_setPaletteColor( 63, color );
		VDP_setTextPalette( PAL3 );
		engine_font_manager_text( "SET COLOR...!", 2, 12 );
	}

	engine_sprite_manager_update();
	*screen_type = screen_type_begin;
}
