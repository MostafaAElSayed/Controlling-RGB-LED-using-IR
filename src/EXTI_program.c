/****************************************************/
/*  Author      :   Mostafa Ahmed El-Sayed          */
/*  File Name   :   EXTI_program.c                  */
/*  Version     :   V01                             */
/*  Date        :   06/02/2023                      */
/****************************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"   

#include"EXTI_interface.h"
#include"EXTI_config.h"
#include"EXTI_private.h"

#define NULL		(void * )0
void (* EXTI_CallBack) (void) = NULL ;

/* Set Line Mode */
void MEXTI_voidInit(u8 Copy_u8Line, u8 Copy_u8Mode)
{
   if(Copy_u8Line <= 15)
   {
    switch (Copy_u8Mode)
    {
            case RISING_EDGE:
                    SET_BIT(EXTI->RTSR, Copy_u8Line);   break;

            case FALLING_EDGE:
                    SET_BIT(EXTI->FTSR, Copy_u8Line);   break;

            case ON_CHANGE:
                    SET_BIT(EXTI->RTSR, Copy_u8Line);
                    SET_BIT(EXTI->FTSR, Copy_u8Line);   break;
            
            default: /* return Error */       break;
    }
   }
   else
   {
    /* Error */
   }
}
void MEXTI_voidEnableEXTI(u8 Copy_u8Line)
{
    if(Copy_u8Line <= 15)
    {
    SET_BIT(EXTI->IMR, Copy_u8Line);
    }
    else{   /*Error*/}
}

void MEXTI_voidDisableEXTI(u8 Copy_u8Line)
{
    if(Copy_u8Line <= 15)
    {
    CLR_BIT(EXTI->IMR, Copy_u8Line);
    }
    else{   /*Error*/}
}

void MEXTI_voidEnableEvent(u8 Copy_u8Line)
{
    if(Copy_u8Line <= 15)
    {
    SET_BIT(EXTI->EMR, Copy_u8Line);
    }
    else{   /*Error*/}
}

void MEXTI_voidDisableEvent(u8 Copy_u8Line)
{
    if(Copy_u8Line <= 15)
    {
    CLR_BIT(EXTI->EMR, Copy_u8Line);
    }
    else{   /*Error*/}
}

void MEXTI_voidSWTrigger(u8 Copy_u8Line)
{
    if(Copy_u8Line <= 15)
    {
        SET_BIT(EXTI->SWIER, Copy_u8Line);
    }
    else{   /*Error*/}
}

void MEXTI_voidSetCallBack(void (*ptr) (void))
{
		EXTI_CallBack = ptr ;
}

void EXTI0_IRQHandler(void)
{
	EXTI_CallBack();
	/*	Clear pending Bit		*/
	SET_BIT(EXTI -> PR , 0);
}