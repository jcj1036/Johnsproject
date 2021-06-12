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



uint32* ramPtr = (uint32*)INFERRED_RAM_BE_0_BASE;
uint32* ledPtr = (uint32*)LEDS_BASE;
uint32* KeyPtr = (uint32*)KEY_BASE;

int byte(uint8 address, uint32 bytes, uint8 data)
{
	uint32 i;
	uint8 readback;
	uint32 real_address;

	uint8* addPtr = (uint8*)address;

	for (i = 0; i < bytes; i++)
	{
		*(addPtr + i) = data;
	}

	for (i = 0; i < bytes; i++)
	{
		readback = *(addPtr + i);
		real_address = i;
		if (readback != data)
		{
			*ledPtr = 0x3FF;
			printf("ERROR: Address: %2lx, Read: %2x, Expected: %2x\n", real_address, readback, data);
			break;
		}
	}
	return 0;
}

int bit16(uint16 address, uint bytes, uint16 data)
{
	uint32 i;
	uint16 readback;
	uint32 real_address;

	uint16* addPtr = (uint16*)address;

	for (i = 0; i < bytes/2; i++)
	{
		*(addPtr + i) = data;
	}

	for (i = 0; i < bytes/2; i++)
	{
		readback = *(addPtr + i);
		real_address = (i*2);
		if (readback != data)
		{
			*ledPtr = 0x3FF;
			printf("ERROR: Address: %4lx, Read: %4x, Expected: %4x\n", real_address, readback, data);
			break;
		}
	}
	return 0;
}

int bit32(uint32 address, uint32 bytes, uint32 data)
{
	uint32 i;
	uint32 readback;
	uint32 real_address;

	uint32* addPtr = (uint32*)address;

	for (i = 0; i < bytes/4; i++)
	{
		*(addPtr + i) = data;
	}

	for (i = 0; i < bytes/4; i++)
	{
		readback = *(addPtr + i);
		real_address = (i*4);
		if (readback != data)
		{
			*ledPtr = 0x3FF;
			printf("ERROR: Address: %8lx, Read: %8lx, Expected: %8lx\n", real_address, readback, data);
			break;
		}
	}
	return 0;
}

void KeyIsr(void *context)
{
	*ledPtr = 0x1;
	printf("RAM TEST DONE");
}

int main(void)
{
	*(KeyPtr + 2) = 1;
	alt_ic_isr_register (KEY_IRQ_INTERRUPT_CONTROLLER_ID, KEY_IRQ, KeyIsr, 0, 0);


	for(;;)
	{
		byte(INFERRED_RAM_BE_0_BASE,16384,0x00);

		*ledPtr = 0x0;
		bit16(INFERRED_RAM_BE_0_BASE,16384,0x1234);

		*ledPtr = 0x0;
		bit32(INFERRED_RAM_BE_0_BASE,16384,0xABCDEF90);

		*ledPtr = 0x0;
		bit32(INFERRED_RAM_BE_0_BASE,16384,0x12345678);

		*ledPtr = 0x0;
//		if (*KeyPtr == 0)
//		{
//			*ledPtr = 0x1;
//			printf("RAM TEST DONE");
//			break;
//		}
	}
	return 0;
}


