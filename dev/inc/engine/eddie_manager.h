#ifndef __EDDIE_MANAGER_H__
#define __EDDIE_MANAGER_H__

#include "eddie_object.h"

// Global variables.
extern struct_eddie_object global_eddie_object;

void engine_eddie_manager_init();
unsigned char engine_eddie_manager_next();
void engine_eddie_manager_set_eddie_image( unsigned char index, unsigned char eddie_image );

#endif//__EDDIE_MANAGER_H__