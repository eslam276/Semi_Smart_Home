/**************************************************************/
/**************************************************************/
/*********		Author: Eslam Nasr   		*******************/
/*********		File: EXTI_CFG.h			*******************/
/*********		Version: 1.00				*******************/
/**************************************************************/
/**************************************************************/

/**
 * @file EXTI_interface.h
 * @author  Eslam Nasr
 * @brief This
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define EXTI_u8INT0          0u
#define EXTI_u8INT1          1u
#define EXTI_u8INT2          2u

#define EXTI_u8LOW_LEVEL           1u
#define EXTI_u8ON_CHANGE           2u
#define EXTI_u8Falling_EDGE  	   4u
#define EXTI_u8RISING_EDGE         3u



void EXTI_voidInitInt0(void);
void EXTI_voidInitInt1(void);
void EXTI_voidInitInt2(void);

uint8 EXTI_u8SetSenseCtrl(uint8 Copy_u8IntNum, uint8 Copy_u8Sense);
uint8 EXTI_u8InterputStatus(uint8 Copy_u8IntNum, uint8 Copy_u8Status);

uint8 EXTI_u8SetCallBack(uint8 Copy_u8Num, pfFuncPtr Copy_fpFunction);
#endif /* ISR_INTERDACE_H_ */
