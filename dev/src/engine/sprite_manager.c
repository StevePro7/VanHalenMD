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


Sprite* sprites[ MAX_SPRITES ] = { NULL, NULL, NULL };
const SpriteDefinition* spriteDefList[ MAX_SPRITES ] = { &gfx_actor, &gfx_right, &gfx_wrong };
unsigned char sprite_positions[ MAX_OPTION ] = { 1 * 48, 2 * 48, 3 * 48, 4 * 48 };
static unsigned char sprite_position;

static void init_sprite( const unsigned char index );

void engine_sprite_manager_init()
{
	SPR_init( 0, 0, 0 );

	init_sprite( sprite_type_actor );
	init_sprite( sprite_type_right );
	init_sprite( sprite_type_wrong );

	sprite_position = 0;
}

void engine_sprite_manager_update()
{
	SPR_update();
}

void engine_sprite_manager_draw( const unsigned char index )
{
	const SpriteDefinition* spriteDef;
	unsigned short *data = NULL;
	unsigned char idx;

	for( idx = 0; idx < MAX_SPRITES; idx++ )
	{
		SPR_setVisibility( sprites[ idx ], HIDDEN );
	}

	spriteDef = spriteDefList[ index ];
	data = spriteDef->palette->data;
	VDP_setPalette( PAL3, data );
	//SPR_setVisibility( sprites[ sprite_type_actor ], HIDDEN );
	//SPR_setVisibility( sprites[ sprite_type_right ], HIDDEN );
	//SPR_setVisibility( sprites[ sprite_type_wrong ], HIDDEN );
	SPR_setVisibility( sprites[ index ], VISIBLE );
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


static void init_sprite( const unsigned char index )
{
	const SpriteDefinition* spriteDef;
	unsigned short *data = NULL;
	spriteDef = spriteDefList[ index ];

	if( NULL != spriteDef->palette )
	{
		data = spriteDef->palette->data;
	}

	VDP_setPalette( PAL3, data );
	sprites[ index ] = SPR_addSprite( spriteDef, 0, sprite_positions[ 0 ], TILE_ATTR( PAL3, 0, FALSE, FALSE ) );
	SPR_setVisibility( sprites[ index ], HIDDEN );
}