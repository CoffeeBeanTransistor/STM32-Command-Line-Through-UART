#include "gpio.h"
#include <stdio.h>

uint8_t bitPos[] = {
	     4,			// b'0000	(Undefined)
		 0,			// b'0001
		 1,			// b'0010
		 1,			// b'0011	(Undefined)
		 2,			// b'0100
		 2,			// b'0101	(Undefined)
		 2,			// b'0110	(Undefined)
		 2,			// b'0111	(Undefined)
		 3,			// b'1000
		 3,			// b'1001	(Undefined)
		 3,			// b'1010	(Undefined)
		 3,			// b'1011	(Undefined)
		 3,			// b'1100	(Undefined)
		 3,			// b'1101	(Undefined)
		 3,			// b'1110	(Undefined)
		 3,			// b'1111	(Undefined)
};

int getPinNumber(GpioPin pin) {
	int pinNum = 0, i = 0, mask = 0x0f, temp;

	for(i = 0; i < 4; i++) {
		temp = pin & mask;
		temp = bitPos[temp];
		if(temp == 4)
			pinNum += 4;
		else {
			pinNum += temp;
			break;
		}
		pin >>= 4;
	}
	return pinNum;
}

/**
 * To configure the GPIO pin.
 *
 * Input:
 * 	port			the port to configure
 * 	pin				the pin to configure
 * 	configuration	the configuration setting for the pin
 * 					[1:0] Mode
 * 					[2:2] Driver Type
 * 					[4:3] Output Speed
 * 					[6:5] Pull Type
 *
 * 	E.g.:
 * 		gpioConfigurationPins(GpioA, GpioPin0, GPIO_OUTPUT |		\
 * 											  GPIO_OPEN_DRAIN |	\
 * 											  GPIO_HIGH_SPEED |	\
 * 											  GPIO_NO_PULL);
 */
void gpioConfigurePin(GpioRegs *port, GpioPin pin, int configuration) {

	uint32_t mode, driver, outSpeed, pullType, pinMask, pinTemp;

	pinMask = 0x01;

	mode 	=  configuration & 0x3;
	driver 	= (configuration >> 2) & 1;
	outSpeed= (configuration >> 3) & 3;
	pullType= (configuration >> 5) & 3;

	for(int i = 0; i < 16; i++) {
		pinTemp = pinMask & pin;
		if(pinTemp > 0) {
			port->mode &= ~(3 << (i * 2));
			port->mode |= mode << i * 2;

			port->driverType &= ~(1 << i);
			port->driverType |= driver << i;

			port->outSpeed &= ~(3 << (i * 2));
			port->outSpeed |= outSpeed << i * 2;

			port->pullType &= ~(3 << (i * 2));
			port->pullType |= pullType << i * 2;

		}
		pinMask = pinMask << 1;
	}

}

void gpioWritePins(GpioRegs *port, GpioPin pins, int state) {

	if(state == PIN_SET)
		port->outBits = pins;
	else if (state == PIN_RESET)
		port->outBits = pins << 16;
}

void gpioTogglePins(GpioRegs *port, GpioPin pins) {
	port->outData ^= pins;
}

void gpioConfigureAltFunc(GpioRegs *port, GpioPin pin, int altFunc) {

	IoRegister *altReg = &(port->altFuncLow);
	int pinNum;
	  pinNum = getPinNumber(pin);


		if(pinNum >= 8) {
			altReg++;
			pinNum -= 8;
		}

		*(altReg) = altFunc << (pinNum * 4) ;
}

