#include "text_manager.h"
//#include "enum_manager.h"
#include "font_manager.h"
#include "global_manager.h"
//#include "locale_manager.h"

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


//TODO delete
//void Food() {}
//void RiffScreen()
//{
//	unsigned char i;
//	unsigned short x;
//	unsigned short y;
//	const char *t;
//
//	for( i = 0; i < MAX_MENUS; i++ )
//	{
//		x = riff_text_object[ i ].posX;
//		y = riff_text_object[ i ].posY;
//		t = riff_text_object[ i ].text;
//		engine_font_manager_text( t, x, y );
//	}
//}
//void DiffScreen()
//{
//	unsigned char i;
//	unsigned short x;
//	unsigned short y;
//	const char *t;
//
//	for( i = 0; i < MAX_MENUS; i++ )
//	{
//		x = diff_text_object[ i ].posX;
//		y = diff_text_object[ i ].posY;
//		t = diff_text_object[ i ].text;
//		engine_font_manager_text( t, x, y );
//	}
//}
//TODO delete


//void engine_text_manager_load( unsigned char cursor, unsigned char maximum, const char **options, const char **line1, const char **line2, const char **line3, const char **line4 )
//{
//	unsigned char idx;
//	for( idx = 0; idx < maximum; idx++ )
//	{
//		text_options[ idx ] = cursor_type_small == cursor ? options[ 0 ] : options[ idx ];
//
//		text_line1[ idx ] = line1[ idx ];
//		text_line2[ idx ] = line2[ idx ];
//		if( cursor_type_small == cursor )
//		{
//			continue;
//		}
//
//		text_line3[ idx ] = line3[ idx ];
//		text_line4[ idx ] = line4[ idx ];
//	}
//}
//
//void engine_text_manager_draw_line( unsigned char cursor, unsigned char index, unsigned char x, unsigned char y )
//{
//	engine_font_manager_text( text_line1[ index ], x, y + 0 );
//	engine_font_manager_text( text_line2[ index ], x, y + 1 );
//	if( cursor_type_small == cursor )
//	{
//		return;
//	}
//
//	engine_font_manager_text( text_line3[ index ], x, y + 2 );
//	engine_font_manager_text( text_line4[ index ], x, y + 3 );
//}
//
//void engine_text_manager_draw_option( unsigned char cursor, unsigned char index, unsigned char x, unsigned char y )
//{
//	const char *option = text_options[ index ];
//	engine_text_manager_draw_options( cursor, option, x, y );
//}
//
//void engine_text_manager_draw_options( unsigned char cursor, const char *option, unsigned char x, unsigned char y )
//{
//	engine_font_manager_char( option[ 0 ], x, y + 0 );
//	engine_font_manager_char( option[ 1 ], x, y + 1 );
//
//	if( cursor_type_small == cursor )
//	{
//		return;
//	}
//
//	engine_font_manager_char( option[ 2 ], x, y + 2 );
//	engine_font_manager_char( option[ 3 ], x, y + 3 );
//}

