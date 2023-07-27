

#ifndef ADC_REG_H_
#define ADC_REG_H_


#include "STD_TYPES.h"

/*  DATASHEET 212  */


#define SFIOR            *( (volatile uint8*) 0x50)


#define ADMUX            *( (volatile uint8*) 0x27)     /* ADC multiplexer selection register */
#define ADMUX_REFS1      7                              /* Refrence selection Bit1 */
#define ADMUX_REFS0      6                              /* Refrence selection Bit0 */
#define ADMUX_ADLAR      5                              /* Left adjust result */



#define ADCSRA           *( (volatile uint8*) 0x26)      /* ADC Control and Status register */
#define ADCSRA_ADEN      7                               /* Enable */
#define ADCSRA_ADSC      6                               /* Start conversion */
#define ADCSRA_ADATE     5                               /* Auto trigger enable */
#define ADCSRA_ADIF      4                               /* Interrupt flag */
#define ADCSRA_ADIE      3                               /* Interrupt Enable */



#define ADCH             *( (volatile uint8*) 0x25)      /* Data high register */
#define ADCL             *( (volatile uint8*) 0x24)      /* Data low register */
#define ADC              *( (volatile uint16*) 0x24)     /* ADC Data register */









#endif