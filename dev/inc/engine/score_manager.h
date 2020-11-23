#ifndef __SCORE_MANAGER__
#define __SCORE_MANAGER__

#include "score_object.h"

// Global variables.
extern struct_score_object global_socre_object;

void engine_score_manager_init();
void engine_score_manager_reset();
void engine_score_manager_update( unsigned char index, unsigned char answer );
void engine_score_manager_draw();
void engine_score_manager_draw_percent( unsigned char index );
void engine_score_manager_draw_summary( unsigned char played );

#endif//__SCORE_MANAGER__