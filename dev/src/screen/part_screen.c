#include "part_screen.h"
#include "eddie_manager.h"
#include "debug_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "graphics_manager.h"
#include "image_manager.h"
#include "quiz_manager.h"
#include "sprite_manager.h"

void screen_part_screen_load()
{
	unsigned char eddie_image;
	eddie_image = engine_eddie_manager_next();
	engine_graphics_manager_clear_area();
	engine_image_manager_draw_eddie( eddie_image, 20, 6 );

	//engine_font_manager_text( "PART SCREEN", 10, 2 );
	//engine_graphics_manager_clear_area();

	//TODO delete
	//engine_debug_manager_eddie();
	//TODO delete

	engine_quiz_manager_draw();
	engine_quiz_manager_riff();

	//TODO delete
	//engine_debug_manager_score();
	//TODO delete
	//// TODO add hack manager to check if cheat enabled
	////engine_quiz_manager_cheat();
}

void screen_part_screen_update( unsigned char *screen_type )
{
	engine_sprite_manager_update();
	//*screen_type = screen_type_part;
	*screen_type = screen_type_play;
}
