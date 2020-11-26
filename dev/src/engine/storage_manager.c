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
	unsigned char byte;

	sRamOffSet = 0x0000;
	SYS_disableInts();
	SRAM_enable();

	byte = SRAM_readByte( sRamOffSet++ );
	engine_quiz_manager_set_riffs_play( byte );
	byte = SRAM_readByte( sRamOffSet++ );
	engine_quiz_manager_set_difficulty( byte );

	SRAM_disable();
	SYS_enableInts();
}

void engine_storage_manager_write()
{
	struct_quiz_object *qo = &global_quiz_object;

	unsigned short sRamOffSet;
	unsigned char byte;

	sRamOffSet = 0x0000;
	SYS_disableInts();
	SRAM_enable();

	byte = qo->quiz_riff_numbs;
	SRAM_writeByte( sRamOffSet++, byte );
	byte = qo->quiz_difficulty;
	SRAM_writeByte( sRamOffSet++, byte );

	SRAM_disable();
	SYS_enableInts();
}

void engine_storage_manager_erase()
{
	unsigned long sRamOffSet;

	sRamOffSet = 0x0000;
	SYS_disableInts();
	SRAM_enable();

	SRAM_writeByte( sRamOffSet++, INVALID_INDEX );
	SRAM_writeByte( sRamOffSet++, INVALID_INDEX );

	SRAM_disable();
	SYS_enableInts();
}