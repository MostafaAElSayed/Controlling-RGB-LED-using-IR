/****************************************************/
/*  Author      :   Mostafa Ahmed El-Sayed          */
/*  File Name   :   EXTI_interface.h                */
/*  Version     :   V01                             */
/*  Date        :   06/02/2023                      */
/****************************************************/
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/*
    Func: voidInit()
    args:
        Copy_u8Mode Options:    
                    RISING_EDGE,
                    FALLING_EDGE,
                    ON_CHANGE,
        Copy_u8Line Options:
                    LINE0   :   LINE15  
    return: void
*/
void MEXTI_voidInit(u8 Copy_u8Line, u8 Copy_u8Mode);
void MEXTI_voidEnableEXTI(u8 Copy_u8Line);
void MEXTI_voidDisableEXTI(u8 Copy_u8Line);
void MEXTI_voidEnableEvent(u8 Copy_u8Line);
void MEXTI_voidDisableEvent(u8 Copy_u8Line);
void MEXTI_voidSWTrigger(u8 Copy_u8Line);
void MEXTI_voidSetCallBack(void (*ptr) (void));

typedef enum
{
    LINE0,
    LINE1,
    LINE2,
    LINE3,
    LINE4,
    LINE5,
    LINE6,
    LINE7,
    LINE8,
    LINE9,
    LINE10,
    LINE11,
    LINE12,
    LINE13,
    LINE14,
    LINE15,
}LINE_t;

typedef enum
{
    RISING_EDGE,
    FALLING_EDGE,
    ON_CHANGE,
}MODE_t;

#endif /* EXTI_INTERFACE_H_*/