#ifndef _IMAGE_OBJECT_H_
#define _IMAGE_OBJECT_H_

#include "global_manager.h"

#ifdef _CONSOLE
#include "_genesis.h"
#else
#include <genesis.h>
#endif

//extern Image images;
extern const Image *image_eddies[ MAX_EDDIES ];

#endif//_IMAGE_OBJECT_H_