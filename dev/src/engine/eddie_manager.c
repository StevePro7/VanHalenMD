#include "eddie_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "global_manager.h"
#include "random_manager.h"

// Global variables.
struct_eddie_object global_eddie_object;

void engine_eddie_manager_init()
{
	struct_eddie_object *eo = &global_eddie_object;
	unsigned char idx;

	eo->eddie_index = 0;
	eo->eddie_final = 0;
	for( idx = 0; idx < EDDIE_IMAGES; idx++ )
	{
		eo->eddie_images[ idx ] = INVALID_INDEX;
	}
}

unsigned char engine_eddie_manager_next()
{
	struct_eddie_object *eo = &global_eddie_object;
	unsigned char eddie_image = 0;

	while( 1 )
	{
		eddie_image = engine_random_manager_data( ( MAX_EDDIES - 1 ) );
		if(
			( eddie_image != eo->eddie_final ) &&
			( eddie_image != eo->eddie_images[ 0 ] ) &&
			( eddie_image != eo->eddie_images[ 1 ] ) &&
			( eddie_image != eo->eddie_images[ 2 ] ) &&
			( eddie_image != eo->eddie_images[ 3 ] ) &&
			( eddie_image != eo->eddie_images[ 4 ] ) &&
			( eddie_image != eo->eddie_images[ 5 ] ) &&
			( eddie_image != eo->eddie_images[ 6 ] ) &&
			( eddie_image != eo->eddie_images[ 7 ] ) &&
			( eddie_image != eo->eddie_images[ 8 ] ) &&
			( eddie_image != eo->eddie_images[ 9 ] )
			)
		{
			eo->eddie_final = eddie_image;
			eo->eddie_images[ eo->eddie_index ] = eddie_image;
			break;
		}
	}

	eo->eddie_index++;
	if( eo->eddie_index >= EDDIE_IMAGES )
	{
		eo->eddie_index = 0;
	}

	return eddie_image;
}

void engine_eddie_manager_set_eddie_final( unsigned char eddie_image )
{
	struct_eddie_object *eo = &global_eddie_object;
	eo->eddie_final = eddie_image;
}