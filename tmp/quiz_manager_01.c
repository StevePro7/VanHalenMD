#include "quiz_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "function_manager.h"
#include "global_manager.h"
#include "hack_manager.h"
#include "music_manager.h"
#include "random_manager.h"
#include "music_object.h"
#ifdef _CONSOLE
#include <string.h>
#else
#include <genesis.h>
#endif


// Global variables.
struct_quiz_object global_quiz_object;

static void print_year( const char *year, unsigned char x, unsigned char y );

void engine_quiz_manager_init()
{
	unsigned char idx, opt;
	for( idx = 0; idx < MAX_RIFFS; idx++ )
	{
		quiz_answer[ idx ] = 0;
		for( opt = 0; opt < MAX_OPTION; opt++ )
		{
			quiz_option[ idx ][ opt ] = 0;
		}
	}
}

void engine_quiz_manager_load()
{
	unsigned char idx;
	unsigned char opt;
	unsigned char rnd;
	for( idx = 0; idx < MAX_RIFFS; idx++ )
	{
		while( 1 )
		{
			rnd = engine_random_manager_data( MAX_RIFFS );
			if( 0 == quiz_answer[ rnd ] )
			{
				quiz_answer[ rnd ] = music_riffs[ idx ];
				break;
			}
		}

		for( opt = 0; opt < MAX_OPTION; opt++ )
		{
			quiz_option[ idx ][ opt ] = opt;
		}
	}
}

void engine_quiz_manager_load_random()
{
	struct_hack_object *ho = &global_hack_object;
	unsigned char idx;
	unsigned char opt;
	unsigned char rnd;
	unsigned char ans;
	unsigned char riff;
	
	unsigned char album, songs;
	unsigned char count;

	for( idx = 0; idx < MAX_RIFFS; idx++ )
	{
		while( 1 )
		{
			rnd = engine_random_manager_data( MAX_RIFFS );
			if( 0 == quiz_answer[ rnd ] )
			{
				quiz_answer[ rnd ] = music_riffs[ idx ];
				break;
			}
		}
	}

	// Must iterate and randomize all the riffs before randomize options!
	for( idx = 0; idx < MAX_RIFFS; idx++ )
	{
		riff = quiz_answer[ idx ];
		album = 0;
		songs = 0;
		engine_function_manager_convertByteToNibbles( riff, &album, &songs );

		// Randomize correct answer first.
		ans = engine_random_manager_data( MAX_OPTION );
		quiz_select[ idx ] = ans;
		quiz_option[ idx ][ ans ] = riff;

		for( opt = 0; opt < MAX_OPTION; opt++ )
		{
			if( ans == opt )
			{
				continue;;
			}

			while( 1 )
			{
				if( random_type_diff == ho->hack_object_random )
				{
					album = engine_random_manager_data( MAX_ALBUMS );
				}

				count = music_count[ album ];
				songs = engine_random_manager_data( count );
				engine_function_manager_convertNibblesToByte( album, songs, &riff );

				if(
					( riff != quiz_option[ idx ][ 0 ] ) &&
					( riff != quiz_option[ idx ][ 1 ] ) &&
					( riff != quiz_option[ idx ][ 2 ] ) &&
					( riff != quiz_option[ idx ][ 3 ] )
					)
				{
					quiz_option[ idx ][ opt ] = riff;
					break;
				}
			}
		}
	}

	quiz_option[ 0 ][ 0 ] = 0x37;
	//quiz_option[ 0 ][ 1 ] = 0x49;
	//quiz_option[ 0 ][ 2 ] = 0x87;
	//quiz_option[ 0 ][ 3 ] = 0x9A;

	//quiz_option[ 0 ][ 0 ] = 0x86;
	//quiz_option[ 0 ][ 1 ] = 0x50;
	//quiz_option[ 0 ][ 2 ] = 0x67;
	//quiz_option[ 0 ][ 3 ] = 0xA9;
}

