#include "part_screen.h"
#include "audio_manager.h"
#include "eddie_manager.h"
#include "enum_manager.h"
#include "graphics_manager.h"
#include "image_manager.h"
#include "quiz_manager.h"
#include "sprite_manager.h"
#include "storage_manager.h"

void screen_part_screen_load()
{
	struct_quiz_object *qo = &global_quiz_object;
	unsigned char eddie_image;
	unsigned char riff_index;
	unsigned char save_index;

	riff_index = qo->quiz_riff_index;
	save_index = quiz_saving[ riff_index ];
	//eddie_image = engine_eddie_manager_next();
	if( 0 == riff_index )
	{
		eddie_image = 5;
	}
	else if( 1 == riff_index )
	{
		eddie_image = 2;
	}
	else if( 2 == riff_index )
	{
		//eddie_image = 4;
		eddie_image = 6;
	}
	else if( 3 == riff_index )
	{
		eddie_image = 8;
	}
	else if( 4 == riff_index )
	{
		eddie_image = 1;
	}


	engine_graphics_manager_clear_area();
	engine_image_manager_draw_eddie( eddie_image, 20, 6 );

	// Store latest Eddie for riff.
	engine_storage_manager_write();

	engine_quiz_manager_draw();
	engine_quiz_manager_riff();

	
	engine_audio_manager_play_riff( save_index );
}

void screen_part_screen_update( unsigned char *screen_type )
{
	engine_sprite_manager_update();
	*screen_type = screen_type_play;
}
