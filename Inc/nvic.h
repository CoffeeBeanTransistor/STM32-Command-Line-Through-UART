#ifndef __NVIC_H__
#define __NVIC_H__
#include <stdio.h>
#include "common.h"

typedef struct NvicRegs NvicRegs;
struct NvicRegs {
	IoRegister	ISER[3];
	IoRegister	Reserved0[29];
	IoRegister	ICER[3];
	IoRegister	Reserved1[29];
	IoRegister	ISPR[3];
	IoRegister	Reserved2[29];
	IoRegister	ICPR[3];
	IoRegister	Reserved3[29];
	IoRegister	IABR[3];
	IoRegister	Reserved4[61];
	IoRegister	IPR[21];
	IoRegister	Reserved5[677];
	IoRegister	STIR;
};

#define nvic	((NvicRegs *)0xE000E100)

void nvicEnableInterrupt(int interruptNumber);

#endif //__NVIC_H__
