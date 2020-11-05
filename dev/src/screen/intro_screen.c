#include "intro_screen.h"
#include "enum_manager.h"
#include "image_manager.h"
#include "gfx.h"

void screen_intro_screen_load()
{
	engine_image_manager_draw( gfx_banner, PAL1, 1, 0, 0 );
	engine_image_manager_draw( gfx_eddie_04, PAL2, 240, 20, 6 );

	//u16 *data01 = NULL;
	//u16 *data02 = NULL;
	////const Image image = gfx_eddie_09;
	////const Image image = vanhalen;

	//Image image01 = gfx_banner;
	//Image image02 = gfx_eddie_04;

	//if( NULL != image01.palette )
	//{
	//	data01 = image01.palette->data;
	//}

	//VDP_setPalette( PAL1, data01 );
	//VDP_drawImageEx( BG_A, &image01, TILE_ATTR_FULL( PAL1, 0, 0, 0, 1 ), 0, 0, 0, CPU );


	//if( NULL != image02.palette )
	//{
	//	data02 = image02.palette->data;
	//}

	//VDP_setPalette( PAL2, data02 );
	//VDP_drawImageEx( BG_A, &image02, TILE_ATTR_FULL( PAL2, 0, 0, 0, 240 ), 20, 6, 0, CPU );
}

void screen_intro_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_intro;
}
