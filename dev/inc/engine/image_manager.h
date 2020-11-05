#ifndef _IMAGE_MANAGER_H_
#define _IMAGE_MANAGER_H_

#ifdef _CONSOLE
#include "_genesis.h"
#else
#include <genesis.h>
#endif

void engine_image_manager_draw( Image image, unsigned char palette, unsigned char index, unsigned char x, unsigned char y );

#endif//_IMAGE_MANAGER_H_