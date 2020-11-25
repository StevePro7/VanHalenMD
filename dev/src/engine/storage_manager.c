#include "storage_manager.h"
#include "enum_manager.h"
//#include "font_manager.h"
#include "global_manager.h"
#include "quiz_manager.h"

#ifdef _CONSOLE
#include "_genesis.h"
#else
#include <genesis.h>
#endif

// Global variable.
//struct_storage_object global_savegame_object;

void engine_storage_manager_read()
{
	struct_quiz_object *qo = &global_quiz_object;
	//struct_storage_object *so = &global_storage_object;

	unsigned short sRamOffSet;
	unsigned char byte;

	sRamOffSet = 0x0000;
	SYS_disableInts();
	SRAM_enable();

	byte = SRAM_readByte( sRamOffSet++ );
	//engine_font_manager_data( byte, 20, 4 );
	engine_quiz_manager_set_riffs_play( byte );
	//engine_font_manager_data( qo->quiz_riff_numbs, 20, 5 );
	//so->save_riff_index = byte;

	byte = SRAM_readByte( sRamOffSet++ );
	//engine_font_manager_data( byte, 20, 7 );
	engine_quiz_manager_set_difficulty( byte );
	//engine_font_manager_data( qo->quiz_difficulty, 20, 8 );
	//so->save_difficulty = byte;

	//engine_quiz_manager_set_riffs_play( so->save_riff_index );
	//engine_quiz_manager_set_difficulty( so->save_difficulty );

	SRAM_disable();
	SYS_enableInts();
}

void engine_storage_manager_write()
{
	//struct_storage_object *so = &global_storage_object;
	struct_quiz_object *qo = &global_quiz_object;

	unsigned short sRamOffSet;
	unsigned char byte;

	sRamOffSet = 0x0000;
	SYS_disableInts();
	SRAM_enable();

	//engine_font_manager_data( qo->quiz_riff_numbs, 20, 13 );
	byte = qo->quiz_riff_numbs;
	//engine_font_manager_data( byte, 20, 14 );
	//so->save_riff_index = byte;
	SRAM_writeByte( sRamOffSet++, byte );

	//engine_font_manager_data( qo->quiz_difficulty, 20, 16 );
	byte = qo->quiz_difficulty;
	//engine_font_manager_data( byte, 20, 17 );
	//so->save_difficulty = byte;
	SRAM_writeByte( sRamOffSet++, byte );

	SRAM_disable();
	SYS_enableInts();
}

void engine_storage_manager_erase()
{
	//struct_storage_object *so = &global_storage_object;

	unsigned long sRamOffSet;

	sRamOffSet = 0x0000;
	SYS_disableInts();
	SRAM_enable();

	SRAM_writeByte( sRamOffSet++, INVALID_INDEX );
	SRAM_writeByte( sRamOffSet++, INVALID_INDEX );

	SRAM_disable();
	SYS_enableInts();
}