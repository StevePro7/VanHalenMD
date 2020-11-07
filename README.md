# VanHalenMD
Vintage Van Halen Pick the Riff

07-Nov-2020
IMPORTANT
e.g.
locale_manager.h
I found that if I changed data here I had to change the corresponding *.c file
that consume the locale otherwise the locale may not neccesarily update!!

05-Nov-2020
IMPORTANT
gfx.h
must manually build the gfx.h file from the gfx.res file
BUT after the header file is generated MUST manually update:
#ifdef _CONSOLE
#include "_genesis.h"
#else
#include <genesis.h>
#endif

Otherwise I won't be able to Ctrl+Shift+B build + step thru code


title text
CLASSIC "PICK THE RIFF" TESTER
123456789012345678901234567890