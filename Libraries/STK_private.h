/****************************************************/
/*  Author      :   Mostafa Ahmed El-Sayed          */
/*  File Name   :   STK_private.h                   */
/*  Version     :   V01                             */
/*  Date        :   06/02/2023                      */
/****************************************************/
#ifndef STK_PRIVATE_H_
#define STK_PRIVATE_H_

/* BASE ADDRESS 0xE000E010  */

typedef struct
{
    volatile u32 CTRL;
    volatile u32 LOAD;
    volatile u32 VAL;
    volatile u32 CALIB;
}STK_t;

#define STK     ((STK_t*)0xE000E010)

#define STK_AHB	  0
#define STK_AHB_8 1

#define SINGLE_INTERVAL 0
#define PERIOD_INTERVAL 1

#endif /*STK_PRIVATE_H_*/
