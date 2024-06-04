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

    GpioCtrlRegs.GPCMUX2.bit.K3IO = GPIOMUX_GPIO;
    GpioCtrlRegs.GPCDIR.bit.K3IO = GPIODIR_INPUT;
    GpioCtrlRegs.GPCPUD.bit.K3IO = GPIOPUD_PULLUP;

    GpioCtrlRegs.GPAMUX2.bit.K4IO = GPIOMUX_GPIO;
    GpioCtrlRegs.GPADIR.bit.K4IO = GPIODIR_INPUT;
    GpioCtrlRegs.GPAPUD.bit.K4IO = GPIOPUD_PULLUP;


    EDIS;

}

U8 Scan_PressKey(void){
    U8 prek=0;
    if(K1==0){
        DELAY_US(10000);    //delay 10mS in order to eliminate jitter
        if(K1==0)
            prek=1;
        while(K1==0);
    }
    if(K2==0){
        DELAY_US(10000);    //delay 10mS in order to eliminate jitter
        if(K2==0)
            prek=2;
        while(K2==0);
    }
    if(K3==0){
        DELAY_US(10000);    //delay 10mS in order to eliminate jitter
        if(K3==0)
            prek=3;
        while(K3==0);
    }
    if(K4==0){
        DELAY_US(10000);    //delay 10mS in order to eliminate jitter
        if(K4==0)
            prek=4;
        while(K4==0);
    }
    if(K5==0){
        DELAY_US(10000);    //delay 10mS in order to eliminate jitter
        if(K5==0)
            prek=5;
        while(K5==0);
    }
    if(K6==0){
        DELAY_US(10000);    //delay 10mS in order to eliminate jitter
        if(K6==0)
            prek=6;
        while(K6==0);
    }
    if(K7==0){
        DELAY_US(10000);    //delay 10mS in order to eliminate jitter
        if(K7==0)
            prek=7;
        while(K7==0);
    }
    return prek;
}
