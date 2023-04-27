/****************************************************/
/*  Author      :   Mostafa Ahmed El-Sayed          */
/*  File Name   :   STK_program.c                   */
/*  Version     :   V01                             */
/*  Date        :   06/02/2023                      */
/****************************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"STK_interface.h"
#include"STK_private.h"
#include"STK_config.h"


/* Define Callback Global Variable */
void (*STK_CallBack)(void);

/* Define Variable for interval mode */
u8 STK_u8Mode;

void MSTK_voidInit(void)
{
    #if CLOCK_SOURCE == STK_AHB
        SET_BIT(STK -> CTRL, 2);
    #elif CLOCK_SOURCE == STK_AHB_8
        CLR_BIT(STK -> CTRL, 2);
    #endif

	STK -> LOAD = 0 ; 
	STK -> VAL  = 0 ; 
}

void MSTK_voidSetBusyWait( u32 Copy_u32Ticks )
{
	/* Load ticks to load register */
	STK -> LOAD = Copy_u32Ticks;
	
	/* Start Timer */
	SET_BIT(STK->CTRL, 0);
	
	/* Wait till flag is raised */
	while( (GET_BIT(STK->CTRL,16)) == 0);
	
	/* Stop Timer */
	SET_BIT(STK->CTRL, 0);
	STK -> LOAD = 0;
	STK -> VAL  = 0;
	
}


void MSTK_voidSetIntervalSingle   (u32 Copy_u32Ticks , void(*Copy_ptr)(void))
{
	/* Disable Timer */
	CLR_BIT(STK -> CTRL,0);
	STK->VAL = 0;

	/* Load ticks to load register */
	STK -> LOAD = Copy_u32Ticks ; 

	/* Start Timer */
	SET_BIT(STK->CTRL, 0);

	/* Enable SysTick Interrupt */
	SET_BIT(STK -> CTRL, 1);

	/* Save CallBack */
	STK_CallBack = Copy_ptr;

	/* Set Mode to Single */
	STK_u8Mode = SINGLE_INTERVAL;
}

void MSTK_voidSetIntervalPeriodic (u32 Copy_u32Ticks , void(*Copy_ptr)(void))
{
	/* Load ticks to load register */
	STK -> LOAD = Copy_u32Ticks ; 

	/* Start Timer */
	SET_BIT(STK->CTRL, 0);

	/* Enable SysTick Interrupt */
	SET_BIT(STK -> CTRL, 1);

	/* Save CallBack */
	STK_CallBack = Copy_ptr;

	/* Set Mode to Single */
	STK_u8Mode = PERIOD_INTERVAL;
}

void MSTK_StopTimer               (void)
{
	/* Disable STK Interrupt */
	CLR_BIT(STK->CTRL, 1);
	
	/* Stop Timer */
	SET_BIT(STK->CTRL, 0);
	STK -> LOAD = 0;
	STK -> VAL  = 0;
}

u32  MSTK_u32GetElapsedTime       (void)
{
	u32 Local_u32ElapsedTime;
	
	Local_u32ElapsedTime = (STK -> LOAD) - (STK -> VAL) ;
	
	return Local_u32ElapsedTime;
}

u32  MSTK_u32GetRemainingTime     (void)
{
	u32 Local_u32RemainTime;
	
	Local_u32RemainTime = STK -> VAL ;
	
	return Local_u32RemainTime;
}

void SysTick_Handler(void)
{
	u8 Local_u8Temporary;
	
	if (STK_u8Mode == SINGLE_INTERVAL)
	{
		/* Disable STK Interrupt */
		CLR_BIT(STK->CTRL, 1);
	
		/* Stop Timer */
		SET_BIT(STK->CTRL, 0);
		STK -> LOAD = 0;
		STK -> VAL  = 0;
	}
	
	/* Callback notification */
	STK_CallBack();
	
	/* Clear interrupt flag */
	Local_u8Temporary = GET_BIT(STK->CTRL,16);
}
