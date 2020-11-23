#include "quiz_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "function_manager.h"
#include "global_manager.h"
#include "random_manager.h"
#include "music_object.h"

#ifdef _CONSOLE
#include <string.h>
#include "_genesis.h"
#else
#include <genesis.h>
#endif

// Global variables.
struct_quiz_object global_quiz_object;

static void reset_quiz();
static void random_options(const char default_option );

void engine_quiz_manager_init()
{
	struct_quiz_object *qo = &global_quiz_object;
	qo->quiz_riffs_play = quiz_number[ 0 ];
	qo->quiz_difficulty = difficulty_type_easy;
	qo->quiz_riff_index = 0;
	qo->quiz_selections = 0;

	reset_quiz();
	//for( idx = 0; idx < MAX_RIFFS; idx++ )
	//{
	//	quiz_answer[ idx ] = 0;
	//	for( opt = 0; opt < MAX_OPTION; opt++ )
	//	{
	//		quiz_option[ idx ][ opt ] = 0;
	//	}
	//}
}

void engine_quiz_manager_load_random()
{
	unsigned char idx;
	unsigned char rnd;

	reset_quiz();
	for( idx = 0; idx < MAX_RIFFS; idx++ )
	{
		while( 1 )
		{
			rnd = engine_random_manager_data( MAX_RIFFS );
			if( 0 == quiz_answer[ rnd ] )
			{
				quiz_saving[ rnd ] = idx;
				quiz_answer[ rnd ] = music_riffs[ idx ];
				break;
			}
		}
	}

	// Must iterate and randomize all the riffs before randomize options!
	random_options( INVALID_INDEX );

	// TODO delete
	//quiz_option[ 0 ][ 0 ] = 0x03;
	//quiz_option[ 0 ][ 1 ] = 0x05;
	//quiz_option[ 0 ][ 2 ] = 0x04;
	//quiz_option[ 0 ][ 3 ] = 0x07;

	//quiz_answer[ 0 ] = 0x05;
	//quiz_select[ 0 ] = 1;
	//quiz_saving[ 0 ] = 3;

	//quiz_option[ 0 ][ 0 ] = 0x86;
	//quiz_option[ 0 ][ 1 ] = 0x50;
	//quiz_option[ 0 ][ 2 ] = 0x67;
	//quiz_option[ 0 ][ 3 ] = 0xA9;
}

void engine_quiz_manager_load_mixing()
{
	unsigned char idx;

	reset_quiz();
	for( idx = 0; idx < MAX_RIFFS; idx++ )
	{
		quiz_saving[ idx ] = idx;
		quiz_answer[ idx ] = music_riffs[ idx ];
	}

	// Must iterate and randomize all the riffs before randomize options!
	random_options( INVALID_INDEX );
}

void engine_quiz_manager_load_normal()
{
	unsigned char idx;
	const unsigned char default_option = 0;		// TODO do I want default_option to be from hack mgr?

	reset_quiz();
	for( idx = 0; idx < MAX_RIFFS; idx++ )
	{
		quiz_saving[ idx ] = idx;
		quiz_answer[ idx ] = music_riffs[ idx ];
	}

	// Must iterate and randomize all the riffs before randomize options!
	random_options( default_option );
}
//
//void engine_quiz_manager_cheat()
//{
//	// TODO replace magic numbers for X + Y.
//	struct_quiz_object *qo = &global_quiz_object;
//
//	engine_font_manager_data( quiz_select[ qo->quiz_riff_index ], 15, 27 );
//	//engine_font_manager_data( qo->quiz_riff_index + 1, 10, 4 );
//	engine_font_manager_data( qo->quiz_riff_index + 0, 10, 4 );
//	engine_font_manager_data( qo->quiz_riffs_play, 16, 4 );
//}
//

