#include "sprite_manager.h"
#include "enum_manager.h"
#include "global_manager.h"
#include "gfx.h"

#ifdef _CONSOLE
#include "_genesis.h"
#else
#include <genesis.h>
#endif

unsigned char sprite_positions[ MAX_OPTION ] = { 1 * 48, 2 * 48, 3 * 48, 4 * 48 };
static unsigned char sprite_index;

Sprite* sprites[ MAX_SPRITES ];

//static Sprite* init_sprite( const SpriteDefinition* spriteDef )
//{
//	Sprite* sprite;
//	//u16 *data = NULL;
//
//	//if( NULL != spriteDef->palette )
//	//{
//	//	data = spriteDef->palette->data;
//	//}
//
//	//VDP_setPalette( PAL3, data );
//	sprite = SPR_addSprite( spriteDef, 0, sprite_positions[ 0 ], TILE_ATTR( PAL3, 0, FALSE, FALSE ) );
//	return sprite;
//	//return SPR_addSprite( spriteDef, 0, sprite_positions[ 0 ], TILE_ATTR( PAL3, 0, FALSE, FALSE ) );
//}

//static void setPalette_sprite( unsigned char index )
//{
//	//const SpriteDefinition* spriteDef;
//	//Sprite* sprite;
//	//unsigned short *data = NULL;
//	//unsigned char idx;
//
//	//for( idx = 0; idx < MAX_SPRITES; idx++ )
//	//{
//	//	sprite = sprites[ sprite_type_actor ];
//	//	SPR_setVisibility( sprite, HIDDEN );
//	//}
//
//	//spriteDef = NULL;
//	//sprite = sprites[ index ];
//	//if( NULL != sprite && NULL != sprite->definition )
//	//{
//	//	spriteDef = sprite->definition;
//	//}
//
//	//if( NULL != spriteDef && NULL != spriteDef->palette )
//	//{
//	//	data = spriteDef->palette->data;
//	//}
//
//	//VDP_setPalette( PAL3, data );
//	//sprite = sprites[ index ];
//
//	//SPR_setVisibility( sprite, VISIBLE );
//}

void engine_sprite_manager_init()
{
	//Sprite* sprite;
	//sprites[ sprite_type_actor ] = init_sprite( &gfx_actor );
	//sprites[ sprite_type_right ] = init_sprite( &gfx_right );
	//sprites[ sprite_type_wrong ] = init_sprite( &gfx_wrong );

	//setPalette_sprite( sprite_type_actor );

	//sprite = sprites[ sprite_type_actor ];
	//SPR_setVisibility( sprite, VISIBLE );

	//const SpriteDefinition* spriteDef = &gfx_right;
	const SpriteDefinition* spriteDef = &gfx_actor;
	u16 *data = NULL;

	if( NULL != spriteDef->palette )
	{
		data = spriteDef->palette->data;
	}

	//sprite_index = 0;
	VDP_setPalette( PAL3, data );
	SPR_init( 0, 0, 0 );
	SPR_addSprite( spriteDef, 0, sprite_positions[ 3 ], TILE_ATTR( PAL3, 0, FALSE, FALSE ) );
}

void engine_sprite_manager_update()
{
	SPR_update();
}

void engine_sprite_manager_test()
{

}