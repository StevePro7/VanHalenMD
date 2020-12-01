#include "begin_screen.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "graphics_manager.h"
#include "image_manager.h"
#include "input_manager.h"
#include "locale_manager.h"
#include "text_manager.h"
#include "timer_manager.h"

void screen_begin_screen_load()
{
	engine_graphics_manager_clear_full();
}

void screen_begin_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_begin;
}