void engine_quiz_manager_load_mixing()
{
	struct_hack_object *ho = &global_hack_object;
	unsigned char idx;
	unsigned char opt;
	unsigned char ans;
	unsigned char riff;

	unsigned char album, songs;
	unsigned char count;

	for( idx = 0; idx < MAX_RIFFS; idx++ )
	{
		quiz_answer[ idx ] = music_riffs[ idx ];
	}

	// Must iterate and randomize all the riffs before randomize options!
	for( idx = 0; idx < MAX_RIFFS; idx++ )
	{
		riff = quiz_answer[ idx ];
		album = 0;
		songs = 0;
		engine_function_manager_convertByteToNibbles( riff, &album, &songs );

		// Randomize correct answer first.
		ans = engine_random_manager_data( MAX_OPTION );
		quiz_select[ idx ] = ans;
		quiz_option[ idx ][ ans ] = riff;

		for( opt = 0; opt < MAX_OPTION; opt++ )
		{
			if( ans == opt )
			{
				continue;;
			}

			while( 1 )
			{
				if( random_type_diff == ho->hack_object_random )
				{
					album = engine_random_manager_data( MAX_ALBUMS );
				}

				count = music_count[ album ];
				songs = engine_random_manager_data( count );
				engine_function_manager_convertNibblesToByte( album, songs, &riff );

				if(
					( riff != quiz_option[ idx ][ 0 ] ) &&
					( riff != quiz_option[ idx ][ 1 ] ) &&
					( riff != quiz_option[ idx ][ 2 ] ) &&
					( riff != quiz_option[ idx ][ 3 ] )
					)
				{
					quiz_option[ idx ][ opt ] = riff;
					break;
				}
			}
		}
	}
}

void engine_quiz_manager_draw( unsigned char idx )
{
	//unsigned char idx;
	unsigned char opt;
	unsigned char x, y;
	unsigned char total;

	unsigned char album, songs, riff;
	const char *years;
	const char *title;
	const char *music;
	x = 2;
	y = 1;

	//idx = 20;
	//opt = 1;
	for( opt = 0; opt < MAX_OPTION; opt++ )
	{
		riff = quiz_option[ idx ][ opt ];
		album = 0;
		songs = 0;
		engine_function_manager_convertByteToNibbles( riff, &album, &songs );

		years = music_years[ album ];
		title = music_album[ album ];

		total = music_total[ album ];
		total += songs;
		music = music_songs[ total ];
		engine_font_manager_text( years, x, y + 0 );
		engine_font_manager_text( title, x, y + 1 );
		engine_font_manager_text( music, x, y + 2 );

		y += 5;
	}
}

void engine_quiz_manager_draw2()
{
	unsigned char idx;
	unsigned char opt;
	unsigned char x, y;
	unsigned char total;
	unsigned short length;

	unsigned char album, songs, riff;
	const char *years;
	//const char *title;
	//const char *music;
	const char *title1, *title2;
	const char *music1, *music2;

	//engine_font_manager_text( "A", 0, 0 );
	//engine_font_manager_text( "XXXX", 0, 7 );
	for( idx = 6; idx < 28; idx++ )
	{
		//engine_font_manager_data( ( idx + 1 ), 10, idx );
		//engine_font_manager_text( "123456789A123456789B", 20, idx );
		//engine_font_manager_text( "123456789A12345678", 22, idx );
		//engine_font_manager_data( ( idx - 7 ), 35, idx );
	}

	idx = 0;
	x = 2;
	y = 6;
	opt = 0;
	for( opt = 0; opt < MAX_OPTION; opt++ )
	{
		riff = quiz_option[ idx ][ opt ];
		album = 0;
		songs = 0;
		engine_function_manager_convertByteToNibbles( riff, &album, &songs );

		years = music_years[ album ];
		//title = music_album[ album ];
		title1 = music_album1[ album ];
		title2 = music_album2[ album ];

		total = music_total[ album ];
		total += songs;
		//music = music_songs[ total ];
		music1 = music_songs1[ total ];
		music2 = music_songs2[ total ];

		print_year( years, x, y );
		//engine_font_manager_text( title, x + 2, y + 0 );
		//engine_font_manager_text( music, x + 2, y + 2 );
		engine_font_manager_text( title1, x + 2, y );
		y++;

		length = strlen( title2 );
		//engine_font_manager_data( length, 10, 2 );
		if( 0 != length )
		{
			//engine_font_manager_text( "EMPTY", x + 2, y + 1 );
			engine_font_manager_text( title2, x + 2, y );
			y++;
		}
		//else
		//{
		//	engine_font_manager_text( title2, x + 2, y + 1 );
		//}
		engine_font_manager_text( music1, x + 2, y );
		y++;
		engine_font_manager_text( music2, x + 2, y );
		y++;
		if( 0 == length )
		{
			y++;
		}
		
		y += 2;
	}
}

