#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "defines.h"

#include "EXTI_interface.h"
#include "EXTI_reg.h"

#include "EXTI_cfg.h"

static void (*EXTI_pfINTFuncPtr[3])(void)= {NULL};/*array of pointers to functions to hold ISR callback*/

void EXTI_voidInitInt0(void)
{
#if INT0_SENSE_CTRL == EXTI_u8LOW_LEVEL
	CLR_BIT(MCUCR, MCUCR_ISC00);
	CLR_BIT(MCUCR, MCUCR_ISC01);
#elif INT0_SENSE_CTRL == EXTI_u8ON_CHANGE
	SET_BIT(MCUCR, MCUCR_ISC00);
	CLR_BIT(MCUCR, MCUCR_ISC01);
#elif INT0_SENSE_CTRL == EXTI_u8RISING_EDGE
	CLR_BIT(MCUCR, MCUCR_ISC00);
	SET_BIT(MCUCR, MCUCR_ISC01);
#elif INT0_SENSE_CTRL == EXTI_u8FALLING_EDGE
	SET_BIT(MCUCR, MCUCR_ISC00);
	SET_BIT(MCUCR, MCUCR_ISC01);
#else
#error Wrong INT0_SENSE_CTRL configuration option
#endif

#if INT0_INITIAL_STATE  == DISABLE
	CLR_BIT(GICR, GICR_INIT0);
#elif INT0_INITIAL_STATE  == ENABLE
	SET_BIT(GICR, GICR_INIT0);
#else
#error Wrong INT0_SENSE_CTRL configuration option
#endif
	return;
}
void EXTI_voidInitInt1(void)
{
#if INT1_SENSE_CTRL == EXTI_u8LOW_LEVEL
	CLR_BIT(MCUCR, MCUCR_ISC10);
	CLR_BIT(MCUCR, MCUCR_ISC11);
#elif INT1_SENSE_CTRL == EXTI_u8ON_CHANGE
	SET_BIT(MCUCR, MCUCR_ISC10);
	CLR_BIT(MCUCR, MCUCR_ISC11);
#elif INT1_SENSE_CTRL == EXTI_u8RISING_EDGE
	CLR_BIT(MCUCR, MCUCR_ISC10);
	SET_BIT(MCUCR, MCUCR_ISC11);
#elif INT1_SENSE_CTRL == EXTI_u8FALLING_EDGE
	SET_BIT(MCUCR, MCUCR_ISC10);
	SET_BIT(MCUCR, MCUCR_ISC11);
#else
#error Wrong INT1_SENSE_CTRL configuration option
#endif

#if INT1_INITIAL_STATE  == DISABLE
	CLR_BIT(GICR, GICR_INIT0);
#elif INT1_INITIAL_STATE  == ENABLE
	SET_BIT(GICR, GICR_INIT1);
#else
#error Wrong INT0_SENSE_CTRL configuration option
#endif
	return;
}

