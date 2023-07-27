/*
 * ISR_cfg.h
 *
 *      Author: Eslam Nasr
 */

#ifndef EXTI_CFG_H_
#define EXTI_CFG_H_

/**
 * @details configure the INT0 sense control, options are            1- EXTI_u8FALLING_EDGE
 * 																	 2- EXTI_u8RISING_EDGE
 * 																	 3- EXTI_u8FALLING_EDGE
 * 	           														 4- EXTI_u8RISING_EDGE
 */

#define INT0_SENSE_CTRL    		 EXTI_u8RISING_EDGE
/**
 * @details configure the INT0 sense control interrupt, options are:  1- ENABLE
 * 																	  2- DISAPLE
 */
#define INT0_INITIAL_STATE 		 ENABLE

/**
 * @details configure the INT1 sense control, options are            1- EXTI_u8FALLING_EDGE
 * 																	 2- EXTI_u8RISING_EDGE
 * 																	 3- EXTI_u8FALLING_EDGE
 * 																	 4- EXTI_u8RISING_EDGE
 */
#define INT1_SENSE_CTRL    		 EXTI_u8FALLING_EDGE
/**
 * @details configure the INT1 sense control interrupt, options are:  1- ENABLE
 * 																	  2- DISAPLE
 */
#define INT1_INITIAL_STATE 		 ENABLE

/**
 * @details configure the INT2 sense control, options are            1- EXTI_u8FALLING_EDGE
 * 																	 2- EXTI_u8RISING_EDGE
 */
#define INT2_SENSE_CTRL    		 EXTI_u8FALLING_EDGE

/**
 * @details configure the INT2 sense control interrupt, options are:  1- ENABLE
 * 																	  2- DISAPLE
 */
#define INT2_INITIAL_STATE 		 ENABLE



#endif /* ISR_CFG_H_ */
