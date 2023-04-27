/****************************************************/
/*  Author      :   Mostafa Ahmed El-Sayed          */
/*  File Name   :   RCC_program.c                   */
/*  Version     :   V01                             */
/*  Date        :   03/02/2023                      */
/****************************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

/*  RCC_CLOCK_TYPE
    Options:        RCC_HSE_CRYSTAL
                    RCC_HSE_RC
                    RCC_HSI          "Default"
                    RCC_PLL
                                */

void RCC_voidInitSysClock(void)
{
    RCC_CR  = 0x00000083;                       //Reset value for RCC_CR Register
    
    #if   RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
        RCC_CR   = 0x00010080;                    //Enable HSE Without bypass
        RCC_CFGR = 0x00000001;

    #elif RCC_CLOCK_TYPE == RCC_HSE_RC
        RCC_CR   = 0x00050080;                    //Enable HSE With bypass
        RCC_CFGR = 0x00000001;

    #elif RCC_CLOCK_TYPE == RCC_HSI
        RCC_CR   = 0x00000081;                    //Enable HSI 
        RCC_CFGR = 0x00000000;

    #elif RCC_CLOCK_TYPE == RCC_PLL
        #if   RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2

        #elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2

        #elif RCC_PLL_INPUT == RCC_PLL_IN_HSE

        #else   #error(Wrong PLL Clock Input)
        #endif
       

    #else #error(Wrong Clock Type!)
    #endif
}

void RCC_voidEnableClock(u8 Copy_u8BusId,u8 Copy_u8PerId)
{
    if(Copy_u8PerId <= 31)
    {
        switch (Copy_u8BusId)
        { 
        case RCC_AHB : SET_BIT(RCC_AHBENR ,Copy_u8PerId);  break;
        case RCC_APB1: SET_BIT(RCC_APB1ENR,Copy_u8PerId);  break;
        case RCC_APB2: SET_BIT(RCC_APB2ENR,Copy_u8PerId);  break;

        default:    /* Error */                            break;
        }
    }
    else
    {
        // Return Error
    }
}

void RCC_voidDisableClock(u8 Copy_u8BusId,u8 Copy_u8PerId)
{
    if(Copy_u8PerId <= 31)
    {
        switch (Copy_u8BusId)
        { 
        case RCC_AHB : CLR_BIT(RCC_AHBENR ,Copy_u8PerId);  break;
        case RCC_APB1: CLR_BIT(RCC_APB1ENR,Copy_u8PerId);  break;
        case RCC_APB2: CLR_BIT(RCC_APB2ENR,Copy_u8PerId);  break;

        default:    /* Error */    break;
        }
    }
    else
    {
        // Return Error
    }
}

u8   RCC_u8GetSystemClockStatus(void)
{
    u8 Local_u8Return = 4;
    Local_u8Return = ((RCC_CFGR >> 2) &(0b11) );

    return Local_u8Return;
}