/**************************************************************/
/**************************************************************/
/*********		Author: Eslam Nasr   		*******************/
/*********		File: PORT_CFG.h			*******************/
/*********		Version: 1.00				*******************/
/**************************************************************/
/**************************************************************/


#ifndef PORT_CFG_H_
#define PORT_CFG_H_

/*Configure pins direction, options 1- INPUT
									2- OUTPUT*/
	
#define PORTA_PIN0_DIR           INPUT
#define PORTA_PIN1_DIR           OUTPUT
#define PORTA_PIN2_DIR           OUTPUT
#define PORTA_PIN3_DIR           OUTPUT
#define PORTA_PIN4_DIR           OUTPUT
#define PORTA_PIN5_DIR           OUTPUT
#define PORTA_PIN6_DIR           OUTPUT
#define PORTA_PIN7_DIR           INPUT

#define PORTB_PIN0_DIR           OUTPUT
#define PORTB_PIN1_DIR           INPUT
#define PORTB_PIN2_DIR           INPUT
#define PORTB_PIN3_DIR           OUTPUT
#define PORTB_PIN4_DIR           INPUT
#define PORTB_PIN5_DIR           INPUT
#define PORTB_PIN6_DIR           INPUT
#define PORTB_PIN7_DIR           INPUT

#define PORTC_PIN0_DIR           OUTPUT
#define PORTC_PIN1_DIR           OUTPUT
#define PORTC_PIN2_DIR           OUTPUT
#define PORTC_PIN3_DIR           OUTPUT
#define PORTC_PIN4_DIR           OUTPUT
#define PORTC_PIN5_DIR           OUTPUT
#define PORTC_PIN6_DIR           OUTPUT
#define PORTC_PIN7_DIR           OUTPUT

#define PORTD_PIN0_DIR           INPUT
#define PORTD_PIN1_DIR           OUTPUT
#define PORTD_PIN2_DIR           OUTPUT
#define PORTD_PIN3_DIR           OUTPUT
#define PORTD_PIN4_DIR           OUTPUT
#define PORTD_PIN5_DIR           OUTPUT
#define PORTD_PIN6_DIR           INPUT
#define PORTD_PIN7_DIR           INPUT


/*configure the Initialization of pins value, options for input pin     1-FLOATING
 * 																    	2-PULLED_UP
 *											  options for output pin    1- HIGH
								  	  	  	  	  	  	  	  	        2- LOW*/

#define PORTA_PIN0_INIT_VAL           LOW
#define PORTA_PIN1_INIT_VAL           LOW
#define PORTA_PIN2_INIT_VAL           LOW
#define PORTA_PIN3_INIT_VAL           LOW
#define PORTA_PIN4_INIT_VAL           LOW
#define PORTA_PIN5_INIT_VAL           LOW
#define PORTA_PIN6_INIT_VAL           LOW
#define PORTA_PIN7_INIT_VAL           LOW

#define PORTB_PIN0_INIT_VAL           LOW
#define PORTB_PIN1_INIT_VAL           LOW
#define PORTB_PIN2_INIT_VAL           LOW
#define PORTB_PIN3_INIT_VAL           LOW
#define PORTB_PIN4_INIT_VAL           PULLED_UP
#define PORTB_PIN5_INIT_VAL           PULLED_UP
#define PORTB_PIN6_INIT_VAL           PULLED_UP
#define PORTB_PIN7_INIT_VAL           PULLED_UP

#define PORTC_PIN0_INIT_VAL           LOW
#define PORTC_PIN1_INIT_VAL           LOW
#define PORTC_PIN2_INIT_VAL           LOW
#define PORTC_PIN3_INIT_VAL           LOW
#define PORTC_PIN4_INIT_VAL           LOW
#define PORTC_PIN5_INIT_VAL           LOW
#define PORTC_PIN6_INIT_VAL           LOW
#define PORTC_PIN7_INIT_VAL           LOW

#define PORTD_PIN0_INIT_VAL           LOW
#define PORTD_PIN1_INIT_VAL           LOW
#define PORTD_PIN2_INIT_VAL           HIGH
#define PORTD_PIN3_INIT_VAL           HIGH
#define PORTD_PIN4_INIT_VAL           HIGH
#define PORTD_PIN5_INIT_VAL           HIGH
#define PORTD_PIN6_INIT_VAL           FLOATING
#define PORTD_PIN7_INIT_VAL           LOW

#endif
