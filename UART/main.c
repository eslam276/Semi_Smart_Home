
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

void APP_voidPlayMusic(void);

void APP_voidControlFanSpeed(void);
void APP_voidControlFan(void);

void Login(void);



int main (void)
{

    PORT_voidInit();

    UART_voidInit();
    ADC_voidInit();



    Login();


    uint8 Number = 0  ;


    while(1)
    {

    }



    while (1)
    {

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




    return 0 ;
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
//
//	uint32 Local_u8Counter;
//
//			for ( Local_u8Counter = 100; Local_u8Counter < 6000; Local_u8Counter++)
//			{
//				TIMER1_voidSetCompValue(Local_u8Counter);
//			}

}
void APP_voidCloseDoor(void)
{

	TIMER1_voidInit();
	TIMER1_voidSetCompValue(1000);

//
//	uint32 Local_u8Counter;
//
//			for ( Local_u8Counter = 6000; Local_u8Counter >100; Local_u8Counter--)
//			{
//				TIMER1_voidSetCompValue(Local_u8Counter);
//			}

}





void APP_voidPlayMusic(void)
{

	while (1)
	{
		uint32 Local_u8Counter;

		for ( Local_u8Counter = 0; Local_u8Counter < 20000; Local_u8Counter++)
		{
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN5,DIO_u8PIN_HIGH);
			_delay_ms(10);

		}


	}


}






















void APP_voidControlFan(void)
{

}





























































































uint8 TIMER_u8OVFCounter ;

void func2(void)
{
	TIMER_u8OVFCounter++ ;
}


uint8 counter ;

 uint32  read1, read2 ;
void func(void)
{

	counter++;

	if(counter==1)
		{

		//read1 = ICU_u32GetVal();
		TIMER1_voidSetTimerVal(0u);
		read1 = TIMER1_u16GetTimerVal();
		//EXTI_u8SetSenseCtrl(EXTI_u8INT0,EXTI_u8Falling_EDGE);
		//ICU_voidSetTriggerSrc(FALLING_EDGE);



		}
	else if(counter==2)
		{
		read2 = TIMER1_u16GetTimerVal();

		//GIE_voidDisableglobal();
		EXTI_u8SetSenseCtrl(EXTI_u8INT0,EXTI_u8RISING_EDGE);


		//counter = 0 ;






		}




}

 uint32 distance  , time ;

void APP_voidControlFanSpeed(void)
{

//	        TIMERS_u8SetCallBack(TIMER1_OVF,&func2);
//	        TIMERS_u8SetCallBack(TIMER1_ICU,&func);


					TIMER0_voidInit();
					 CLCD_voidInit();
					while(1)
					{
					TIMER0_voidSetCompValue(Map(0,255,0,250,ADC_u8GetChannelReading(ADC_SINGLE_ENDED_CH0)));


					}
	        CLCD_voidInit();

	        ICU_voidInit();

	        EXTI_voidInitInt0();
			EXTI_u8SetSenseCtrl(EXTI_u8INT0,EXTI_u8RISING_EDGE);
	        EXTI_u8SetCallBack(EXTI_u8INT0,&func);





			while(1)
			{



				TIMER_u8OVFCounter= 0 ;
				counter = 0 ;
				read2 = 0 ;
				read1 = 0;





				GIE_voidEnableglobal();




				DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_HIGH);
				_delay_us(13);
				DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_LOW);

				DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_HIGH);
				_delay_us(13);
				DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_LOW);

				while(read2==0);
				GIE_voidDisableglobal();








				//+TIMER_u8OVFCounter*0xffff

				time = (((read2  ))/400);

				distance = (3.4*time);

				//distance = TIMER_u8OVFCounter;

				//distance = (((read2+TIMER_u8OVFCounter*0xffff )-read1) / 200) * 3.4 ;

				CLCD_voidSendCmd(1);
				CLCD_voidSendNumber(counter);

				if(distance>30)
				{
					distance = 30 ;
				}



				TIMER0_voidInit();
				TIMER0_voidSetCompValue(Map(0,1023,0,250,ADC_u8GetChannelReading(ADC_SINGLE_ENDED_CH0)));
				//TIMER0_voidSetCompValue(250);

//				CLCD_voidSendNumber(read2);
//				CLCD_voidGoToXY(0,1);
//				CLCD_voidSendNumber(read1);
			//	_delay_ms(1000);




				//












			}

}











void Login(void)
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

