/*
 * PressKey.h
 *
 *  Created on: 2024Äê5ÔÂ28ÈÕ
 *      Author: alpha
 */

#ifndef APP_INCLUDE_PRESSKEY_H_
#define APP_INCLUDE_PRESSKEY_H_

#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"

#define KO1IO GPIO79
#define KO2IO GPIO44
#define KI1IO GPIO28
#define KI2IO GPIO39

#define KI1 GpioDataRegs.GPADAT.bit.KI1IO
#define KI2 GpioDataRegs.GPBDAT.bit.KI2IO

#define KO1_H GpioDataRegs.GPCSET.bit.GPIO79=1
#define KO1_L GpioDataRegs.GPCCLEAR.bit.GPIO79=1
#define KO2_H GpioDataRegs.GPBSET.bit.GPIO44=1
#define KO2_L GpioDataRegs.GPBCLEAR.bit.GPIO44=1

void PressKey_Init(void);
U8 Scan_PressKey(void);

#endif /* APP_INCLUDE_PRESSKEY_H_ */
