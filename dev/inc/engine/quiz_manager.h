#ifndef __QUIZ_MANAGER__
#define __QUIZ_MANAGER__

#include "quiz_object.h"

// Global variables.
extern struct_quiz_object global_quiz_object;

void engine_quiz_manager_init();

void engine_quiz_manager_load();
void engine_quiz_manager_load_random();
void engine_quiz_manager_load_mixing();
void engine_quiz_manager_load_normal();

void engine_quiz_manager_draw( unsigned char idx );
void engine_quiz_manager_draw2();
void engine_quiz_manager_draw_option();
void engine_quiz_manager_draw_riffs();

#endif//__QUIZ_MANAGER__