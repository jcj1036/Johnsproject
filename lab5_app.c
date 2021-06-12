#include "io.h"
#include <stdio.h>
#include "system.h"
#include "alt_types.h"
#include "sys/alt_irq.h"
//#include <math.h>


// create standard embedded type definitions
typedef   signed char   sint8;        // signed 8 bit values
typedef unsigned char   uint8;        // unsigned 8 bit values
typedef   signed short  sint16;       // signed 16 bit values
typedef unsigned short  uint16;       // unsigned 16 bit values
typedef   signed long   sint32;       // signed 32 bit values
typedef unsigned long   uint32;       // unsigned 32 bit values
typedef         float   real32;       // 32 bit real values



uint32* servoPtr = (uint32*)SERVOCONTROLLER_BASE;
uint32* SWPtr = (uint32*)SWITCHES_BASE;
uint32* KeyPtr = (uint32*)PUSHBUTTONS_BASE;
uint32* Hex0Ptr = (uint32*)HEX1_BASE;
uint32* Hex1Ptr = (uint32*)HEX2_BASE;
uint32* Hex2Ptr = (uint32*)HEX3_BASE;
uint32* Hex4Ptr = (uint32*)HEX4_BASE;
uint32* Hex5Ptr = (uint32*)HEX5_BASE;

uint32 buttonpress;
uint32 swRead;
uint32 minAngle = 50000;
uint32 maxAngle = 100000;
int updateMin = 0;
int updateMax = 0;
int swHunds;
int swTens;
int swOnes;
int swCount;
int swDec;

uint32 hexValue[10] = {0x40, 0x4f, 0x24, 0x30, 0x19, 0x12, 0x03, 0x78, 0x00, 0x18};

//int toDec(long long n)
//{
//    int dec = 0, i = 0, rem;
//    while (n != 0)
//    {
//        rem = n % 10;
//        n /= 10;
//        dec += rem * pow(2, i);
//        ++i;
//    }
//    return dec;
//}

float toCount(float angle)
{
	float x;
//	int y;
	x = angle - 45;
	x = x * .00001111;
	x = x + .001;
	x = x * 50000000;
	return x;
}

int toHundreds(int dec)
{
	int z;
	z = dec/100;
	return z;
}

int toTens(int dec)
{
	int z;
	if (dec > 99)
	{
		z = dec - 100;
		z = z/10;
	}
	else
	{
		z = dec/10;
	}
	return z;
}

int toOnes(int dec, int tens)
{
	int z = dec;
	if (z > 99)
	{
		z = dec - 100;
	}
	switch (tens)
	{
	case 0:
		break;
	case 1:
		z = z - 10;
		break;
	case 2:
		z = z - 20;
		break;
	case 3:
		z = z - 30;
		break;
	case 4:
		z = z - 40;
		break;
	case 5:
		z = z - 50;
		break;
	case 6:
		z = z - 60;
		break;
	case 7:
		z = z - 70;
		break;
	case 8:
		z = z - 80;
		break;
	case 9:
		z = z - 90;
		break;
	}
	z = z/1;
	return z;
}

void KeyIsr(void *context)
{
	buttonpress = *(KeyPtr + 3);
	if (buttonpress & 2)
	{
		minAngle = swCount;
		updateMin = 1;
	}
	else if (buttonpress & 4)
	{
		maxAngle = swCount;
		updateMax = 1;
	}
	*(KeyPtr + 3) = 0;
}

void ServoIsr(void *context)
{
	*(servoPtr) = minAngle;
	*(servoPtr + 1) = maxAngle;
}

