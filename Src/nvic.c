#include "nvic.h"
#include <stdio.h>

void nvicEnableInterrupt(int interruptNumber) {
	int regNum, bitNum;

	regNum = interruptNumber / 32;
	bitNum = interruptNumber % 32;

	nvic->ISER[regNum] = 1 << bitNum;
}
