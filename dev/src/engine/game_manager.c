#include "game_manager.h"
#include "enum_manager.h"

// Global variables.
struct_game_object global_game_object;

void engine_game_manager_init()
{
	struct_game_object *go = &global_game_object;
	go->riff_selections = 0;
	go->diff_selections = difficulty_type_easy;
	//go->diff_selections = difficulty_type_hard;
}

//TODO override with the hack MGR
//void engine_game_manager_load()
//{
//}

void engine_game_manager_set_riff_select( unsigned char index )
{
	struct_game_object *go = &global_game_object;
	go->riff_selections = index;
}

void engine_game_manager_set_diff_select( unsigned char index )
{
	struct_game_object *go = &global_game_object;
	go->diff_selections = index;
}