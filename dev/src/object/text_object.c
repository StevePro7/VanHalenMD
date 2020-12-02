#include "text_object.h"

// Global variable.
// TODO set maximum once established
const struct_text_object global_text_object[ 39 ] =
{
	// Riff screen.
	{ 1, 7, "Pick how many riffs" },
	{ 1, 8, "Eddie should shred:" },

	// Difficulty screen.
	{ 1, 7, "Select option mixup" },
	{ 1, 8, "foreach riff played" },

	// Ready screen.
	{ 1, 25, "Button [ A ]" },
	{ 1, 26, "Button [ B ]" },
	{ 1, 27, "Button [ C ]" },
	{ 14, 25, "Select" },
	{ 14, 26, "Census" },
	{ 14, 27, "Replay" },
	//{ 1, 21, "Button [ A ]" },
	//{ 1, 22, "Button [ B ]" },
	//{ 1, 23, "Button [ C ]" },
	//{ 14, 21, "Select" },
	//{ 14, 22, "Census" },
	//{ 14, 23, "Replay" },

	// Summary screen.
	{ 2, 10, "Riffs Total" },
	{ 2, 14, "Riffs Solved" },
	{ 2, 18, "Riffs Correct" },
	{ 2, 22, "Riffs Percent" },
	//{ 1, 26, "Button [ A ]" },
	//{ 1, 27, "Button [ B ]" },
	{ 16, 26, "Quit" },
	{ 16, 27, "Back" },
	{ 1, 26, "Thanks for playing!" },
	{ 3, 27, "StevePro Studios" },

	// Begin screen.
	{ 3, 24, "Eddie Van Halen is widely regarded as" },
	{ 3, 25, "one of the greatest guitarists of all" },
	{ 3, 26, "time." },
	{ 3, 27, "" },
	{ 3, 24, "His innovations revolutionized guitar" },
	{ 3, 25, "playing and he influenced generations" },
	{ 3, 26, "of guitarists." },
	{ 3, 27, "" },
	{ 2, 24, "  Eddie is responsible for some of the" },
	{ 2, 25, "most memorable riffs ever and his band" },
	{ 2, 26, "remains one of the world's top selling" },
	{ 2, 27, "artists." },

	// Title screen.
	{ 1, 11, "Theres only one way" },
	{ 1, 12, "to rock Vintage Van" },
	{ 1, 13, "Halen celebrates 40" },
	{ 1, 14, "awesome riffs shred" },
	{ 1, 15, "by Eddie Van Halen." },
	{ 1, 18, "Built with the SGDK" },
	{ 1, 19, "Special thanks goes" },
	{ 1, 20, "to the MegaDriveDev" },
	{ 1, 21, "Suzanne and Adriana" },

	// OLD Title screen - too wide
	//{ 0, 11, "There's only one way" },
	//{ 0, 12, "to rock! Vintage Van" },
	//{ 0, 13, "Halen celebrates 40x" },
	//{ 0, 14, "awesome riffs played" },
	//{ 0, 15, "by Eddie Van Halen." },
};

// Riff Screen.
//const struct_text_object riff_text_object[ MAX_MENUS ] =
//{
//	{ 1, 7, "Pick how many riffs" },
//	{ 1, 8, "Eddie should shred:" },
//};
const unsigned char riff_yPos[ MAX_OPTION ] = { 12, 16, 20, 24 };
const char *riff_line1[ MAX_OPTION ] =
{
	"05 Awesome riffs",
	"10 Awesome riffs",
	"20 Awesome riffs",
	"40 Awesome riffs",
};
const char *riff_line2[ MAX_OPTION ] =
{
	"   Blast 'em out",
	"   Rock 'n roll.",
	"   Nonstop Eddie",
	"   EVH marathon!",
};

// Difficulty Screen.
//const struct_text_object diff_text_object[ MAX_MENUS ] =
//{
//	{ 1, 7, "Select option mixup" },
//	{ 1, 8, "foreach riff played" },
//};
const unsigned char diff_yPos[ MAX_MENUS ] = { 12, 16 };
const char *diff_line1[ MAX_MENUS ] =
{
	"Easy   [ mixup ]",
	"Hard   [ mixup ]",
};
const char *diff_line2[ MAX_MENUS ] =
{
	"",
	"",
};
const char *diff_line3[ MAX_MENUS ] =
{
	"Each riff option is",
	"Each riff option is",
};
const char *diff_line4[ MAX_MENUS ] =
{
	"from the same album",
	"from various albums",
};
