#ifndef __RCC_H__
#define __RCC_H__
#include <stdio.h>
#include "common.h"
typedef struct RccRegs RccRegs;
struct RccRegs {
	IoRegister CR;						//0x00 Control Reg
	IoRegister PLLCFGR;					//0x04 PLL Config Reg
	IoRegister CFGR;				    //0x08 Clock Config Reg
	IoRegister CIR;						//0x0C Clock Interrupt Reg
	IoRegister AHB1RSTR;				//0x10 AHB1 Peripheral Reset Reg
	IoRegister AHB2RSTR;				//0x14 AHB2 Peripheral Reset Reg
	IoRegister AHB3RSTR;				//0x18 AHB3 Peripheral Reset Reg
	IoRegister Reserved0;				//0x1C Reserved
	IoRegister APB1RSTR;				//0x20 APB1 Peripheral Reset Reg
	IoRegister APB2RSTR;				//0x24 APB2 Peripheral Reset Reg
	IoRegister Reserved1[2];			//0x28 Reserved
	IoRegister AHB1ENR;					//0x30 AHB1 Peripheral Clock Reg
	IoRegister AHB2ENR;					//0x34 AHB2 Peripheral Clock Reg
	IoRegister AHB3ENR;					//0x38 AHB3 Peripheral Clock Reg
	IoRegister Reserved2;				//0x3C Reserved
	IoRegister APB1ENR;					//0x40 APB1 Peripheral Clock Reg
	IoRegister APB2ENR;					//0x44 APB2 Peripheral Clock Reg
	IoRegister Reserved3[2];			//0x48 Reserved
	IoRegister AHB1ELPENR;				//0x50 AHB1 Peripheral Low Power Clock Reg
	IoRegister AHB2ELPENR;				//0x54 AHB2 Peripheral Low Power Clock Reg
	IoRegister AHB3ELPENR;				//0x58 AHB3 Peripheral Low Power Clock Reg
	IoRegister Reserved4;				//0x5C Reserved
	IoRegister APB1ELPENR;				//0x60 APB1 Peripheral Low Power Clock Reg
	IoRegister APB2ELPENR;				//0x64 APB2 Peripheral Low Power Clock Reg
	IoRegister Reserved5[2];			//0x68 Reserved
	IoRegister BDCR;					//0x70 Backup Domain Con Reg
	IoRegister CSR;						//0x74 Clock Con & Status Reg
	IoRegister Reserved6[2];			//0x78 Reserved
	IoRegister SSCGR;					//0x80 Spread Spectrum Clock Gen Reg
	IoRegister PLL12SCFGR;				//0x84 PLLI2S Config Reg
};

#define rcc										((RccRegs *)0x40023800)

//TIMER
#define ENABLE_TIMER_2_CLK_GATING()				rcc->APB1ENR |= (1 << 0)

#define RESET_TIMER_2()							rcc->APB1RSTR |= (1 << 0)

#define UNRESET_TIMER_2()						rcc->APB1RSTR &= ~(1 << 0)

//GPIO
#define ENABLE_GPIOC_CLK_GATING()				rcc->AHB1ENR |= (1 << 2)
#define ENABLE_GPIOD_CLK_GATING()				rcc->AHB1ENR |= (1 << 3)
#define ENABLE_GPIOG_CLK_GATING()				rcc->AHB1ENR |= (1 << 6)

#define RESET_GPIOC()							rcc->AHB1RSTR |= (1 << 2)
#define RESET_GPIOD()							rcc->AHB1RSTR |= (1 << 3)
#define RESET_GPIOG()							rcc->AHB1RSTR |= (1 << 6)

#define UNRESET_GPIOC()							rcc->AHB1RSTR &= ~(1 << 2)
#define UNRESET_GPIOD()							rcc->AHB1RSTR &= ~(1 << 3)
#define UNRESET_GPIOG()							rcc->AHB1RSTR &= ~(1 << 6)

//USART
#define ENABLE_USART5_CLK_GATING()				rcc->APB1ENR |= (1 << 20)

#define RESET_USART5()							rcc->APB1RSTR |= (1 << 20)

#define UNRESET_USART5()						rcc->APB1RSTR &= ~(1 << 20)

#endif //__RCC_H__
