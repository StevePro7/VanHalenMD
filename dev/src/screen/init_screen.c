#include "init_screen.h"
#include "eddie_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "game_manager.h"
#include "graphics_manager.h"
#include "hack_manager.h"
#include "quiz_manager.h"
#include "score_manager.h"
#include "screen_manager.h"
#include "sprite_manager.h"
#include "storage_manager.h"

void screen_init_screen_load()
{
	// Initialize + bootstrap:
	engine_eddie_manager_init();
	engine_game_manager_init();
	engine_quiz_manager_init();
	engine_score_manager_init();
	engine_sprite_manager_init();

	engine_hack_manager_init();
	engine_hack_manager_load();
	engine_storage_manager_read();
	engine_hack_manager_save();

	engine_graphics_manager_clear_full();
	//engine_font_manager_text( "INIT SCREEN  ", 10, 2 );
}

void screen_init_screen_update( unsigned char *screen_type )
{
	// From here goto : begin / intro / title / riff / load screen...
	//*screen_type = screen_type_init;
	*screen_type = screen_type_begin;
	//*screen_type = screen_type_title;
	//*screen_type = screen_type_riff;
	//*screen_type = screen_type_ready;
	//*screen_type = screen_type_load;
}