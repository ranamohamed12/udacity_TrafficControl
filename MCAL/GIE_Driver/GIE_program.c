#include "../../STD_TYPES.h"
#include "../../BIT_MATH.h"
#include"GIE_registers.h"
#include"GIE_interface.h"

void MGIE_voidGIEEnable(void)
{
	SET_BIT(GIE_SREG,GIE_I);
}

void MGIE_voidGIEDisable(void)
{
	CLR_BIT(GIE_SREG, GIE_I);
}
