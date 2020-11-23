#include "audio_manager.h"
#include "global_manager.h"
#include "audio_object.h"

#ifdef _CONSOLE
#include "_genesis.h"
#else
#include <genesis.h>
#endif

void engine_audio_manager_init()
{
	unsigned char idx;
	const unsigned char *audio;
	unsigned int sized;

	// Initialize riffs.
	for( idx = 0; idx < MAX_RIFFS; idx++ )
	{
		audio = audio_riff[ idx ];
		sized = audio_riff_size[ idx ];
		SND_setPCM_XGM( SFX_RIFF_START + idx, audio, sized );
	}

	// Initialize effects.
	for( idx = 0; idx < MAX_EFFECTS; idx++ )
	{
		audio = audio_effect[ idx ];
		sized = audio_effect_size[ idx ];
		SND_setPCM_XGM( SFX_EFFECT_START + idx, audio, sized );
	}
}

void engine_audio_manager_play_riff( unsigned char index )
{
	XGM_startPlayPCM( SFX_RIFF_START + index, 1, SOUND_PCM_CH1 );
}

void engine_audio_manager_play_effect( unsigned char index )
{
	XGM_startPlayPCM( SFX_EFFECT_START + index, 1, SOUND_PCM_CH2 );
}