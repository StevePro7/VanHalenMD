#include "music_manager.h"
#include "font_manager.h"
#include "global_manager.h"
#include "music_object.h"

void engine_music_manager_test()
{
	//unsigned char value = music_total[ MAX_ALBUMS - 1 ];
	unsigned char value = music_riffs[ MAX_RIFFS - 1 ];
	engine_font_manager_data( value, 10, 10 );

	//const char *str = music_album[ MAX_ALBUMS - 1 ];
	//const char *str = music_songs[ 10 ];
	//engine_font_manager_text( str, 10, 10 );
}

//unsigned char engine_music_manager_riff( unsigned char idx )
//{
//	return music_riffs[ idx ];
//}