void engine_quiz_manager_riff()
{
	struct_quiz_object *qo = &global_quiz_object;
	unsigned char index = qo->quiz_riff_index;
	unsigned char opt;
	unsigned char total;
	unsigned short length;

	unsigned char album, songs, riff;
	const char *years;
	const char *title1, *title2;
	const char *music1, *music2;

	for( opt = 0; opt < MAX_OPTION; opt++ )
	{
		riff = quiz_option[ index ][ opt ];
		album = 0;
		songs = 0;
		engine_function_manager_convertByteToNibbles( riff, &album, &songs );

		years = music_years[ album ];
		title1 = music_album1[ album ];
		title2 = music_album2[ album ];

		total = music_total[ album ];
		total += songs;
		music1 = music_songs1[ total ];
		music2 = music_songs2[ total ];

		quiz_years[ opt ] = years;
		quiz_line1[ opt ] = title1;
		length = strlen( title2 );
		if( 0 == length )
		{
			quiz_line2[ opt ] = music1;
			quiz_line3[ opt ] = music2;
			quiz_line4[ opt ] = "";
		}
		else
		{
			quiz_line2[ opt ] = title2;
			quiz_line3[ opt ] = music1;
			quiz_line4[ opt ] = music2;
		}
	}
}

void engine_quiz_manager_draw()
{
	// TODO replace hard coded co-ordinates.
	struct_quiz_object *qo = &global_quiz_object;
	engine_font_manager_zero( qo->quiz_riff_index + 1, 10, BANNER_Y );
	engine_font_manager_zero( qo->quiz_riffs_play, 13, BANNER_Y );
}


unsigned char engine_quiz_manager_increment( unsigned char quiz_selection )
{
	struct_quiz_object *qo = &global_quiz_object;
	qo->quiz_riff_index++;
	qo->quiz_selections = quiz_selection;

	return qo->quiz_riff_index >= qo->quiz_riffs_play;
}
//void engine_quiz_manager_decrement( unsigned char quiz_selection )
//{
//	struct_quiz_object *qo = &global_quiz_object;
//	qo->quiz_riff_index--;
//	qo->quiz_selections = quiz_selection;
//}
//
//void engine_quiz_manager_load_testing()
//{
//	// 0x01		1-1
//	// 0x22		2-1
//	// 0x01		1-2
//	// 0x87		2-2
	//quiz_option[ 0 ][ 0 ] = 0x01;
	//quiz_option[ 0 ][ 1 ] = 0x87;
	//quiz_option[ 0 ][ 2 ] = 0x02;
	//quiz_option[ 0 ][ 3 ] = 0x03;
//
//	quiz_option[ 1 ][ 0 ] = 0x87;
//	quiz_option[ 1 ][ 1 ] = 0x87;
//	quiz_option[ 1 ][ 2 ] = 0x12;
//	quiz_option[ 1 ][ 3 ] = 0x13;
//
//	quiz_option[ 2 ][ 0 ] = 0x01;
//	quiz_option[ 2 ][ 1 ] = 0x11;
//	quiz_option[ 2 ][ 2 ] = 0x12;
//	quiz_option[ 2 ][ 3 ] = 0x13;
//
//	quiz_option[ 3 ][ 0 ] = 0x87;
//	quiz_option[ 3 ][ 1 ] = 0x11;
//	quiz_option[ 3 ][ 2 ] = 0x12;
//	quiz_option[ 3 ][ 3 ] = 0x13;
//}

void engine_quiz_manager_reset()
{
	struct_quiz_object *qo = &global_quiz_object;
	qo->quiz_riff_index = 0;
	qo->quiz_selections = 0;
}
void engine_quiz_manager_set_riffs_play( unsigned char index )
{
	struct_quiz_object *qo = &global_quiz_object;
	qo->quiz_riffs_play = quiz_number[ index ];
}
void engine_quiz_manager_set_difficulty( unsigned char index )
{
	struct_quiz_object *qo = &global_quiz_object;
	qo->quiz_difficulty = index;
}

static void reset_quiz()
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

static void random_options(const char default_option )
{
	struct_quiz_object *qo = &global_quiz_object;
	unsigned char idx;
	unsigned char opt;
	unsigned char ans;
	unsigned char riff;

	unsigned char album, songs;
	unsigned char count;

	// Must iterate and randomize all the riffs before randomize options!
	for( idx = 0; idx < MAX_RIFFS; idx++ )
	{
		riff = quiz_answer[ idx ];
		album = 0;
		songs = 0;
		engine_function_manager_convertByteToNibbles( riff, &album, &songs );

		// Randomize correct answer first.
		ans = engine_random_manager_data( MAX_OPTION );
		if( INVALID_INDEX != default_option )
		{
			ans = default_option;
		}

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
				if( difficulty_type_hard == qo->quiz_difficulty )
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