
#include "STD_TYPES.h"
#include <util/delay.h>
#include "MAP.h"

#include "TIMER_interface.h"
#include "PORT_interface.h"
#include "UART_interface.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "PORT_interface.h"
#include "KPD_interface.h"
#include "ADC_interface.h"
#include "GIE_interface.h"
#include "EXTI_interface.h"

#include "LDR.h"

void APP_voidControlLight(void);
void APP_voidOpenDoor(void);
void APP_voidCloseDoor(void);
void APP_voidControlFanSpeed(void);
void APP_voidLogin(void);



void main (void)
{

    PORT_voidInit();
    UART_voidInit();
    ADC_voidInit();

    APP_voidLogin();


    uint8 Number = 0  ;
	uint8 Check = 0 ;



    while (1)
    {

		
		while (1)
		{
			Number = UART_voidReceiveData();

			if (Number!=Check)
			{
				break;
			}
			
		}

		Check = Number ;
		
    	



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















void APP_voidControlLight(void)
{
	uint8   LOCAL_u8Light , LOCAL_u8LedNum  ;
	LOCAL_u8Light =   LDR_u16GetAnalogVolt(ADC_u8GetChannelReading(ADC_SINGLE_ENDED_CH7));

	LOCAL_u8LedNum = LOCAL_u8Light/10  ;
	DIO_u8SetPortValue(DIO_u8PORTC,(0xFF>>(LOCAL_u8LedNum)));
	_delay_ms(100);
}








void APP_voidOpenDoor(void)
{

	TIMER1_voidInit();
	TIMER1_voidSetCompValue(6000);


}


void APP_voidCloseDoor(void)
{

	TIMER1_voidInit();
	TIMER1_voidSetCompValue(1000);

}










void APP_voidControlFanSpeed(void)
{


	TIMER0_voidInit();
	CLCD_voidInit();
	while(1)
	{

		TIMER0_voidSetCompValue(Map(0,255,0,250,ADC_u8GetChannelReading(ADC_SINGLE_ENDED_CH0)));

	}
}







void APP_voidLogin(void)
{

	 CLCD_voidInit();


    uint8 LOCAL_u8Id[4] = {1,2,3,4} , LOCAL_u8Password[4] = {4,3,2,1} ;

	uint8 LOCAL_u8CheckId[4] = {1,2,3,4} , LOCAL_u8CheckPassword[4] = {4,3,2,1} ;

    uint8 ID = 1 , Password = 1 ;

    uint8 LoginI = 3 ;



    CLCD_voidGoToXY(3,0);

    CLCD_u8SendString("Welcome...");

    _delay_ms(2000);

    while (LoginI)
    {



    	 ID = 1 ;
    	 Password = 1 ;





        CLCD_voidSendCmd(1);

        CLCD_u8SendString("Enter ID : ");
        CLCD_voidGoToXY(0,1);

        int m = 0xff;
        int i =4;

        while(i)
        {
            m = KPD_u8GetPressedKey();

            if(m!= 0xff)
            {

                LOCAL_u8CheckId[4-i] = m ;
                i--;

                CLCD_voidSendNumber(m);
            }
        }



        for(i=0 ; i<4 ; i++)
        {
            if(LOCAL_u8CheckId[i]!=LOCAL_u8Id[i])
            {

                ID = 0 ;

            }
        }







        CLCD_voidSendCmd(1);

        CLCD_u8SendString("Enter Password:");
        CLCD_voidGoToXY(0,1);

            m = 0xff;
            i =4;

        while(i)
        {
            m = KPD_u8GetPressedKey();

            if(m!= 0xff)
            {

                LOCAL_u8CheckPassword[4-i] = m ;
                i--;

                CLCD_voidSendNumber(m);
            }
        }



        for(i=0 ; i<4 ; i++)
        {
            if(LOCAL_u8CheckPassword[i]!=LOCAL_u8Password[i])
            {
                Password=0;
            }

        }






        if (ID && Password)
        {


            CLCD_voidSendCmd(1);

            CLCD_u8SendString("Welcome Eslam");
             _delay_ms(2000);

            break;

        }

        else if (ID==0 & Password ==1)
        {

            CLCD_voidSendCmd(1);

            CLCD_u8SendString("Invalid Id ");



            LoginI--;

        }


        else if (ID==1 & Password ==0)
        {

            CLCD_voidSendCmd(1);

            CLCD_u8SendString("Invalid Password");



            LoginI--;

        }
        else if (ID==0 & Password ==0)
        {

            CLCD_voidSendCmd(1);

           CLCD_u8SendString("Invalid Id");

            CLCD_voidGoToXY(0,1);

            CLCD_u8SendString("Invalid Password");



            LoginI--;

        }


        if(LoginI)

        {
        			_delay_ms(2000);

                   CLCD_voidSendCmd(1);

                   CLCD_u8SendString("Try Again..");
                    _delay_ms(2000);

        }



    }


    if (ID && Password)
    {
        /* code */
    }

    else
    {
    	_delay_ms(2000);

        CLCD_voidSendCmd(1);

        CLCD_u8SendString("Invalid Login ");



        while (1)
        {
            /* code */
        }

    }






}

