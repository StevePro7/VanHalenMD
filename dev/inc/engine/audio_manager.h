#ifndef __AUDIO_MANAGER__
#define __AUDIO_MANAGER__

#include "audio_object.h"

void engine_audio_manager_init();
int engine_audio_manager_test();

// Global variables.
extern struct_audio_object global_audio_object;

#endif//__AUDIO_MANAGER__