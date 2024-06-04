/*
 * PressKey.c
 *
 *  Created on: 2024Äê5ÔÂ28ÈÕ
 *      Author: alpha
 */

#include <PressKey.h>

void Key_Init(void){
    EALLOW;
    SysCtrlRegs.PCLKCR3.bit.GPIOINENCLK = 1;    //enable GPIO input clock

    GpioCtrlRegs.GPCMUX1.bit.KO1IO = GPIOMUX_GPIO;
    GpioCtrlRegs.GPCDIR.bit.KO1IO = GPIODIR_OUTPUT;
    GpioCtrlRegs.GPCPUD.bit.KO1IO = GPIOPUD_PULLUP;

    GpioCtrlRegs.GPBMUX1.bit.KO2IO = GPIOMUX_GPIO;
    GpioCtrlRegs.GPBDIR.bit.KO2IO = GPIODIR_OUTPUT;
    GpioCtrlRegs.GPBPUD.bit.KO2IO = GPIOPUD_PULLUP;

    GpioCtrlRegs.GPCMUX2.bit.KI1IO = GPIOMUX_GPIO;
    GpioCtrlRegs.GPCDIR.bit.KI1IO = GPIODIR_INPUT;
    GpioCtrlRegs.GPCPUD.bit.KI1IO = GPIOPUD_PULLUP;

    GpioCtrlRegs.GPBMUX1.bit.KI2IO = GPIOMUX_GPIO;
    GpioCtrlRegs.GPBDIR.bit.KI2IO = GPIODIR_INPUT;
    GpioCtrlRegs.GPBPUD.bit.KI2IO = GPIOPUD_PULLUP;

    EDIS;

    KO1_L;
    KO2_L;
}

U8 Scan_PressKey(void){
    U8 prek=0;

    KO1_H;
    KO2_L;
    return prek;
}
