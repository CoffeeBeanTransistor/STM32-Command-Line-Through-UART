#include "uart.h"
#include <stdio.h>

void usartConfigure(UsartRegs *usart, long long mode, int baudrate, int clockfreq) {

	int mantissa, fraction;
	float usartDiv, temp;

	usart->CR1 = (uint32_t)(mode & 0xffff);
	usart->CR2 = (uint32_t)((mode >> 16) & 0xffff);
	usart->CR3 = (uint32_t)(mode >> 32);

	usartDiv = (float)clockfreq / 8 /baudrate ;

	if(IS_OVERSAMPLING_BY_16(mode)) {
		usartDiv /= 2;
	}

	mantissa = (int)(usartDiv);
	temp = ((float)usartDiv) - ((int)usartDiv);
	temp *= 16;
	fraction = (int)(temp);

	usart->BRR = (mantissa << 4) | fraction;
}
