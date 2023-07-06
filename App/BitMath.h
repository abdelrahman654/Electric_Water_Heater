/*
 * BitMath.h
 *
 * Created: 05/06/2023 05:47:34 ص
 *  Author: ascom
 */ 


#ifndef BITMATH_H_
#define BITMATH_H_

#define SetBit(Reg,Bit)      Reg |=  (1 << Bit)
#define ClrBit(Reg,Bit)      Reg &= ~(1 << Bit)
#define TogBit(Reg,Bit)      Reg ^=  (1 << Bit)
#define GetBit(Reg,Bit)      1 & (Reg >> Bit)



#endif /* BITMATH_H_ */