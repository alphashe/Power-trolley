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
#include <eQEP.h>

#define RESETAB GPIO3
#define RESETCD GPIO2
#define RESETAB_H GpioDataRegs.GPASET.bit.RESETAB=1
#define RESETAB_L GpioDataRegs.GPACLEAR.bit.RESETAB=1
#define RESETCD_H GpioDataRegs.GPASET.bit.RESETCD=1
#define RESETCD_L GpioDataRegs.GPACLEAR.bit.RESETCD=1

struct Powtrolley{
    int targ_speed;
    int speed;
    char On;


};
struct Powtrolley* Power_trolley_Init(void);

void Power_trolley_display(struct Powtrolley temp);
void Power_trolley_menu(void);
void Power_trolley_contr(struct Powtrolley temp);

#endif /* APP_INCLUDE_POWER_TROLLEY_H_ */
