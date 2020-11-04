#ifndef _QUIZ_OBJECT_H_
#define _QUIZ_OBJECT_H_

#include "global_manager.h"

// Music Manager.
typedef struct tag_struct_quiz_object
{
	unsigned char select;

} struct_quiz_object;

extern unsigned char quiz_answer[ MAX_RIFFS ];
extern unsigned char quiz_select[ MAX_RIFFS ];
extern unsigned char quiz_option[ MAX_RIFFS ][ MAX_OPTION ];

#endif//_QUIZ_OBJECT_H_