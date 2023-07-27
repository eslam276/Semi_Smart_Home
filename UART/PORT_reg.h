/**************************************************************/
/**************************************************************/
/*********		Author: Eslam Nasr   		*******************/
/*********		File: PORT_reg.h			*******************/
/*********		Version: 1.00				*******************/
/**************************************************************/
/**************************************************************/


#ifndef PORT_REG_H_
#define PORT_REG_H_

#define DDRA		*((volatile uint8*)0x3A)
#define PORTA		*((volatile uint8*)0x3B)

#define PORTC		*((volatile uint8*)0x35)
#define DDRC		*((volatile uint8*)0x34)

#define DDRD		*((volatile uint8*)0x31)
#define PORTD		*((volatile uint8*)0x32)

#define PORTB		*((volatile uint8*)0x38)
#define DDRB		*((volatile uint8*)0x37)

#endif
