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

void engine_storage_manager_read()
{
	unsigned short sRamOffSet;
	unsigned short word;
	unsigned char byte;
	unsigned char idx;

	sRamOffSet = 0x0000;
	SYS_disableInts();
	SRAM_enable();

	// Quiz most recent number + difficulty.
	byte = SRAM_readByte( sRamOffSet++ );
	engine_quiz_manager_set_riffs_play( byte );
	byte = SRAM_readByte( sRamOffSet++ );
	engine_quiz_manager_set_difficulty( byte );

	// Quiz summary numbers + difficulties.
	for( idx = 0; idx < MAX_OPTION * MAX_DIFFICULTY; idx++ )
	{
		word = SRAM_readWord( sRamOffSet++ );
		engine_quiz_manager_set_quiz_saved( idx, word );
	}
	word = SRAM_readWord( sRamOffSet++ );
	engine_quiz_manager_set_quiz_total( word );

	SRAM_disable();
	SYS_enableInts();
}

void engine_storage_manager_write()
{
	struct_quiz_object *qo = &global_quiz_object;

	unsigned short sRamOffSet;
	unsigned short word;
	unsigned char byte;
	unsigned char idx;

	sRamOffSet = 0x0000;
	SYS_disableInts();
	SRAM_enable();

	// Quiz most recent number + difficulty.
	byte = qo->quiz_riff_numbs;
	SRAM_writeByte( sRamOffSet++, byte );
	byte = qo->quiz_difficulty;
	SRAM_writeByte( sRamOffSet++, byte );

	// Quiz summary numbers + difficulties.
	for( idx = 0; idx < MAX_OPTION * MAX_DIFFICULTY; idx++ )
	{
		word = qo->quiz_saved[ idx ];
		SRAM_writeWord( sRamOffSet++, word );
	}
	word = qo->quiz_total;
	SRAM_writeWord( sRamOffSet++, word );

	SRAM_disable();
	SYS_enableInts();
}

void engine_storage_manager_erase()
{
	unsigned long sRamOffSet;
	unsigned char idx;

	sRamOffSet = 0x0000;
	SYS_disableInts();
	SRAM_enable();

	// Quiz most recent number + difficulty.
	SRAM_writeByte( sRamOffSet++, INVALID_INDEX );
	SRAM_writeByte( sRamOffSet++, INVALID_INDEX );

	// Quiz summary numbers + difficulties.
	for( idx = 0; idx < MAX_OPTION * MAX_DIFFICULTY; idx++ )
	{
		SRAM_writeWord( sRamOffSet++, INVALID_INDEX );
	}
	SRAM_writeWord( sRamOffSet++, INVALID_INDEX );

	SRAM_disable();
	SYS_enableInts();
}