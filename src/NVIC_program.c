/****************************************************/
/*  Author      :   Mostafa Ahmed El-Sayed          */
/*  File Name   :   NVIC_program.c                  */
/*  Version     :   V01                             */
/*  Date        :   06/02/2023                      */
/****************************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"NVIC_interface.h"
#include"NVIC_private.h"
#include"NVIC_config.h"

void MNVIC_voidInit(void)
{
    #define SCB_AIRCR       *((volatile u32*)0xE000ED00 + 0x0C)
    switch (NVIC_GROUP_SUB_DISTRIBUTION)
    {
    case NVIC_GROUP_4_SUB_0: SCB_AIRCR = NVIC_GROUP_4_SUB_0;   break;
    case NVIC_GROUP_3_SUB_1: SCB_AIRCR = NVIC_GROUP_3_SUB_1;   break;
    case NVIC_GROUP_2_SUB_2: SCB_AIRCR = NVIC_GROUP_2_SUB_2;   break;
    case NVIC_GROUP_1_SUB_3: SCB_AIRCR = NVIC_GROUP_1_SUB_3;   break;
    case NVIC_GROUP_0_SUB_4: SCB_AIRCR = NVIC_GROUP_0_SUB_4;   break;
    
    default: /* Error   */   break;
    }
}

void MNVIC_voidSetPriority(u8 Copy_u8PeripheralIdx, u8 Copy_u8Priority)
{
    if(Copy_u8PeripheralIdx < 60)
    {
        NVIC_IPR[Copy_u8PeripheralIdx] = Copy_u8Priority ;
    }
    else
    {
        /*  Return Error */
    }
}

void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNumber)
{
    if(Copy_u8IntNumber <=31)
    {
        /*  SET_BIT(NVIC_ISER0,Copy_u8IntNumber); */
        NVIC_ISER0 = (1 << Copy_u8IntNumber);   //a7sn mn set_bit() w 3mlyt ORing 3shan hna 0 has no effect! 
    }
    else if(Copy_u8IntNumber <=59)
    {
        Copy_u8IntNumber -= 32 ; 
        /*  SET_BIT(NVIC_ISER1,(Copy_u8IntNumber)); */
        NVIC_ISER1 = (1 << Copy_u8IntNumber);   //a7sn mn set_bit() w 3mlyt ORing 3shan hna 0 has no effect! 
    }
    else
    {
        //return Error
    }
}


void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNumber)
{
    if(Copy_u8IntNumber <=31)
    {
        NVIC_ICER0 = (1 << Copy_u8IntNumber);   //a7sn mn set_bit() w 3mlyt ORing 3shan hna 0 has no effect! 
    }
    else if(Copy_u8IntNumber <=59)
    {
        Copy_u8IntNumber -= 32 ; 
        NVIC_ICER1 = (1 << Copy_u8IntNumber);   //a7sn mn set_bit() w 3mlyt ORing 3shan hna 0 has no effect! 
    }
    else
    {
        //return Error
    }
}

void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNumber)
{
    if(Copy_u8IntNumber <=31)
    {
        NVIC_ISPR0 = (1 << Copy_u8IntNumber);   //a7sn mn set_bit() w 3mlyt ORing 3shan hna 0 has no effect! 
    }
    else if(Copy_u8IntNumber <=59)
    {
        Copy_u8IntNumber -= 32 ; 
        NVIC_ISPR1 = (1 << Copy_u8IntNumber);   //a7sn mn set_bit() w 3mlyt ORing 3shan hna 0 has no effect! 
    }
    else
    {
        //return Error
    }
}

void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber)
{
    if(Copy_u8IntNumber <=31)
    {
        NVIC_ICPR0 = (1 << Copy_u8IntNumber);   //a7sn mn set_bit() w 3mlyt ORing 3shan hna 0 has no effect! 
    }
    else if(Copy_u8IntNumber <=59)
    {
        Copy_u8IntNumber -= 32 ; 
        NVIC_ICPR1 = (1 << Copy_u8IntNumber);   //a7sn mn set_bit() w 3mlyt ORing 3shan hna 0 has no effect! 
    }
    else
    {
        //return Error
    }
}

u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber)
{
    u8 Local_u8Result;
    if(Copy_u8IntNumber <=31)
    {
        Local_u8Result = GET_BIT(NVIC_IABR0,Copy_u8IntNumber);
    }
    else if(Copy_u8IntNumber <=59)
    {
        Copy_u8IntNumber -= 32 ; 
        Local_u8Result = GET_BIT(NVIC_IABR1,Copy_u8IntNumber);
    }
    else
    {
        //return Error
    }
}
