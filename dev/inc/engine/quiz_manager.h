#ifndef __QUIZ_MANAGER__
#define __QUIZ_MANAGER__

//#include "quiz_object.h"

// Global variables.
//extern struct_quiz_object global_quiz_object;

void engine_quiz_manager_init();

//void engine_quiz_manager_load();
void engine_quiz_manager_load_random( const unsigned char difficulty );
void engine_quiz_manager_load_mixing( const unsigned char difficulty );
void engine_quiz_manager_load_normal( const unsigned char difficulty );

void engine_quiz_manager_draw( unsigned char idx );
void engine_quiz_manager_draw2();

// TODO delete debug functions.
void engine_quiz_manager_debug_option( unsigned char page );
void engine_quiz_manager_debug_riffs();

#endif//__QUIZ_MANAGER__