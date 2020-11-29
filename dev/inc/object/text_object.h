#ifndef __TEXT_OBJECT_H__
#define __TEXT_OBJECT_H__

#include "global_manager.h"

typedef struct tag_struct_text_object
{
	unsigned char posX;
	unsigned char posY;
	const char *text;

} struct_text_object;

// Global variable.
extern const struct_text_object global_text_object[ 35 ];		// TODO set maximum once established

// Riff Screen.
//extern const struct_text_object riff_text_object[ MAX_MENUS ];
extern const unsigned char riff_yPos[ MAX_OPTION ];
extern const char *riff_line1[ MAX_OPTION ];
extern const char *riff_line2[ MAX_OPTION ];

// Difficulty Screen.
//extern const struct_text_object diff_text_object[ MAX_MENUS ];
extern const unsigned char diff_yPos[ MAX_MENUS ];
extern const char *diff_line1[ MAX_MENUS ];
extern const char *diff_line2[ MAX_MENUS ];
extern const char *diff_line3[ MAX_MENUS ];
extern const char *diff_line4[ MAX_MENUS ];


//extern const char *riff_line3[ MAX_OPTION ];
//extern const char *riff_line4[ MAX_OPTION ];
//

//extern unsigned char text_yPos[ 4 ];
//
//extern const char *text_options[ 4 ];
//extern const char *text_line1[ 4 ];
//extern const char *text_line2[ 4 ];
//extern const char *text_line3[ 4 ];
//extern const char *text_line4[ 4 ];
//
//extern const char *text_diff1[ 2 ];
//extern const char *text_diff2[ 2 ];
//
//extern const char *text_riff1[ 4 ];
//extern const char *text_riff2[ 4 ];
//
//extern const char *text_song1[ 4 ];
//extern const char *text_song2[ 4 ];

//extern const char *audio_years[ 4 ];
//extern const char *audio_album1[ 4 ];
//extern const char *audio_album2[ 4 ];
//extern const char *audio_songs1[ 4 ];
//extern const char *audio_songs2[ 4 ];

#endif//__TEXT_OBJECT_H__