void EXTI_voidInitInt2(void)
{
#if INIT2_SENSE_CTRL == EXTI_u8RISING_EDGE
	CLR_BIT(MCUCR, MCUCR_ISC2);
#elif INIT2_SENSE_CTRL == EXTI_u8FALLING_EDGE
	SET_BIT(MCUCR, MCUCR_ISC2);
#else
#error Wrong INIT2_SENSE_CTRL configuration option
#endif

#if INT2_INITIAL_STATE  == DISABLE
	CLR_BIT(GICR, GICR_INIT2);
#elif INT2_INITIAL_STATE  == ENABLE
	SET_BIT(GICR, GICR_INIT2);
#else
#error Wrong INT2_SENSE_CTRL configuration option
#endif
	return;
}
uint8 EXTI_u8SetSenseCtrl(uint8 Copy_u8IntNum, uint8 Copy_u8Sense)
{
	uint8 Local_u8ErrorState = OK;
	switch (Copy_u8IntNum)
	{
	case EXTI_u8INT0:
		switch (Copy_u8Sense)
		{
			case EXTI_u8LOW_LEVEL: CLR_BIT(MCUCR, MCUCR_ISC00);     CLR_BIT(MCUCR, MCUCR_ISC00); break;
			case EXTI_u8ON_CHANGE: SET_BIT(MCUCR, MCUCR_ISC00);     CLR_BIT(MCUCR, MCUCR_ISC00); break;
			case EXTI_u8Falling_EDGE: CLR_BIT(MCUCR, MCUCR_ISC00);  SET_BIT(MCUCR, MCUCR_ISC00); break;
			case EXTI_u8RISING_EDGE: SET_BIT(MCUCR, MCUCR_ISC00);     SET_BIT(MCUCR, MCUCR_ISC00); break;
			default: Local_u8ErrorState = NOK; break;
		}
	break;
	case EXTI_u8INT1:
		switch (Copy_u8Sense)
		{
			case EXTI_u8LOW_LEVEL: CLR_BIT(MCUCR, MCUCR_ISC10);  CLR_BIT(MCUCR, MCUCR_ISC11); break;
			case EXTI_u8ON_CHANGE: SET_BIT(MCUCR, MCUCR_ISC10);  CLR_BIT(MCUCR, MCUCR_ISC11); break;
			case EXTI_u8Falling_EDGE: CLR_BIT(MCUCR, MCUCR_ISC10);  SET_BIT(MCUCR, MCUCR_ISC11); break;
			case EXTI_u8RISING_EDGE: SET_BIT(MCUCR, MCUCR_ISC10);  SET_BIT(MCUCR, MCUCR_ISC11); break;
			default:break;
		}
		break;
	case EXTI_u8INT2:
		switch (Copy_u8Sense)
		{
			case EXTI_u8Falling_EDGE: CLR_BIT(MCUCR, MCUCR_ISC2);  SET_BIT(MCUCR, MCUCR_ISC2); break;
			case EXTI_u8LOW_LEVEL: SET_BIT(MCUCR, MCUCR_ISC2);  SET_BIT(MCUCR, MCUCR_ISC2); break;
			default:break;
		}
		break;
		default:Local_u8ErrorState = NOK;
			break;
	}
	return Local_u8ErrorState;
}
uint8 EXTI_u8InterputStatus(uint8 Copy_u8IntNum, uint8 Copy_u8Status)
{
	uint8 Local_u8ErrorState = OK;

	if (Copy_u8IntNum == EXTI_u8INT0)
	{
		switch (Copy_u8Status)
		{
		case ENABLE: SET_BIT(GICR, GICR_INIT0);
			break;
		case DISABLE: CLR_BIT(GICR, GICR_INIT0);
			break;
		}
	}
	else if (Copy_u8IntNum == EXTI_u8INT1)
	{
		switch (Copy_u8Status)
		{
		case ENABLE: SET_BIT(GICR, GICR_INIT1);
			break;
		case DISABLE: CLR_BIT(GICR, GICR_INIT1);
			break;
		default:
			break;
		}
	}
	else if (Copy_u8IntNum == EXTI_u8INT2)
	{
		switch (Copy_u8Status)
		{
		case ENABLE: SET_BIT(GICR, GICR_INIT2);
			break;
		case DISABLE: CLR_BIT(GICR, GICR_INIT2);
			break;
		default:
			break;

		}
	}
	else Local_u8ErrorState = NOK;
	return Local_u8ErrorState;
}

uint8 EXTI_u8SetCallBack(uint8 Copy_u8Num,  void (*Copy_pfFuncPtr)(void))
{
	uint8 Local_u8ErrorState = OK;
	if(Copy_pfFuncPtr != NULL)
	{
		EXTI_pfINTFuncPtr[Copy_u8Num] = Copy_pfFuncPtr;
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}


void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	if (EXTI_pfINTFuncPtr[EXTI_u8INT0] != NULL)
	{
		EXTI_pfINTFuncPtr[EXTI_u8INT0]();
	}
}
void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
	if (EXTI_pfINTFuncPtr[EXTI_u8INT1] != NULL)
	{
		EXTI_pfINTFuncPtr[EXTI_u8INT1]();
	}
}
void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
	if (EXTI_pfINTFuncPtr[EXTI_u8INT2] != NULL)
	{
		EXTI_pfINTFuncPtr[EXTI_u8INT2]();
	}
}
