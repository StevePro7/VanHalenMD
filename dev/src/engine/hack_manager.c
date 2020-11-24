#include "hack_manager.h"

// Global variable.
struct_hack_object global_hack_object;

void engine_hack_manager_init()
{
	struct_hack_object *ho = &global_hack_object;
	ho->hack_delayspeed = 1;
	ho->hack_delayspeed = 0;
}

void engine_hack_manager_invert()
{
}