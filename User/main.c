
#include <TouchKey.h>
#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "ADC.h"
#include "INT.h"
#include "TIME.h"
#include "EPWM.h"
#include "LED.h"
#include "OLED.h"
#include "PressKey.h"
//#include "SPI.h"
#include "oledchar.h"
#include <Power_trolley.h>
#include <PressKey.h>
//定义变量


void main(void){
    MemCopy(&RamfuncsLoadStart, &RamfuncsLoadEnd, &RamfuncsRunStart);
    InitFlash();

    InitSysCtrl();
    //DINT;
    Uint16 fx = 0;

	InitPieCtrl();
	IER = 0x0000;   //disable all interrupt
	IFR = 0x0000;   //clear all interrupt flag
	InitPieVectTable();

	//
	TIM0_Init(150-1, 700000-1);    //150MHz 150 divide ->1uS, count 700*1000  ->700mS
	DELAY_US(100);
    LED_Init();
    DELAY_US(1000000);  //wait OLED charge

    OLED_Init();
    OLED_Clear();
    OLED_ShowPicture(34, 2, 60, 60, BtPic, 1);
    OLED_Refresh();
    OLED_Clear();
    PressKey_Init();
    DELAY_US(1000000);
   // ADC_Init();


    struct Powtrolley* ptrolley;
    ptrolley = Power_trolley_Init();
    ptrolley->targ_speed=0;

	while(1){
	   Power_trolley_display(*ptrolley);
	   Power_trolley_contr(*ptrolley);
	   if(Scan_PressKey() == 1){
	       if(ptrolley->targ_speed<99)
	           ptrolley->targ_speed++;
	       else
	           ptrolley->targ_speed=1;
	   }
	   if(Scan_PressKey() == 2)
	       if(ptrolley->targ_speed>0)
           ptrolley->targ_speed--;
       else
           ptrolley->targ_speed=99;

	}
 }

