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
#define KI1IO GPIO80
#define KI2IO GPIO39

#define KI1 GpioDataRegs.GPCDAT.bit.KI1IO
#define KI2 GpioDataRegs.GPBDAT.bit.KI2IO

#define KO1IO_H GpioDataRegs.GPCSET.bit.SCL=1
#define KO1IO_L GpioDataRegs.GPCCLEAR.bit.SCL=1
#define KO2IO_H GpioDataRegs.GPCBDAT.bit.GPBSET
#define KO2IO_L GpioDataRegs.GPCBAT.bit.GPBCLEAR

void PressKey_Init(void);
U8 Scan_PressKey(void);

#endif /* APP_INCLUDE_PRESSKEY_H_ */
