#include "text_manager.h"
#include "font_manager.h"
#include "global_manager.h"

void engine_text_manager_draw_lines( unsigned char start, unsigned char lines )
{
	engine_text_manager_draw_lines_extra( start, lines, 0 );
}

void engine_text_manager_draw_lines_extra( unsigned char start, unsigned char lines, signed char deltaY )
{
	unsigned char idx;
	unsigned short posX;
	unsigned short posY;
	const char *text;
	unsigned char maxim = start + lines;

	for( idx = start; idx < maxim; idx++ )
	{
		posX = global_text_object[ idx ].posX;
		posY = global_text_object[ idx ].posY;
		text = global_text_object[ idx ].text;
		engine_font_manager_text( text, posX, posY + deltaY );
	}
}
