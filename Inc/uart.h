#ifndef __UART_H__
#define __UART_H__
#include <stdio.h>
#include "common.h"

typedef struct UsartRegs UsartRegs;
struct UsartRegs {
	IoRegister SR;					//0x00	Status Register
	IoRegister DR;					//0x04	Data Register
	IoRegister BRR;		    		//0x08	Baud Rate Register
	IoRegister CR1;					//0x0C	Control Register 1
	IoRegister CR2;					//0x10	Control Register 2
	IoRegister CR3;					//0x14	Control Register 3
	IoRegister GTPR;				//0x18	Guard Time and Prescaler Register
};

#define usart5  					((UsartRegs *)0x40005000)

//SR
#define USART_PE				(1 << 0)
#define USART_FE				(1 << 1)
#define USART_NF				(1 << 2)
#define USART_ORE				(1 << 3)
#define USART_IDLE				(1 << 4)
#define USART_RXNE				(1 << 5)
#define USART_TC				(1 << 6)
#define USART_TXE				(1 << 7)
#define USART_LBD				(1 << 8)
#define USART_CTS				(1 << 9)

//CR1
#define USART_SEND_BREAK				1ULL
#define USART_RECEIVER_WAKEUP_ACTIVE	(0ULL << 1)
#define USART_RECEIVER_WAKEUP_MUTE		(1ULL << 1)
#define USART_RX_DISABLE				(0ULL << 2)
#define USART_RX_ENABLE					(1ULL << 2)
#define USART_TX_DISABLE				(0ULL << 3)
#define USART_TX_ENABLE					(1ULL << 3)
#define USART_IDLEIE					(1ULL << 4)
#define USART_RXNEIE					(1ULL << 5)
#define USART_TCIE						(1ULL << 6)
#define USART_TXEIE						(1ULL << 7)
#define USART_PEIE						(1ULL << 8)
#define USART_PARITY_EVEN				(0ULL << 9)
#define USART_PARITY_ODD				(1ULL << 9)
#define USART_PARITY_OFF				(0ULL << 10)
#define USART_PARITY_ON					(1ULL << 10)
#define USART_WAKEUP_IDLE				(0ULL << 11)
#define USART_WAKEUP_ADDR				(1ULL << 11)
#define	USART_WORDLENGTH_8				(0ULL << 12)
#define	USART_WORDLENGTH_9				(1ULL << 12)
#define USART_DISABLE					(0ULL << 13)
#define USART_ENABLE					(1ULL << 13)
#define USART_SAMPLING_16				(0ULL << 15)
#define USART_SAMPLING_8				(1ULL << 15)

//CR2
#define USART_STOP_BIT_1				(0ULL << 28)
#define USART_STOP_BIT_0_5				(1ULL << 28)
#define USART_STOP_BIT_2				(2ULL << 28)
#define USART_STOP_BIT_1_5				(3ULL << 28)

#define USART_GET_STATUS(usart, flag)				((usart)->SR & (flag))
#define USART_IS_TX_REG_EMPTY(usart)				USART_GET_STATUS(usart, USART_TXE)
#define USART_IS_RX_REG_NOT_EMPTY(usart)			USART_GET_STATUS(usart, USART_RXNE)
#define IS_OVERSAMPLING_BY_16(mode)					~(mode & USART_SAMPLING_16)
#define USART_ENABLE_INTERRUPT(usart, flag)			(usart)->CR1 |= (flag)

void usartConfigure(UsartRegs *usart, long long mode, int baudrate, int clockfreq);

#endif //__UART_H__