int main(void)
{
	*(KeyPtr + 2) = 6;
	alt_ic_isr_register (PUSHBUTTONS_IRQ_INTERRUPT_CONTROLLER_ID, PUSHBUTTONS_IRQ, KeyIsr, 0, 0);
	
	alt_ic_isr_register (SERVOCONTROLLER_IRQ_INTERRUPT_CONTROLLER_ID, SERVOCONTROLLER_IRQ, ServoIsr, 0, 0);
	
	
	for(;;)
	{	
		swRead = *(SWPtr);
		
//		swDec = toDec(swRead);

		swCount = toCount(swRead);
		
		swHunds = toHundreds(swRead);
		swTens = toTens(swRead);
		swOnes = toOnes(swRead, swTens);

		if (updateMin == 1)
		{
			//write minimum tens digit hex display
			switch (swTens)
			{
			case 0 :
				*(Hex5Ptr) = hexValue[0];
				break;
			case 1 :
				*(Hex5Ptr) = hexValue[1];
				break;
			case 2 :
				*(Hex5Ptr) = hexValue[2];
				break;
			case 3 :
				*(Hex5Ptr) = hexValue[3];
				break;
			case 4 :
				*(Hex5Ptr) = hexValue[4];
				break;
			case 5 :
				*(Hex5Ptr) = hexValue[5];
				break;
			case 6 :
				*(Hex5Ptr) = hexValue[6];
				break;
			case 7 :
				*(Hex5Ptr) = hexValue[7];
				break;
			case 8 :
				*(Hex5Ptr) = hexValue[8];
				break;
			case 9 :
				*(Hex5Ptr) = hexValue[9];
				break;
			default :
				*(Hex5Ptr) = hexValue[0];
				break;
			}
			//write minimum ones digit hex display
			switch (swOnes)
			{
			case 0 :
				*(Hex4Ptr) = hexValue[0];
				break;
			case 1 :
				*(Hex4Ptr) = hexValue[1];
				break;
			case 2 :
				*(Hex4Ptr) = hexValue[2];
				break;
			case 3 :
				*(Hex4Ptr) = hexValue[3];
				break;
			case 4 :
				*(Hex4Ptr) = hexValue[4];
				break;
			case 5 :
				*(Hex4Ptr) = hexValue[5];
				break;
			case 6 :
				*(Hex4Ptr) = hexValue[6];
				break;
			case 7 :
				*(Hex4Ptr) = hexValue[7];
				break;
			case 8 :
				*(Hex4Ptr) = hexValue[8];
				break;
			case 9 :
				*(Hex4Ptr) = hexValue[9];
				break;
			default :
				*(Hex4Ptr) = hexValue[0];
				break;
			}
		}
		else if (updateMax == 1)
		{
			//write maximum hundreds digit hex display
			switch (swHunds)
			{
			case 0 :
				*(Hex2Ptr) = hexValue[0];
				break;
			case 1 :
				*(Hex2Ptr) = hexValue[1];
				break;
			case 2 :
				*(Hex2Ptr) = hexValue[2];
				break;
			case 3 :
				*(Hex2Ptr) = hexValue[3];
				break;
			case 4 :
				*(Hex2Ptr) = hexValue[4];
				break;
			case 5 :
				*(Hex2Ptr) = hexValue[5];
				break;
			case 6 :
				*(Hex2Ptr) = hexValue[6];
				break;
			case 7 :
				*(Hex2Ptr) = hexValue[7];
				break;
			case 8 :
				*(Hex2Ptr) = hexValue[8];
				break;
			case 9 :
				*(Hex2Ptr) = hexValue[9];
				break;
			default :
				*(Hex2Ptr) = hexValue[0];
				break;
			}
			//write maximum tens digit hex display
			switch (swTens)
			{
			case 0 :
				*(Hex1Ptr) = hexValue[0];
				break;
			case 1 :
				*(Hex1Ptr) = hexValue[1];
				break;
			case 2 :
				*(Hex1Ptr) = hexValue[2];
				break;
			case 3 :
				*(Hex1Ptr) = hexValue[3];
				break;
			case 4 :
				*(Hex1Ptr) = hexValue[4];
				break;
			case 5 :
				*(Hex1Ptr) = hexValue[5];
				break;
			case 6 :
				*(Hex1Ptr) = hexValue[6];
				break;
			case 7 :
				*(Hex1Ptr) = hexValue[7];
				break;
			case 8 :
				*(Hex1Ptr) = hexValue[8];
				break;
			case 9 :
				*(Hex1Ptr) = hexValue[9];
				break;
			default :
				*(Hex1Ptr) = hexValue[0];
				break;
			}
			//write maximum ones digit hex display
			switch (swOnes)
			{
			case 0 :
				*(Hex0Ptr) = hexValue[0];
				break;
			case 1 :
				*(Hex0Ptr) = hexValue[1];
				break;
			case 2 :
				*(Hex0Ptr) = hexValue[2];
				break;
			case 3 :
				*(Hex0Ptr) = hexValue[3];
				break;
			case 4 :
				*(Hex0Ptr) = hexValue[4];
				break;
			case 5 :
				*(Hex0Ptr) = hexValue[5];
				break;
			case 6 :
				*(Hex0Ptr) = hexValue[6];
				break;
			case 7 :
				*(Hex0Ptr) = hexValue[7];
				break;
			case 8 :
				*(Hex0Ptr) = hexValue[8];
				break;
			case 9 :
				*(Hex0Ptr) = hexValue[9];
				break;
			default :
				*(Hex0Ptr) = hexValue[0];
				break;
			}

		}
		updateMin = 0;
		updateMax = 0;
	}
	return 0;
}


