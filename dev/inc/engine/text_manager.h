#ifndef __TEXT_MANAGER_H__
#define __TEXT_MANAGER_H__

#include "text_object.h"

void engine_text_manager_draw_lines( unsigned char start, unsigned char lines );
void engine_text_manager_draw_lines_extra( unsigned char start, unsigned char lines, signed char deltaY );

#endif//__TEXT_MANAGER_H__
