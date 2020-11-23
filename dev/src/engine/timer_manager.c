#include "timer_manager.h"
#include "global_manager.h"
#include "hack_manager.h"

// Global variables.
struct_delay_object global_delay_object;
//struct_frame_object global_frame_object;

// Delay Manager.
void engine_delay_manager_load( unsigned int delay )
{
	struct_delay_object *dObj = &global_delay_object;
	struct_hack_object *ho = &global_hack_object;
	dObj->delay_value = delay;
	dObj->delay_timer = 0;

	// Used for testing so no wait.
	if( ho->hack_delayspeed )
	{
		dObj->delay_value = 0;
	}
}
unsigned char engine_delay_manager_update()
{
	struct_delay_object *dObj = &global_delay_object;
	unsigned char test;

	dObj->delay_timer++;
	test = dObj->delay_timer >= dObj->delay_value;
	if( test )
	{
		dObj->delay_timer = 0;
	}

	return test;
}

// Frame Manager.
//void engine_frame_manager_load( unsigned int timer )
//{
//	struct_frame_object *fo = &global_frame_object;
//	fo->frame_count = 0;
//	fo->frame_timer = timer;
//}
//void engine_frame_manager_update()
//{
//	struct_frame_object *fo = &global_frame_object;
//	fo->frame_count++;
//	if( fo->frame_count >= MAX_INT_VALUE )
//	{
//		fo->frame_count = 0;
//	}
//}