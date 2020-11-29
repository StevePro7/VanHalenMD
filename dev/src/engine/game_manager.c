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
	go->game_localcheat = 0;
	go->game_completion = 0;
}

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

void engine_game_manager_set_local_cheat( unsigned char cheat )
{
	struct_game_object *go = &global_game_object;
	go->game_localcheat = cheat;
}

void engine_game_manager_set_game_finish( unsigned char ended )
{
	struct_game_object *go = &global_game_object;
	go->game_completion = ended;
}