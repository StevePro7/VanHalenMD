#include "play_screen.h"
#include "data_manager.h"
#include "enum_manager.h"

void screen_play_screen_load()
{
	engine_data_manager_test();
}

void screen_play_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_play;
}