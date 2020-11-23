#ifndef __TIMER_MANAGER_H__
#define __TIMER_MANAGER_H__

#include "timer_object.h"

// Global variables.
extern struct_delay_object global_delay_object;
//extern struct_frame_object global_frame_object;

// Delay Manager.
void engine_delay_manager_load( unsigned int delay );
unsigned char engine_delay_manager_update();
//void engine_delay_manager_draw();

// Frame Manager.
//void engine_frame_manager_load( unsigned int timer );
//void engine_frame_manager_update();

#endif//__TIMER_MANAGER_H__