/****************************************************/
/*  Author      :   Mostafa Ahmed El-Sayed          */
/*  File Name   :   GPIO_program.c                  */
/*  Version     :   V01                             */
/*  Date        :   06/02/2023                      */
/****************************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GPIO_interface.h"
#include "GPIO_config.h"
#include "GPIO_private.h"

void GPIO_VoidSetPinDirection(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Mode)
{
    switch (Copy_u8Port)
    {
    case GPIOA:
        if(Copy_u8Pin <= 7)
        {
            GPIOA_CRL &= ~((0b1111) << (Copy_u8Pin*4));
            GPIOA_CRL |= (Copy_u8Mode << (Copy_u8Pin*4));
        }
        else if(Copy_u8Pin <= 15)
        {
            Copy_u8Pin -= 8 ; 
            GPIOA_CRH &= ~((0b1111) << (Copy_u8Pin*4));
            GPIOA_CRH |= (Copy_u8Mode << (Copy_u8Pin*4));           
        }
        else{ /*Error (Wrong PIN NUMBER)*/}
        break;

    case GPIOB:
        if(Copy_u8Pin <= 7)
        {
            GPIOB_CRL &= ~((0b1111) << (Copy_u8Pin*4));
            GPIOB_CRL |= (Copy_u8Mode << (Copy_u8Pin*4));
        }
        else if(Copy_u8Pin <= 15)
        {
            Copy_u8Pin -= 8 ; 
            GPIOB_CRH &= ~((0b1111) << (Copy_u8Pin*4));
            GPIOB_CRH |= (Copy_u8Mode << (Copy_u8Pin*4));           
        }
        else{ /*Error (Wrong PIN NUMBER)*/}
        break;

    case GPIOC:
        if(Copy_u8Pin <= 7)
        {
            GPIOC_CRL &= ~((0b1111) << (Copy_u8Pin*4));
            GPIOC_CRL |= (Copy_u8Mode << (Copy_u8Pin*4));
        }
        else if(Copy_u8Pin <= 15)
        {
            Copy_u8Pin -= 8 ; 
            GPIOC_CRH &= ~((0b1111) << (Copy_u8Pin*4));
            GPIOC_CRH |= (Copy_u8Mode << (Copy_u8Pin*4));           
        }
        else{ /*Error (Wrong PIN NUMBER)*/}
        break;

    
    default:
        /*  Error (Wrong PORT NAME)*/
        break;
    }
}

void GPIO_VoidSetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_Value)
{
    if((Copy_u8Pin >= 0) && (Copy_u8Pin <= 15))
    {
        switch (Copy_u8Port)
        {
        case GPIOA:
            if(Copy_Value == GPIO_HIGH)
            {
                SET_BIT(GPIOA_ODR,Copy_u8Pin);
            }
            else if(Copy_Value == GPIO_LOW)
            {
                CLR_BIT(GPIOA_ODR,Copy_u8Pin);
            }
            else{ /* Error (Wrong VALUE for PIN)*/}
            break;

        case GPIOB:
            if(Copy_Value == GPIO_HIGH)
            {
                SET_BIT(GPIOB_ODR,Copy_u8Pin);
            }
            else if(Copy_Value == GPIO_LOW)
            {
                CLR_BIT(GPIOB_ODR,Copy_u8Pin);
            }
            else{ /* Error (Wrong VALUE for PIN)*/}
            break;
        case GPIOC:
            if(Copy_Value == GPIO_HIGH)
            {
                SET_BIT(GPIOC_ODR,Copy_u8Pin);
            }
            else if(Copy_Value == GPIO_LOW)
            {
                CLR_BIT(GPIOC_ODR,Copy_u8Pin);
            }
            else{ /* Error (Wrong VALUE for PIN)*/}
            break;

        
        default: /* Error (Wrong PORT NAME)*/   break;
        }
    }
    else
    {
        /*  Error (Wrong PIN NUMBER)*/
    }
}

u8 GPIO_VoidGetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin)
{
    if((Copy_u8Pin >= 0) && (Copy_u8Pin <= 15))
    {
        u8 Loc_u8Result = 0 ;
        switch (Copy_u8Port)
        {
        case GPIOA:
            Loc_u8Result = GET_BIT(GPIOA_IDR,Copy_u8Pin);
            break;

        case GPIOB:
            Loc_u8Result = GET_BIT(GPIOB_IDR,Copy_u8Pin);
            break;

        case GPIOC:
            Loc_u8Result = GET_BIT(GPIOC_IDR,Copy_u8Pin);
            break;
        
        default: /* Error (Wrong PORT NAME)*/   break;
        }
        return Loc_u8Result;
    }
    else
    {
        /* Error (Wrong PIN NUMBER)*/
    }
}
