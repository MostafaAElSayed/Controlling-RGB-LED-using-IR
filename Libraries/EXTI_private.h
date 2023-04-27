/****************************************************/
/*  Author      :   Mostafa Ahmed El-Sayed          */
/*  File Name   :   EXTI_private.h                  */
/*  Version     :   V01                             */
/*  Date        :   06/02/2023                      */
/****************************************************/
#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

typedef struct 
{
    volatile u32 IMR;
    volatile u32 EMR;
    volatile u32 RTSR;
    volatile u32 FTSR;
    volatile u32 SWIER;
    volatile u32 PR;
}EXTI_t;

#define EXTI    ((EXTI_t*)0x40010400)


#endif /*EXTI_PRIVATE_H_*/