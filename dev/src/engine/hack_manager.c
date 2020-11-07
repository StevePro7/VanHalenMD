#include "hack_manager.h"
#include "enum_manager.h"

// Global variable.
struct_hack_object global_hack_object;

#define PEEK( addr)			(* ( unsigned char *)( addr ) )
#define POKE( addr, data )	(* ( unsigned char *)( addr ) = ( data ) )

#define HACKER_START		0x0050

void engine_hack_manager_init()
{
	//struct_hack_object *ho = &global_hack_object;

	//ho->hack_object_random = random_type_diff;
	//ho->hack_object_random = random_type_same;
}