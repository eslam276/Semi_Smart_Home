

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "defines.h"

#include "ADC_reg.h"
#include "ADC_cfg.h"


void ADC_voidInit(void)
{




    /* Set voltage refrence  */


    #if ADC_u8REF_VOLT == AREF_REF

        CLR_BIT(ADMUX,ADMUX_REFS0);
        CLR_BIT(ADMUX,ADMUX_REFS1);

    #elif ADC_u8REF_VOLT == AVCC_REF


        SET_BIT(ADMUX,ADMUX_REFS0);
        CLR_BIT(ADMUX,ADMUX_REFS1);


    #elif ADC_u8REF_VOLT == INTERNAL_2560mV_REF

        SET_BIT(ADMUX,ADMUX_REFS0);
        SET_BIT(ADMUX,ADMUX_REFS1);


    #else 

        #error Wrong ADC_u8REF_VOLT confegration option 


    #endif








    /* Set ADC Left Adjust Result */

    #if ADC_u8RESOLUTION == EIGHT_BITS

         SET_BIT(ADMUX,ADMUX_ADLAR);

    #elif ADC_u8RESOLUTION == TEN_BITS

         CLR_BIT(ADMUX,ADMUX_ADLAR);

    #else 

        #error Wrong ADC_u8RESOLUTION confegration option 

    #endif






    /* ADC  Auto trigger */


    #if ADC_u8AUTO_TRIGGER   == ENABLE

         SET_BIT(ADCSRA,ADCSRA_ADATE);

    #elif ADC_u8AUTO_TRIGGER == DISABLE

         CLR_BIT(ADCSRA,ADCSRA_ADATE);

    #else 

        #error Wrong ADC_u8AUTO_TRIGGER confegration option 

    #endif




    /* ADC  Interrupt enable */

    #if ADC_u8INT_ENABLE   == ENABLE

         SET_BIT(ADCSRA,ADCSRA_ADIE);

    #elif ADC_u8INT_ENABLE == DISABLE

         CLR_BIT(ADCSRA,ADCSRA_ADIE);

    #else 

        #error Wrong ADC_u8INT_ENABLE confegration option 

    #endif

     





    /* Configure ADC prescaler bits */


    ADCSRA &= PRESCALER_MASK ;
    ADCSRA |= ADC_u8PRESCALER_VAL ;



    /* ADC Enable */

    SET_BIT(ADCSRA,ADCSRA_ADEN); 






}



uint16 ADC_u8GetChannelReading(uint8 Copy_u8Channel)
{

    ADMUX &= CHANNEL_MASK;
    ADMUX |= Copy_u8Channel ;



    /* Start Conversion */

    SET_BIT(ADCSRA,ADCSRA_ADSC);



    /* Reading the flag */

    while (GET_BIT(ADCSRA,ADCSRA_ADIF)== 0)
    {
        /* code */
    }

    /* clear the conversion complete flag */
    SET_BIT(ADCSRA,ADCSRA_ADIF);


    #if ADC_u8RESOLUTION == EIGHT_BITS

        return ADCH ;


    #elif ADC_u8RESOLUTION == TEN_BITS

        return ADC ;

    #else

        #error Wrong ADC_u8RESOLUTION confegration option 

    #endif

}


