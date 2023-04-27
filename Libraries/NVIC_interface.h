/****************************************************/
/*  Author      :   Mostafa Ahmed El-Sayed          */
/*  File Name   :   NVIC_interface.h                */
/*  Version     :   V01                             */
/*  Date        :   06/02/2023                      */
/****************************************************/
#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

void MNVIC_voidInit             (void);
void MNVIC_voidSetPriority      (u8 Copy_u8PeripheralIdx, u8 Copy_u8Priority);
void MNVIC_voidEnableInterrupt  (u8 Copy_u8IntNumber);
void MNVIC_voidDisableInterrupt (u8 Copy_u8IntNumber);
void MNVIC_voidSetPendingFlag   (u8 Copy_u8IntNumber);
void MNVIC_voidClearPendingFlag (u8 Copy_u8IntNumber);
u8 MNVIC_u8GetActiveFlag        (u8 Copy_u8IntNumber);

typedef enum
{
    WWDG,
    PVD,
    TAMPER,
    RTC,
    FLASH,
    RCC,
    EXTI0,
    EXTI1,
    EXTI2,
    EXTI3,
    EXTI4,
    DMA1_Channel1,
    DMA1_Channel2,
    DMA1_Channel3,
    DMA1_Channel4,
    DMA1_Channel5,
    DMA1_Channel6,
    DMA1_Channel7,
    ADC1_2,
    USB_HP_CAN_TX,
    USB_LP_CAN_RX0,
    CAN_RX1,
    CAN_SCE,
    EXTI9_5,
    TIM1_BRK,
    TIM1_UP,
    TIM1_TRG_COM,
    TIM1_CC,
    TIM2,
    TIM3,
    TIM4,
    I2C1_EV,
    I2C1_ER,
    I2C2_EV,
    I2C2_ER,
    SPI1,
    SPI2,
    USART1,
    USART2,
    USART3,
    EXTI15_10,
    RTCAlarm,
    USBWakeup,
    TIM8_BRK,
    TIM8_UP,
    TIM8_TRG_COM,
    TIM8_CC,
    ADC3,
    FSMC,
    SDIO,
    TIM5,
    SPI3,
    UART4,
    UART5,
    TIM6,
    TIM7,
    DMA2_Channel1,
    DMA2_Channel2,
    DMA2_Channel3,
    DMA2_Channel4_5,
}VectorTable_t;

#endif /* NVIC_INTERFACE_H_ */