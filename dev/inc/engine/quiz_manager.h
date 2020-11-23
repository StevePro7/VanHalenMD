#ifndef __QUIZ_MANAGER__
#define __QUIZ_MANAGER__

#include "quiz_object.h"

// Global variables.
extern struct_quiz_object global_quiz_object;

void engine_quiz_manager_init();

void engine_quiz_manager_load_random();
void engine_quiz_manager_load_mixing();
void engine_quiz_manager_load_normal();

void engine_quiz_manager_riff();
void engine_quiz_manager_draw();

unsigned char engine_quiz_manager_increment( unsigned char quiz_selection );
//void engine_quiz_manager_increment( unsigned char quiz_selection );
//void engine_quiz_manager_decrement( unsigned char quiz_selection );
//void engine_quiz_manager_load_testing();
//
//void engine_quiz_manager_cheat();

void engine_quiz_manager_reset();
void engine_quiz_manager_set_riffs_play( unsigned char index );
void engine_quiz_manager_set_difficulty( unsigned char index );

#endif//__QUIZ_MANAGER__