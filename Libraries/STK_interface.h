/****************************************************/
/*  Author      :   Mostafa Ahmed El-Sayed          */
/*  File Name   :   STK_interface.h                 */
/*  Version     :   V01                             */
/*  Date        :   06/02/2023                      */
/****************************************************/
#ifndef STK_INTERFACE_H_
#define STK_INTERFACE_H_

void MSTK_voidInit                (void);
void MSTK_voidSetBusyWait         (u32 Copy_u32Ticks);
void MSTK_voidSetIntervalSingle   (u32 Copy_u32Ticks , void(*Copy_ptr)(void));
void MSTK_voidSetIntervalPeriodic (u32 Copy_u32Ticks , void(*Copy_ptr)(void));
void MSTK_StopTimer               (void);
u32  MSTK_u32GetElapsedTime       (void);
u32  MSTK_u32GetRemainingTime     (void);


#endif /*STK_INTERFACE_H_*/