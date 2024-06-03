
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
//定义变量


void main(void){
    MemCopy(&RamfuncsLoadStart, &RamfuncsLoadEnd, &RamfuncsRunStart);
    InitFlash();

    InitSysCtrl();
    //DINT;
    Uint16 fx = 0, data_recive=0, data_trans=0;
    Uint16 i=0;
    Uint32 realtime=0;
    Uint32 shownum=0;
	InitPieCtrl();
	IER = 0x0000;   //disable all interrupt
	IFR = 0x0000;   //clear all interrupt flag
	InitPieVectTable();

	//sdf
	TIM0_Init(150-1, 700000-1);    //150MHz 150 divide ->1uS, count 700*1000  ->700mS
	DELAY_US(100);
    LED_Init();
    //K2_Init();
    DELAY_US(1000000);  //wait OLED charge

    OLED_Init();
    OLED_Clear();
    SPI_Init();
    OLED_ShowPicture(34, 2, 60, 60, BtPic, 1);
    OLED_Refresh();
    OLED_Clear();
    DELAY_US(1000000);
   // ADC_Init();
   // Key_Init();
   // EXTI1_Init();;;;;


    struct Powtrolley* ptrolley;
    ptrolley = Power_trolley_Init();
    //Init_Key_Time();

	while(1){
	   Power_trolley_display(*ptrolley);
	   ptrolley->targ_speed=0;
	   Power_trolley_contr(*ptrolley);
	   fx++;
	   // if(fx==500000){
	   //     LED4_TOGGLE;
	   // }
	   ptrolley->l_speed=fx*10;
	   DELAY_US(1000000);
	    if(fx==9){
	          fx=0;
	        fx=0;
	    }
	}
 }

