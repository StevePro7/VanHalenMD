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
	//engine_sprite_manager_draw( sprite_type_actor );
	engine_sprite_manager_draw( sprite_type_right );
}

void screen_begin_screen_update( unsigned char *screen_type )
{
	u16 color;
	unsigned char input;
	input = engine_input_manager_hold_right();
	if( input )
	{
		color = RGB24_TO_VDPCOLOR( 0x9ACD32 );
		VDP_setPaletteColor( 63, color );
		VDP_setTextPalette( PAL3 );
		VDP_drawText( "SET COLOR...!", 2, 12 );
		//engine_font_manager_text( "SET COLOR...!", 2, 12 );
	}

	engine_sprite_manager_update();
	*screen_type = screen_type_begin;
}
