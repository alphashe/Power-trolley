/*
 * PressKey.c
 *
 *  Created on: 2024Äê5ÔÂ28ÈÕ
 *      Author: alpha
 */

#include <PressKey.h>

void PressKey_Init(void){
    EALLOW;
    SysCtrlRegs.PCLKCR3.bit.GPIOINENCLK = 1;    //enable GPIO input clock

    GpioCtrlRegs.GPCMUX1.bit.KO1IO = GPIOMUX_GPIO;
    GpioCtrlRegs.GPCDIR.bit.KO1IO = GPIODIR_OUTPUT;
    GpioCtrlRegs.GPCPUD.bit.KO1IO = GPIOPUD_PULLUP;

    GpioCtrlRegs.GPBMUX1.bit.KO2IO = GPIOMUX_GPIO;
    GpioCtrlRegs.GPBDIR.bit.KO2IO = GPIODIR_OUTPUT;
    GpioCtrlRegs.GPBPUD.bit.KO2IO = GPIOPUD_PULLUP;

    GpioCtrlRegs.GPAMUX2.bit.KI1IO = GPIOMUX_GPIO;
    GpioCtrlRegs.GPADIR.bit.KI1IO = GPIODIR_INPUT;
    GpioCtrlRegs.GPAPUD.bit.KI1IO = GPIOPUD_PULLUP;

    GpioCtrlRegs.GPBMUX1.bit.KI2IO = GPIOMUX_GPIO;
    GpioCtrlRegs.GPBDIR.bit.KI2IO = GPIODIR_INPUT;
    GpioCtrlRegs.GPBPUD.bit.KI2IO = GPIOPUD_PULLUP;

    KO1_L;
    KO2_L;
    EDIS;

}

U8 Scan_PressKey(void){
    U8 prek=0;

    KO1_H;
    KO2_H;
    DELAY_US(100);
    if(KI1==0 || KI2==0){
        DELAY_US(10000);
        if(KI1==0){
            prek = 1;
            return prek;
        }
        if(KI2==0){
            prek = 2;
            return prek;
        }

    }
/*
    KO1_L;
    KO2_H;
    DELAY_US(100);
    if(KI1==0 || KI2==0){
        DELAY_US(10000);
        if(KI1==0){
            prek = 3;
            return prek;
        }

        if(KI2==0){
            prek = 4;
            return prek;
        }

    }
*/
    return prek;
}
