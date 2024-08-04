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





/* Function to convert analog volt from LDR to digital value using ADC*/

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

    /* PWM mode in timer1 with top value = 40000 to control the duty cycle   */
	TIMER1_voidInit();
	TIMER1_voidSetCompValue(6000);


}


void APP_voidCloseDoor(void)
{
    /* PWM mode in timer1 with top value = 40000 to control the duty cycle   */
	TIMER1_voidInit();
	TIMER1_voidSetCompValue(1000);

}










void APP_voidControlFanSpeed(void)
{

    uint8 check =100 ;

    /* fast PWM mode */
	TIMER0_voidInit();
	
	while(check > 10)
	{
        
        /* Get the analog volt from the  Potentiometer and map it */
		TIMER0_voidSetCompValue(Map(0,255,0,250,ADC_u8GetChannelReading(ADC_SINGLE_ENDED_CH0)));

        check = ADC_u8GetChannelReading(ADC_SINGLE_ENDED_CH0) ;
	}

    TIMER0_voidPWMDisable();
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

        else if (ID==0 && Password ==1)
        {

            CLCD_voidSendCmd(1);

            CLCD_u8SendString("Invalid Id ");



            LoginI--;

        }


        else if (ID==1 && Password ==0)
        {

            CLCD_voidSendCmd(1);

            CLCD_u8SendString("Invalid Password");



            LoginI--;

        }
        else if (ID==0 && Password ==0)
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

