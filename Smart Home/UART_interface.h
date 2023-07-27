/*
 * UART_interface.h
 *
 *       Author: Eslam Nasr
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

#include "STD_TYPES.h"


void UART_voidInit(void);

void UART_voidSendData(uint8 Copy_u8Data);
uint8 UART_voidReceiveData(void);

uint8 UART_u8SendString(uint8 * Copy_pu8String);
uint8 UART_u8RecieveString(uint8 * Copy_pu8String , uint8 Copy_u8Size);



#endif /* UART_INTERFACE_H_ */
