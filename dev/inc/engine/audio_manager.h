#ifndef __AUDIO_MANAGER__
#define __AUDIO_MANAGER__

void engine_audio_manager_init();
void engine_audio_manager_play_riff( unsigned char index );
void engine_audio_manager_play_effect( unsigned char index );
void engine_audio_manager_stop();

#endif//__AUDIO_MANAGER__