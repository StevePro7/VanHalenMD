#include "audio_manager.h"

// Global variables.
struct_audio_object global_audio_object;

void engine_audio_manager_init()
{
	struct_audio_object *ao = &global_audio_object;
	ao->data = 17;
}

int engine_audio_manager_test()
{
	struct_audio_object *ao = &global_audio_object;
	return ao->data;
}