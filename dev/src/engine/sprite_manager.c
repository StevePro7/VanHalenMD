#include "sprite_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "global_manager.h"
#include "gfx.h"

#ifdef _CONSOLE
#include "_genesis.h"
#else
#include <genesis.h>
#endif

unsigned char sprite_positions[ MAX_OPTION ] = { 1 * 48, 2 * 48, 3 * 48, 4 * 48 };
//static unsigned char sprite_index;

Sprite* sprites[ MAX_SPRITES ] = { NULL, NULL, NULL };
const SpriteDefinition* spriteDefList[ MAX_SPRITES ] = { &gfx_actor, &gfx_right, &gfx_wrong };

static void init_sprite( const unsigned char index )
{
	const SpriteDefinition* spriteDef;
	u16 *data = NULL;
	spriteDef = spriteDefList[ index ];
	data = spriteDef->palette->data;
	VDP_setPalette( PAL3, data );
	sprites[ index ] = SPR_addSprite( spriteDef, 0, sprite_positions[ 0 ], TILE_ATTR( PAL3, 0, FALSE, FALSE ) );
	SPR_setVisibility( sprites[ index ], HIDDEN );
}



void engine_sprite_manager_init()
{
	//const SpriteDefinition* spriteDef;
	//u16 *data = NULL;

	//sprites[ sprite_type_actor ] = init_sprite( &gfx_actor );
	//sprites[ sprite_type_right ] = init_sprite( &gfx_right );
	//sprites[ sprite_type_wrong ] = init_sprite( &gfx_wrong );

	SPR_init( 0, 0, 0 );

	init_sprite( sprite_type_actor );
	init_sprite( sprite_type_right );
	init_sprite( sprite_type_wrong );

	//// Sprite #0
	//spriteDef = spriteDefList[ sprite_type_actor ];
	//data = spriteDef->palette->data;
	//VDP_setPalette( PAL3, data );
	//sprites[ sprite_type_actor ] = SPR_addSprite( spriteDef, 0, sprite_positions[ 0 ], TILE_ATTR( PAL3, 0, FALSE, FALSE ) );
	//SPR_setVisibility( sprites[ sprite_type_actor ], HIDDEN );
	////SPR_setVisibility( sprites[ sprite_type_actor ], VISIBLE );

	//// Sprite #1
	//spriteDef = spriteDefList[ sprite_type_right ];
	//data = spriteDef->palette->data;
	//VDP_setPalette( PAL3, data );
	//sprites[ sprite_type_right ] = SPR_addSprite( spriteDef, 0, sprite_positions[ 0 ], TILE_ATTR( PAL3, 0, FALSE, FALSE ) );
	//SPR_setVisibility( sprites[ sprite_type_right ], HIDDEN );
	////SPR_setVisibility( sprites[ sprite_type_right ], VISIBLE );

	//// Sprite #2
	//spriteDef = spriteDefList[ sprite_type_wrong ];
	//data = spriteDef->palette->data;
	//VDP_setPalette( PAL3, data );
	//sprites[ sprite_type_wrong ] = SPR_addSprite( spriteDef, 0, sprite_positions[ 0 ], TILE_ATTR( PAL3, 0, FALSE, FALSE ) );
	//SPR_setVisibility( sprites[ sprite_type_wrong ], HIDDEN );
	////SPR_setVisibility( sprites[ sprite_type_wrong ], VISIBLE );

	////sprite_index = 0;
}
/*
void engine_sprite_manager_init()
{
	const SpriteDefinition* spriteDef2;
	//Sprite* sprite2;

	//Sprite* sprite;
	//sprites[ sprite_type_actor ] = init_sprite( &gfx_actor );
	//sprites[ sprite_type_right ] = init_sprite( &gfx_right );
	//sprites[ sprite_type_wrong ] = init_sprite( &gfx_wrong );

	SPR_init( 0, 0, 0 );
	//setPalette_sprite( sprite_type_actor );


	//sprite = sprites[ sprite_type_actor ];
	//SPR_setVisibility( sprite, VISIBLE );


	//const SpriteDefinition* spriteDef = &gfx_right;
	//const SpriteDefinition* spriteDef = &gfx_actor;
	u16 *data = NULL;
	//if( NULL != spriteDef->palette )
	//{
	//	data = spriteDef->palette->data;
	//}


	//sprite2 = sprites[ 0 ];
	//spriteDef2 = sprite2->definition;
	spriteDef2 = spriteDefList[ 2 ];
	if( NULL == spriteDef2 )
	{
		engine_font_manager_text( "THERE", 2, 20 );
	}
	//engine_font_manager_text( "WORLD", 2, 21 );

	data = spriteDef2->palette->data;
	VDP_setPalette( PAL3, data );

	//VDP_setPalette( PAL3, data );
	//SPR_addSprite( spriteDef, 0, sprite_positions[ 2 ], TILE_ATTR( PAL3, 0, FALSE, FALSE ) );
	SPR_addSprite( spriteDef2, 0, sprite_positions[ 2 ], TILE_ATTR( PAL3, 0, FALSE, FALSE ) );

	////sprite_index = 0;
}
*/
void engine_sprite_manager_update()
{
	SPR_update();
}

void engine_sprite_manager_test0()
{
	// Sprite #0
	const SpriteDefinition* spriteDef;
	u16 *data = NULL;
	spriteDef = spriteDefList[ sprite_type_actor ];
	data = spriteDef->palette->data;
	VDP_setPalette( PAL3, data );
	SPR_setVisibility( sprites[ sprite_type_actor ], HIDDEN );
	SPR_setVisibility( sprites[ sprite_type_right ], HIDDEN );
	SPR_setVisibility( sprites[ sprite_type_wrong ], HIDDEN );
	SPR_setVisibility( sprites[ sprite_type_actor ], VISIBLE );
}

void engine_sprite_manager_test1()
{
	// Sprite #1
	const SpriteDefinition* spriteDef;
	u16 *data = NULL;
	spriteDef = spriteDefList[ sprite_type_right ];
	data = spriteDef->palette->data;
	VDP_setPalette( PAL3, data );
	SPR_setVisibility( sprites[ sprite_type_actor ], HIDDEN );
	SPR_setVisibility( sprites[ sprite_type_right ], HIDDEN );
	SPR_setVisibility( sprites[ sprite_type_wrong ], HIDDEN );
	SPR_setVisibility( sprites[ sprite_type_right ], VISIBLE );
}

void engine_sprite_manager_test2()
{
	// Sprite #2
	const SpriteDefinition* spriteDef;
	u16 *data = NULL;
	spriteDef = spriteDefList[ sprite_type_wrong ];
	data = spriteDef->palette->data;
	VDP_setPalette( PAL3, data );
	SPR_setVisibility( sprites[ sprite_type_actor ], HIDDEN );
	SPR_setVisibility( sprites[ sprite_type_right ], HIDDEN );
	SPR_setVisibility( sprites[ sprite_type_wrong ], HIDDEN );
	SPR_setVisibility( sprites[ sprite_type_wrong ], VISIBLE );
}