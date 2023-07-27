
#include "STD_TYPES.h"
#include <util/delay.h>
#include "MAP.h"

#include "TIMER_interface.h"
#include "UART_interface.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "ADC_interface.h"
#include "GIE_interface.h"
#include "EXTI_interface.h"

#include "KPD_interface.h"
#include "CLCD_interface.h"
#include "LDR.h"

#include "APP.h"




void main (void)
{

    PORT_voidInit();
    UART_voidInit();
    ADC_voidInit();

    APP_voidLogin();


    uint8 Number = 0  ;



    while (1)
    {

		
		Check = Number ;
		
    	
        Number = UART_voidReceiveData();


    	switch (Number)
    	{
			case '1':
				DIO_u8SetPortValue(DIO_u8PORTC,0xff);
				break;
			case '2':
				DIO_u8SetPortValue(DIO_u8PORTC,0u);
					break;
			case '3':
				APP_voidControlLight();
			    	break;
			case '4':
				APP_voidOpenDoor();
					break;
			case '5':
		      	APP_voidCloseDoor();
					break;
			case '6':
				DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN3,DIO_u8PIN_HIGH);
			    	break;
		    case '7':
		    	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN3,DIO_u8PIN_LOW);
				     break;

		    case '8':
		    	APP_voidControlFanSpeed();
				    break;


			default:
				break;
		}
    }




}











