#include "over_screen.h"
#include "audio_manager.h"
#include "cursor_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "game_manager.h"
#include "hack_manager.h"
#include "graphics_manager.h"
#include "input_manager.h"
#include "locale_manager.h"
#include "quiz_manager.h"
#include "score_manager.h"
#include "sprite_manager.h"
#include "text_manager.h"
#include "timer_manager.h"

#define SCORE_FLASH_DELAY		25

static void flash_score();
static unsigned char flash_count;

void screen_over_screen_load()
{
	struct_quiz_object *qo = &global_quiz_object;

	engine_cursor_manager_hide();
	engine_graphics_manager_clear_half();

	engine_font_manager_text( LOCALE_SUMMARY_OVER, 1, 7 );
	engine_text_manager_draw_lines( 10, 4 );
	engine_text_manager_draw_lines( 16, 2 );
	//engine_text_manager_draw_lines( 4, 4 );
	//engine_text_manager_draw_lines( 12, 2 );
	engine_score_manager_draw_summary( qo->quiz_riffs_play );

	engine_delay_manager_load( SCORE_FLASH_DELAY );
	engine_audio_manager_stop();

	//flash_score();
	flash_count = 0;
}

void screen_over_screen_update( unsigned char *screen_type )
{
	struct_score_object *so = &global_socre_object;
	struct_hack_object *ho = &global_hack_object;
	unsigned char delay;
	unsigned char input;

	if( 0 != so->score_answerd && so->score_correct == so->score_answerd )
	{
		delay = engine_delay_manager_update();
		if( delay )
		{
			if( !ho->hack_delayspeed )
			{
				flash_count = 1 - flash_count;
			}

			if( flash_count )
			{
				engine_font_manager_text( LOCALE_OVER_PERFECT, 16, 23 );
			}
			else
			{
				flash_score();
			}
		}
	}

	input = engine_input_manager_hold_buttonA();
	if( input )
	{
		*screen_type = screen_type_title;
		return;
	}

	engine_sprite_manager_update();
	*screen_type = screen_type_over;
}

static void flash_score()
{
	struct_game_object *go = &global_game_object;
	struct_score_object *so = &global_socre_object;
	if( go->game_completion )
	{
		if( 0 != so->score_answerd && so->score_correct == so->score_answerd )
		{
			engine_text_manager_draw_lines_palette( LOCALE_OVER_PERFECT, 16, 23 );
		}
	}
}