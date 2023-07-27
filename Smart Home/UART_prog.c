/*
 * UART_prog.c
 *
 *  
 *      Author: Eslam Nasr
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "defines.h"
#include "UART_cfg.h"
#include "UART_interface.h"
#include "UART_private.h"

#include "UART_reg.h"


void UART_voidInit(void)
{
	uint8 Local_u8UCSRCVal = 0u;
	/*enable transmitter receiver*/
	SET_BIT(UCSRB, UCSRB_TXEN);
	SET_BIT(UCSRB, UCSRB_RXEN);

	
	/*Asynch mode*/
	CLR_BIT(Local_u8UCSRCVal, UCSRC_UMSEL);

	/*Disable parity*/
	CLR_BIT(Local_u8UCSRCVal, UCSRC_UPM1);
	CLR_BIT(Local_u8UCSRCVal, UCSRC_UPM0);

	/*1 Stop bit*/
	CLR_BIT(Local_u8UCSRCVal, UCSRC_USBS);


	/*Character size 8 bits*/

	SET_BIT(Local_u8UCSRCVal, UCSRC_UCSZ1);
	SET_BIT(Local_u8UCSRCVal, UCSRC_UCSZ0);

	/* Register select UCSRC*/
	SET_BIT(Local_u8UCSRCVal,UCSRC_URSEL);



	UCSRC = Local_u8UCSRCVal ;

	/*Baud Rate = 9600 bps */
	UBRRL = 103u ;

}

void UART_voidSendData(uint8 Copy_u8Data)
{
	/* Wait until the transmit buffer is ready */

	while((GET_BIT(UCSRA ,UCSRA_UDRE)) == 0)
	{
	}
	UDR = Copy_u8Data;

}


uint8 UART_voidReceiveData(void)
{
	/* Wait until the Recieve  buffer is ready */

	while((GET_BIT(UCSRA ,UCSRA_RXC)) == 0)
	{
	}
	return UDR;

}











uint8 UART_u8SendString(uint8 * Copy_pu8String)
{
	uint8 Local_u8ErrorState= OK ;
	if(Copy_pu8String != NULL)
	{
		uint8 Local_u8Counter = 0 ;
		while(Copy_pu8String[Local_u8Counter] != '\0')
		{
			UART_voidSendData(Copy_pu8String[Local_u8Counter]);
			Local_u8Counter++;
		}

	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}
	return Local_u8ErrorState;
}


uint8 UART_u8RecieveString(uint8 * Copy_pu8String , uint8 Copy_u8Size)
{
	uint8 Local_u8ErrorState= OK ;

		if(Copy_pu8String != NULL)
		{
			uint8 Local_u8Counter  ;

			for(Local_u8Counter = 0  ; Local_u8Counter< Copy_u8Size ; Local_u8Counter++ )
			{
				Copy_pu8String[Local_u8Counter] = UART_voidReceiveData();
			}


		}
		else
		{
			Local_u8ErrorState = NULL_PTR_ERR;
		}
		return Local_u8ErrorState;
}

