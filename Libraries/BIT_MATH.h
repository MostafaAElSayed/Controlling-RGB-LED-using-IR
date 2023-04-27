/****************************************************/
/*  Author      :   Mostafa Ahmed El-Sayed          */
/*  File Name   :   BIT_MATH.h                      */
/*  Version     :   V01                             */
/*  Date        :   02/02/2023                      */
/****************************************************/
#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(VAR,BIT)    (VAR |=  (1 << BIT))
#define CLR_BIT(VAR,BIT)    (VAR &= ~(1 << BIT))
#define TOG_BIT(VAR,BIT)    (VAR ^=  (1 << BIT))
#define GET_BIT(VAR,BIT)    ( (VAR >> BIT) & 1 )


#endif  /** BIT_MATH_H_ */