static void print_year( const char *years, unsigned char x, unsigned char y )
{
	//engine_font_manager_text( &years[3], x, y + 3 );
	//engine_font_manager_text( &years[ 2 ], x, y + 2 );
	engine_font_manager_char( years[ 0 ], x, y + 0 );
	engine_font_manager_char( years[ 1 ], x, y + 1 );
	engine_font_manager_char( years[ 2 ], x, y + 2 );
	engine_font_manager_char( years[ 3 ], x, y + 3 );
}

void engine_quiz_manager_draw_option()
{
	unsigned char lop;
	unsigned char idx;
	unsigned char ans;
	unsigned char tst;
	unsigned char x, y;

	x = 0;
	y = 0;
	for( lop = 0; lop < 25; lop++ )
	{
		idx = 25 * 0 + lop;
		//idx = 25 * 1 + lop;

		ans = quiz_option[ idx ][ 3 ];	engine_font_manager_data( ans, x + 22, y );
		ans = quiz_option[ idx ][ 2 ];	engine_font_manager_data( ans, x + 18, y );
		ans = quiz_option[ idx ][ 1 ];	engine_font_manager_data( ans, x + 14, y );
		ans = quiz_option[ idx ][ 0 ];	engine_font_manager_data( ans, x + 10, y );

		ans = quiz_answer[ idx ];	engine_font_manager_data( ans, x + 4, y );
		engine_font_manager_data( ( idx + 1 ), x + 0, y );

		tst = (
			( quiz_option[ idx ][ 3 ] == quiz_option[ idx ][ 2 ] ) ||
			( quiz_option[ idx ][ 3 ] == quiz_option[ idx ][ 1 ] ) ||
			( quiz_option[ idx ][ 3 ] == quiz_option[ idx ][ 0 ] ) ||
			( quiz_option[ idx ][ 2 ] == quiz_option[ idx ][ 1 ] ) ||
			( quiz_option[ idx ][ 2 ] == quiz_option[ idx ][ 0 ] ) ||
			( quiz_option[ idx ][ 1 ] == quiz_option[ idx ][ 0 ] )
			);

		engine_font_manager_data( quiz_select[ idx ], x + 32, y );
		if( tst )
		{
			engine_font_manager_text( "YES", x + 34, y );
		}
		else
		{
			engine_font_manager_text( "no.", x + 30, y );
		}

		y++;
	}
}

void engine_quiz_manager_draw_riffs()
{
	unsigned char idx, lop;
	unsigned char ans, bob;
	unsigned char x, y, z;

	x = 0;
	y = 0;
	for( idx = 0; idx < 25; idx++ )
	{
		engine_font_manager_data( ( idx + 1 ), x + 0, y );
		ans = quiz_answer[ idx ];
		engine_font_manager_data( ans, x + 5, y );

		z = 0;
		for( lop = 0; lop < MAX_RIFFS; lop++ )
		{
			bob = quiz_answer[ lop ];
			if( ans == bob )
			{
				z++;
			}
		}

		engine_font_manager_data( z, x + 10, y );
		y++;
	}

	x = 20;
	y = 0;
	for( idx = 25; idx < 50; idx++ )
	{
		engine_font_manager_data( ( idx + 1 ), x + 0, y );
		ans = quiz_answer[ idx ];
		engine_font_manager_data( ans, x + 5, y );

		z = 0;
		for( lop = 0; lop < MAX_RIFFS; lop++ )
		{
			bob = quiz_answer[ lop ];
			if( ans == bob )
			{
				z++;
			}
		}

		engine_font_manager_data( z, x + 10, y );
		y++;
	}
}



// Normal.
void engine_quiz_manager_load_normal()
{
	unsigned char idx, opt;
	for( idx = 0; idx < MAX_RIFFS; idx++ )
	{
		quiz_answer[ idx ] = music_riffs[ idx ];
		for( opt = 0; opt < MAX_OPTION; opt++ )
		{
			//quiz_option[ idx ][ opt ] = opt;
			quiz_option[ idx ][ opt ] = music_riffs[ opt ];
		}
	}
}