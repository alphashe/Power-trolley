/*
 * TIME.h
 *
 *  Created on: 2024��1��26��
 *      Author: alpha
 */

#ifndef APP_INCLUDE_TIME_H_
#define APP_INCLUDE_TIME_H_

#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"
#include "LED.h"
#include "Global.h"


void TIM0_Init(Uint32 divide, Uint32 count);

interrupt void TIM0_Int(void);

#endif /* APP_INCLUDE_TIME_H_ */
