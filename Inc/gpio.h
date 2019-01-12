#ifndef __GPIO_H__
#define __GPIO_H__
#include <stdio.h>
#include "common.h"

typedef enum {
	PIN_RESET = 0,
	PIN_SET,
}PinState;

typedef enum {
	GPIO_INPUT = 0,
	GPIO_OUTPUT,
	GPIO_ALT_FUNC,
	GPIO_ANALOG,
}GpioMode;

typedef enum {
	GPIO_PUSH_PULL 			= 0,
	GPIO_OPEN_DRAIN		 	= 1 << 2,
}GpioDriverType;

typedef enum {
	GPIO_LOW_SPEED 			= 0,
	GPIO_MEDIUM_SPEED 		= 1 << 3,
	GPIO_HIGH_SPEED 		= 2 << 3,
	GPIO_VERY_HIGH_SPEED	= 3 << 3,
}GpioSpeed;

typedef enum {
	GPIO_NO_PULL 			= 0,
	GPIO_PULL_UP 			= 1 << 5,
	GPIO_PULL_DOWN 			= 2 << 5,
}GpioPullType;

typedef enum {
	GPIO_AF0 = 0,
	GPIO_AF1,
	GPIO_AF2,
	GPIO_AF3,
	GPIO_AF4,
	GPIO_AF5,
	GPIO_AF6,
	GPIO_AF7,
	GPIO_AF8,
	GPIO_AF9,
	GPIO_AF10,
	GPIO_AF11,
	GPIO_AF12,
	GPIO_AF13,
	GPIO_AF14,
	GPIO_AF15
}GpioAltFunc;

typedef enum {
	GpioPin0 	= 0x0001,
	GpioPin1 	= 0x0002,
	GpioPin2 	= 0x0004,
	GpioPin3 	= 0x0008,
	GpioPin4 	= 0x0010,
	GpioPin5 	= 0x0020,
	GpioPin6 	= 0x0040,
	GpioPin7 	= 0x0080,
	GpioPin8 	= 0x0100,
	GpioPin9 	= 0x0200,
	GpioPin10 	= 0x0400,
	GpioPin11 	= 0x0800,
	GpioPin12 	= 0x1000,
	GpioPin13 	= 0x2000,
	GpioPin14 	= 0x4000,
	GpioPin15 	= 0x8000,
}GpioPin;


typedef struct GpioRegs GpioRegs;
struct GpioRegs {
	IoRegister mode;
	IoRegister driverType;
	IoRegister outSpeed;
	IoRegister pullType;
	IoRegister inData;
	IoRegister outData;
	IoRegister outBits;
	IoRegister pinLock;
	IoRegister altFuncLow;
	IoRegister altFuncHi;
};

#define	gpioC	((GpioRegs *)0x40020800)
#define	gpioD	((GpioRegs *)0x40020C00)
#define	gpioG	((GpioRegs *)0x40021800)

void gpioTogglePins(GpioRegs *port, GpioPin pins);
void gpioWritePins(GpioRegs *port, GpioPin pins, int state);
int getPinNumber(GpioPin pin);
void gpioConfigurePin(GpioRegs *port, GpioPin pin, int configuration);
void gpioConfigureAltFunc(GpioRegs *port, GpioPin pin, int configuration);

#endif //__GPIO_H__
