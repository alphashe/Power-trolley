/*
 * eQEP.h
 *
 *  Created on: 2024Äê6ÔÂ5ÈÕ
 *      Author: alpha
 */

#ifndef APP_INCLUDE_EQEP_H_
#define APP_INCLUDE_EQEP_H_

#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"

extern unsigned int motor_speed;
extern int DirectionQep;
//extern int LineEncoder;
extern int Encoder_N;
extern float Speed_Mr_RPM;
extern Uint32 Position_k_1;
extern Uint32 Position_k;

void eQEP_Init(void);
void Frencal_Init(void);
Uint32 QEP_pos_speed_get_Calc(void);

#endif /* APP_INCLUDE_EQEP_H_ */
