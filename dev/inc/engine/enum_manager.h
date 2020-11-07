#ifndef __ENUM_MANAGER__
#define __ENUM_MANAGER__

typedef enum tag_enum_screen_type
{
	screen_type_none = 0,
	screen_type_splash = 1,
	screen_type_begin = 2,
	screen_type_intro = 3,
	screen_type_play = 4,
	screen_type_quiz = 5,
	screen_type_test = 6,

} enum_screen_type;

typedef enum tag_enum_sprite_type
{
	sprite_type_actor = 0,
	sprite_type_right = 1,
	sprite_type_wrong = 2,

} enum_sprite_type;

//typedef enum tag_enum_random_type
//{
//	random_type_diff = 0,	// easy
//	random_type_same = 1,	// hard
//
//} enum_random_type;

typedef enum tag_enum_difficulty_type
{
	random_difficulty_easy = 0,
	random_difficulty_hard = 1,

} enum_random_type;

/*
typedef enum tag_enum_album_type
{
album_1978 = 0,		// Van Halen
album_1979 = 1,		// Van Halen II
album_1980 = 2,		// Women and Children First
album_1981 = 3,		// Fair Warning
album_1982 = 4,		// Diver Down
album_1984 = 5,		// 1984
album_1986 = 6,		// 5150
album_1988 = 7,		// OU812
album_1991 = 8,		// For Unlawful Carnal Knowledge
album_1995 = 9,		// Balance
album_1998 = 10,	// Van Halen III
album_2012 = 11,	// A Different Kind of Truth

} enum_album_type;
*/

#endif//__ENUM_MANAGER__
