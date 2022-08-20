#include "../../STD_TYPES.h"
#include "../../BIT_MATH.h"
#include"Interrupt_registers.h"
#include"Interrupt_interface.h"
#include"Interrupt_config.h"

/* define global pointer to function ISR INT0 takes void and return void*/
//void (*EXTINT_PtrINT0Func_ISR)(void)= NULL;

u8 MEXTI_voidEXTINT_SenseControl(u8 copy_u8ControlSense, u8 copy_u8Num_INT)  //post build method
{
	u8 Local_u8statusError = OK;
	switch(copy_u8Num_INT)
	{
		case EXIT_INF0:
		if(copy_u8ControlSense == EXIT_LOW_LEVEL_MODE )
		{
			CLR_BIT(MCUCR_REG ,MCUCR_ISC00);
	        CLR_BIT(MCUCR_REG ,MCUCR_ISC01);
			//peripheral interrupt enable for int0
	        SET_BIT(GICR_REG ,GICR_INT0);
		}

		else if(copy_u8ControlSense == EXIT_ANY_LOGICAL_CHANGE_MODE )
		{
			SET_BIT(MCUCR_REG ,MCUCR_ISC00);
	        CLR_BIT(MCUCR_REG ,MCUCR_ISC01);
			//peripheral interrupt enable for int0
	        SET_BIT(GICR_REG ,GICR_INT0);
		}

		else if(copy_u8ControlSense == EXIT_ANY_FALLING_EDGE_MODE)
		{
			CLR_BIT(MCUCR_REG ,MCUCR_ISC00);
	        SET_BIT(MCUCR_REG ,MCUCR_ISC01);
			//peripheral interrupt enable for int0
	        SET_BIT(GICR_REG ,GICR_INT0);
		}

		else if(copy_u8ControlSense == EXIT_ANY_RISING_EDGE_MODE)
		{
			SET_BIT(MCUCR_REG ,MCUCR_ISC00);
	        SET_BIT(MCUCR_REG ,MCUCR_ISC01);
			//peripheral interrupt enable for int0
	        SET_BIT(GICR_REG ,GICR_INT0);
		}

		else{
					//invalid control Sense
		}
		break;

		case EXIT_INF1:
		if(copy_u8ControlSense == EXIT_LOW_LEVEL_MODE )
		{
			CLR_BIT(MCUCR_REG ,MCUCR_ISC10);
	        CLR_BIT(MCUCR_REG ,MCUCR_ISC11);
			//peripheral interrupt enable for int1
	        SET_BIT(GICR_REG ,GICR_INT1);
		}

		else if(copy_u8ControlSense == EXIT_ANY_LOGICAL_CHANGE_MODE )
		{
			SET_BIT(MCUCR_REG ,MCUCR_ISC10);
	        CLR_BIT(MCUCR_REG ,MCUCR_ISC11);
			//peripheral interrupt enable for int1
	        SET_BIT(GICR_REG ,GICR_INT1);
		}

		else if(copy_u8ControlSense == EXIT_ANY_FALLING_EDGE_MODE)
		{
			CLR_BIT(MCUCR_REG ,MCUCR_ISC10);
	        SET_BIT(MCUCR_REG ,MCUCR_ISC11);
			//peripheral interrupt enable for int1
	        SET_BIT(GICR_REG ,GICR_INT1);
		}

		else if(copy_u8ControlSense == EXIT_ANY_RISING_EDGE_MODE)
		{
			SET_BIT(MCUCR_REG ,MCUCR_ISC10);
	        SET_BIT(MCUCR_REG ,MCUCR_ISC11);
			//peripheral interrupt enable for int1
	        SET_BIT(GICR_REG ,GICR_INT1);
		}

		else{
					//invalid control Sense
		}
		break;
		case EXIT_INF2:
	    if (copy_u8ControlSense == EXIT_ANY_RISING_EDGE_MODE)
	   {
		SET_BIT(MCUCSR_REG ,MCUCSR_INT2);
		SET_BIT(GICR_REG ,GICR_INT2);
	   }
	    else if(copy_u8ControlSense == EXIT_ANY_FALLING_EDGE_MODE)
   	   {
		CLR_BIT(MCUCSR_REG ,MCUCSR_INT2);
		SET_BIT(GICR_REG ,GICR_INT2);
	   }
		else{
					//invalid control Sense
		}
		break;

  	default:
  		 Local_u8statusError= NOT_OK;
  		break;
  	}
	return Local_u8statusError;
}

u8 MEXTI_voidEXTINT_Enable(u8 copy_u8Num_INT)
{
	u8 local_U8Enable_error = OK;
		switch(copy_u8Num_INT)
		{
			case EXIT_INF0:
			SET_BIT(GICR_REG ,GICR_INT0);
			break;

			case EXIT_INF1:
			SET_BIT(GICR_REG ,GICR_INT1);
			break;

			case EXIT_INF2:
			SET_BIT(GICR_REG ,GICR_INT2);
			break;

			default:
				local_U8Enable_error = NOT_OK;
		    break;
		}
		 return local_U8Enable_error ;
	}



u8 MEXTI_voidEXTINT_Disable(u8 copy_u8Num_INT)
{
	u8 local_U8Disable_error = OK;
	switch(copy_u8Num_INT)
	{
		case EXIT_INF0:
		CLR_BIT(GICR_REG ,GICR_INT0);
		break;

		case EXIT_INF1:
		CLR_BIT(GICR_REG ,GICR_INT1);
		break;

		case EXIT_INF2:
		CLR_BIT(GICR_REG ,GICR_INT2);
		break;

		default:
			local_U8Disable_error = NOT_OK;
	    break;
	}
	 return local_U8Disable_error ;
}


