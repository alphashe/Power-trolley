/*
 * Power_trolley.h
 *
 *  Created on: 2024Äê5ÔÂ31ÈÕ
 *      Author: alpha
 */

#ifndef APP_INCLUDE_POWER_TROLLEY_H_
#define APP_INCLUDE_POWER_TROLLEY_H_

#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"
#include "EPWM.h"
#include "OLED.h"

struct Powtrolley{
    int targ_speed;
    char r_speed;
    char l_speed;

};
struct Powtrolley* Power_trolley_Init(void);

void Power_trolley_display(struct Powtrolley temp);
void Power_trolley_menu(void);
void Power_trolley_contr(struct Powtrolley temp);

#endif /* APP_INCLUDE_POWER_TROLLEY_H_ */
