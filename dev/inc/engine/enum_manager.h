#ifndef __ENUM_MANAGER__
#define __ENUM_MANAGER__

typedef enum tag_enum_screen_type
{
	screen_type_none = 0,
	screen_type_splash = 1,
	screen_type_intro = 2,
	screen_type_begin = 3,
	screen_type_title = 4,
	screen_type_riff = 5,
	screen_type_diff = 6,
	screen_type_ready = 7,
	screen_type_init = 8,
	screen_type_load = 9,
	screen_type_part = 10,
	screen_type_play = 11,
	screen_type_quiz = 12,
	screen_type_score = 13,
	screen_type_over = 14,
	screen_type_test = 15,
	screen_type_func = 16,

} enum_screen_type;

typedef enum tag_enum_sprite_type
{
	sprite_type_actor = 0,
	sprite_type_chose = 1,
	sprite_type_right = 2,
	sprite_type_wrong = 3,

} enum_sprite_type;

typedef enum tag_enum_difficulty_type
{
	difficulty_type_easy = 0,
	difficulty_type_hard = 1,

} enum_difficulty_type;

typedef enum tag_enum_cursor_type
{
	cursor_type_small = 0,
	cursor_type_large = 1,

} enum_cursor_type;

typedef enum tag_enum_movement_type
{
	movement_type_up = 0,
	movement_type_down = 1,

} enum_movement_type;

typedef enum tag_enum_horizontal_type
{
	horizontal_type_left = 0,
	horizontal_type_right = 1,

} enum_horizontal_type;

typedef enum tag_enum_stage_type
{
	event_stage_start = 0,
	event_stage_pause = 1,
	event_stage_menus = 2,

} enum_stage_type;

typedef enum tag_enum_effects_type
{
	effects_type_cheat = 0,
	effects_type_ready = 1,
	effects_type_wrong = 3,
	effects_type_right = 2,

} enum_effects_type;

#endif//__ENUM_MANAGER__
