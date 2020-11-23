#include "banner_manager.h"
#include "font_manager.h"
#include "global_manager.h"
#include "locale_manager.h"

void engine_banner_manager_stats()
{
	// TODO replace hard coded co-ordinates.
	//engine_font_manager_text( "Riff 01/05  Score 00    OK 100%", 5, 3 );		// TODO delete!!
	engine_font_manager_text( LOCALE_RIFF_TEXT, 5, BANNER_Y );
	engine_font_manager_text( LOCALE_SCORE_TEXT, 17, BANNER_Y );
	engine_font_manager_text( LOCALE_OKAY_TEXT, 29, BANNER_Y );

	engine_font_manager_text( LOCALE_FSLASH_SYM, 12, BANNER_Y );
	engine_font_manager_text( LOCALE_PERCENT_SYM, 35, BANNER_Y );
}
