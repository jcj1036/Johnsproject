/*
 * lab6_part2.c
 *
 *  Created on: Apr 14, 2021
 *      Author: jcj1036
 */

#include <stdio.h>
#include "system.h"

// create standard embedded type definitions
typedef   signed char   sint8;        // signed 8 bit values
typedef unsigned char   uint8;        // unsigned 8 bit values
typedef   signed short  sint16;       // signed 16 bit values
typedef unsigned short  uint16;       // unsigned 16 bit values
typedef   signed long   sint32;       // signed 32 bit values
typedef unsigned long   uint32;       // unsigned 32 bit values
typedef         float   real32;       // 32 bit real values



uint32* ramPtr = (uint32*)INFERREDRAM_0_BASE;
uint32* ledPtr = (uint32*)LEDS_BASE;

int byte(uint8 address, uint32 bytes, uint8 data)
{
	uint8 i;
	uint8 readback;

	uint8* addPtr = (uint8*)address;

	for (i = 0; i < bytes/4; i++)
	{
		*(addPtr + i) = data;
	}

	for (i = 0; i < bytes/4; i++)
	{
		readback = *(addPtr + i);
		if (readback != data)
		{
			*ledPtr = 0x3FF;
			break;
		}
	}
	return 0;
}

int bit16(uint16 address, uint32 bytes, uint16 data)
{
	uint16 i;
	uint16 readback;

	uint16* addPtr = (uint16*)address;

	for (i = 0; i < bytes/4; i++)
	{
		*(addPtr + i) = data;
	}

	for (i = 0; i < bytes/4; i++)
	{
		readback = *(addPtr + i);
		if (readback != data)
		{
			*ledPtr = 0x3FF;
			break;
		}
	}
	return 0;
}

int bit32(uint32 address, uint32 bytes, uint32 data)
{
	uint32 i;
	uint32 readback;

	uint32* addPtr = (uint32*)address;

	for (i = 0; i < bytes/4; i++)
	{
		*(addPtr + i) = data;
	}

	for (i = 0; i < bytes/4; i++)
	{
		readback = *(addPtr + i);
		if (readback != data)
		{
			*ledPtr = 0x3FF;
			break;
		}
	}
	return 0;
}

int main(void)
{
//	byte(INFERREDRAM_0_BASE,16384,0x12);
//
//	bit16(INFERREDRAM_0_BASE,16384,0x1234);

	bit32(INFERREDRAM_0_BASE,16384,0x12345678);

	return 0;
}


