#include "splash_screen.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "gfx.h"
//#include <stdlib.h>

//#ifdef _CONSOLE
//#include "_genesis.h"
//#else
//#include <genesis.h>
//#endif

void screen_splash_screen_load()
{
	unsigned short *data = NULL;
	//Image image = gfx_splash;

	if( NULL != gfx_splash.palette )
	{
		data = gfx_splash.palette->data;
	}

	VDP_setPalette( PAL1, data );
	VDP_drawImageEx( BG_A, &gfx_splash, TILE_ATTR_FULL( PAL1, 0, 0, 0, 1 ), 4, 2, 0, CPU );
}

void screen_splash_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_splash;
}
