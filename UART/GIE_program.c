/*
 * GIE_program.c
 *
 *  
 *      Author: Eslam Nasr
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GIE_interface.h"
#include "GIE_reg.h"


void GIE_voidEnableglobal(void)
{
	/*  SET_BIT(SREG, SREG_I);  */

	__asm __volatile("SEI"); /*Inline assembly instruction to set 1 bit*/
}




void GIE_voidDisableglobal(void)
{
	/*  CLR_BIT(SREG, SREG_I); */

	__asm __volatile("CLI"); /*Inline assembly instruction to clear 1 bit*/
}
