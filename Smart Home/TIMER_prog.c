
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "defines.h"


#include "TIMER_reg.h"
#include "TIMER_private.h"
#include "TIMER_cfg.h"
#include "TIMER_interface.h"




static uint16 counter ;

//static uint8 TIMERS_u8OVF_Counter  ;



/* Global ARR of pointers to functions */

static void (* TIMERS_pvCallBackFuncArr [8])(void) = {NULL} ;



void TIMER1_voidInit(void)
{
    /* Conigure fast pwm mode */

    SET_BIT(TCCR1A,TCCR1A_COM1A1);
    CLR_BIT(TCCR1A,TCCR1A_COM1A0);


    /* configure waveform generation mode */

    CLR_BIT(TCCR1A,TCCR1A_WGM10);
    SET_BIT(TCCR1A,TCCR1A_WGM11);
    SET_BIT(TCCR1B,TCCR1B_WGM12);
    SET_BIT(TCCR1B,TCCR1B_WGM13);

    /* configure prescaler */

    TCCR1B &= PRESCALER_MASK ;
    TCCR1B |= DIVBY_8;

    /* SET top value */

    ICR1 = TIMER1_TOP_VALUE ;





}


void TIMER1_voidSetCompValue(uint16 Copy_u16Value)
{
    OCR1A = Copy_u16Value;
}


void TIMER1_voidSetTimerVal(uint16 Copy_u16Value)
{
	TCNT1 = Copy_u16Value;
}

uint16 TIMER1_u16GetTimerVal(void)
{
	return TCNT1 ;
}

void ICU_voidInit(void)
{



    /* Timer1 Normal mode */

    CLR_BIT(TCCR1A,TCCR1A_WGM10);
    CLR_BIT(TCCR1A,TCCR1A_WGM11);
    CLR_BIT(TCCR1B,TCCR1B_WGM12);
    CLR_BIT(TCCR1B,TCCR1B_WGM13);

   


    /* configure prescaler */

    TCCR1B &= PRESCALER_MASK ;
    TCCR1B |= TIMER_CLOCK;









 

#if ICU_u8_TRIGGER_SRC == RISSING_EDGE


    SET_BIT(TCCR1B,TCCR1B_ICES1);

#elif ICU_u8_TRIGGER_SRC == FALLING_EDGE

    CLR_BIT(TCCR1B,TCCR1B_ICES1);

#else
#error wrong ICU_u8_TRIGGER_SRC configratioon
#endif




    /* Enable Timer 1 OVF INT*/
   // SET_BIT(TIMSK,TIMSK_TOIE1);


#if ICU_u8_INT_INIT_STATE == ENABLE
    SET_BIT(TIMSK,TIMSK_TICIE1);

#elif ICU_u8_INT_INIT_STATE == DISABLE
    CLR_BIT(TIMSK,TIMSK_TICIE1);

#else 
#error wrong ICU_u8_INT_INIT_STATE CFG
#endif


}


uint8 ICU_voidSetTriggerSrc(uint8 Copy_u8TriggerSrc)
{

    uint8 Local_u8ErrorState = OK ;
    if (Copy_u8TriggerSrc == FALLING_EDGE )
    {
        CLR_BIT(TCCR1B,TCCR1B_ICES1);
    }
    else if (Copy_u8TriggerSrc == RISSING_EDGE)
    {
        SET_BIT(TCCR1B,TCCR1B_ICES1);
    }
    else
    {
        Local_u8ErrorState = NOK;
    }
    
    return Local_u8ErrorState ;
}

uint32 ICU_u32GetVal(void)
{
    return (ICR1);
}



void ICU_voidIntEnable(void)
{

    SET_BIT(TIMSK,TIMSK_TICIE1);

}
void ICU_voidIntDisable(void)
{

    CLR_BIT(TIMSK,TIMSK_TICIE1);
}


uint8 TIMERS_u8SetCallBack( TIMERS_Int_Src_t Copy_u8TimerIntSource ,  void (* Copy_pvCallBackFunction )(void) )
{

    uint8 LOCAL_u8ErrorState = OK ;

    if (Copy_pvCallBackFunction != NULL)
    {
       TIMERS_pvCallBackFuncArr[Copy_u8TimerIntSource]= Copy_pvCallBackFunction ;
    }
    else
    {
        LOCAL_u8ErrorState = NOK ;
    }





    return LOCAL_u8ErrorState ;

}


void TIMER0_voidInit(void)
{

    /* Waveform generation mode : Fast PWM */

    SET_BIT(TCCR0,TCCR0_WGM00);
    SET_BIT(TCCR0,TCCR0_WGM01);


    /* Compare match output mode */

    CLR_BIT(TCCR0,TCCR0_COM00);
    SET_BIT(TCCR0,TCCR0_COM01);


    /* Set prescaler */

    TCCR0 &= PRESCALER_MASK;
    TCCR0 |= TIMER_CLOCK;



    /* Output compare match interrupt enable */

    // SET_BIT(TIMSK,TIMSK_OCIE0);




}
void TIMER0_voidPWMDisable(void)
{

    CLR_BIT(TCCR0,TCCR0_COM00);
    CLR_BIT(TCCR0,TCCR0_COM01);
}


void TIMER0_voidSetCompValue(uint8 Copy_u8Value)
{
    OCR0 = Copy_u8Value ;
}







/* 42 Datasheet vector table */


//
//
///* ISR for TIMER 1 Overflow */
//
//void __vector_9(void)   __attribute((signal));
//
//void __vector_9(void)
//{
//	if (TIMERS_pvCallBackFuncArr[TIMER1_OVF] != NULL)
//	        {
//	             TIMERS_pvCallBackFuncArr[TIMER1_OVF]();
//	        }
//}
//

//
///* ISR for TIMER 0 Overflow */
//
//void __vector_11(void)   __attribute((signal));
//
//void __vector_11(void)
//{
//    counter++;
//    if (counter==7813)
//    {
//
//        counter = 0 ;
//        TCNT0 = PRELOAD;
//
//         TIMERS_pvCallBackFuncArr[TIMER0_OVF]();
//
//    }
//
//}
//
//
//

//
///* ISR for TIMER 0 Copmare match */
//
//void __vector_10 (void)   __attribute((signal));
//
//void __vector_10(void)
//{
//
//
//    counter++;
//    if (counter==1000)
//    {
//
//        counter = 0 ;
//
//        if (TIMERS_pvCallBackFuncArr[TIMER0_COMP] != NULL)
//        {
//             TIMERS_pvCallBackFuncArr[TIMER0_COMP]();
//        }
//
//
//
//
//
//
//    }
//
//}


//
///* ISR for TIMER 1 Capture event */
//
//void __vector_6 (void)   __attribute((signal));
//
//void __vector_6(void)
//{
//
//        if (TIMERS_pvCallBackFuncArr[TIMER1_ICU] != NULL)
//        {
//             TIMERS_pvCallBackFuncArr[TIMER1_ICU]();
//        }
//}
