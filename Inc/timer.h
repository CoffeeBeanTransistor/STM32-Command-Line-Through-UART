#ifndef __TIMER_H__
#define __TIMER_H__
#include <stdio.h>
#include "common.h"

typedef struct TimerRegs TimerRegs;
struct TimerRegs {
	IoRegister CR1;					//0x00
	IoRegister CR2;					//0x04
	IoRegister SMCR;		    	//0x08
	IoRegister DIER;				//0x0C
	IoRegister SR;					//0x10
	IoRegister EGR;					//0x14
	IoRegister CCMR1;				//0x18
	IoRegister CCMR2;				//0x1C
	IoRegister CCER;				//0x20
	IoRegister CNT;					//0x24
	IoRegister PSC;					//0x28
	IoRegister ARR;					//0x2C
	IoRegister Reserved0;			//0x30
	IoRegister CCR1;				//0x34
	IoRegister CCR2;				//0x38
	IoRegister CCR3;				//0x3C
	IoRegister CCR4;				//0x40
	IoRegister Reserved1;			//0x44
	IoRegister DCR;					//0x48
	IoRegister DMAR;				//0x4C
	IoRegister OR;					//0x50
};

#define tim2  				((TimerRegs *)0x40000000)

//SR
#define TIM_UIF				 1
#define TIM_CC1IF			(1 << 1)
#define TIM_CC2IF			(1 << 2)
#define TIM_CC3IF			(1 << 3)
#define TIM_CC4IF			(1 << 4)
#define TIM_TIF				(1 << 6)
#define TIM_CC1OF			(1 << 9)
#define TIM_CC2OF			(1 << 10)
#define TIM_CC3OF			(1 << 11)
#define TIM_CC4OF			(1 << 12)

//CR1
#define TIM_CEN 		  		1

//DIER
#define TIM_UIE					1

//MACROS
#define TIM_SET_CNT(tim, value)					(tim)->CNT = (value)
#define TIM_SET_PSC(tim, value)					(tim)->PSC = (value)
#define TIM_SET_ARR(tim, value)					(tim)->ARR = (value)

/*Clear Status Register of Timer, which FLAG should be one of the following :
	TIM_UIF		Update Interrupt Flag
	TIM_CC1IF	Capture/Compare 1 Interrupt Flag
	TIM_CC2IF	Capture/Compare 2 Interrupt Flag
	TIM_CC3IF	Capture/Compare 3 Interrupt Flag
	TIM_CC4IF	Capture/Compare 4 Interrupt Flag
	TIM_TIF		Trigger Interrupt Flag
	TIM_CC1OF	Capture/Compare 1 Overcapture Flag
	TIM_CC2OF	Capture/Compare 2 Overcapture Flag
	TIM_CC3OF	Capture/Compare 3 Overcapture Flag
	TIM_CC4OF	Capture/Compare 4 Overcapture Flag */
#define TIM_CLEAR_FLAG(tim, flag)				(tim)->SR &= ~(flag)
#define TIM_COUNTER_ENABLE(tim)					(tim)->CR1 |= TIM_CEN
#define TIM_COUNTER_DISABLE(tim)				(tim)->CR1 &= ~TIM_CEN
#define TIM_ENABLE_INTERRUPT(tim, interrupt) 	(tim)->DIER |= TIM_UIE

#endif //__TIMER_H__
