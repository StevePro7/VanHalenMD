#include "score_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "global_manager.h"
#include "locale_manager.h"

#ifdef _CONSOLE
#include "_genesis.h"
#else
#include <genesis.h>
#endif

// Global variables.
struct_score_object global_socre_object;

static unsigned short calculate_percentage( unsigned short numerator, unsigned short denominator );

void engine_score_manager_init()
{
	struct_score_object *so = &global_socre_object;
	unsigned char idx;

	so->score_correct = 0;
	so->score_answerd = 0;

	for( idx = 0; idx < MAX_RIFFS; idx++ )
	{
		so->saved_correct[ idx ] = 0;
		so->saved_answerd[ idx ] = 0;
	}
}

void engine_score_manager_reset()
{
	struct_score_object *so = &global_socre_object;
	so->score_correct = 0;
	so->score_answerd = 0;
}

void engine_score_manager_update( unsigned char index, unsigned char answer )
{
	struct_score_object *so = &global_socre_object;
	if( sprite_type_right == answer )
	{
		so->score_correct++;
		so->saved_correct[ index ]++;
	}

	engine_score_manager_draw();
	so->score_answerd++;
	so->saved_answerd[ index ]++;

	// Attempt to prevent overflow!
	if( so->saved_answerd[ index ] >= MAX_INT_VALUE )
	{
		so->saved_correct[ index ] = 0;
		so->saved_answerd[ index ] = 0;
	}
}

void engine_score_manager_draw()
{
	// TODO replace hard coded co-ordinates.
	struct_score_object *so = &global_socre_object;
	engine_font_manager_zero( so->score_correct, 23, BANNER_Y );
}

void engine_score_manager_draw_percent( unsigned char index )
{
	struct_score_object *so = &global_socre_object;
	unsigned short correct = so->saved_correct[ index ];
	unsigned short answerd = so->saved_answerd[ index ];
	unsigned short percent = calculate_percentage( correct, answerd );
	engine_font_manager_data( percent, 32, BANNER_Y );
}

void engine_score_manager_draw_summary( unsigned char played )
{
	struct_score_object *so = &global_socre_object;
	unsigned char correct = so->score_correct;
	unsigned char answerd = so->score_answerd;
	unsigned short percent = calculate_percentage( correct, answerd );

	// TODO replace hard coded co-ordinates.
	engine_font_manager_zero( played, 17, 11 );
	engine_font_manager_zero( answerd, 17, 15 );
	engine_font_manager_zero( correct, 17, 19 );
	engine_font_manager_data( percent, 16, 23 );
	engine_font_manager_text( LOCALE_PERCENT_SYM, 19, 23 );
}

static unsigned short calculate_percentage( unsigned short numerator, unsigned short denominator )
{
	unsigned short percent = 0;
	if( 0 != denominator )
	{
		percent = numerator * 100 / denominator;
	}

	return percent;
}