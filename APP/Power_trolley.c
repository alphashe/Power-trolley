/*
 * power_trolley.c
 *
 *  Created on: 2024Äê5ÔÂ31ÈÕ
 *      Author: alpha
 */

#include <Power_trolley.h>

struct Powtrolley* Power_trolley_Init(void){
    static struct Powtrolley trolley;
    trolley.targ_speed=0;
    trolley.speed=0;


    EPWM1_Init(1500);   //150MHz 1500 => 100kHz
    EPWM3_Init(1500);

    EALLOW;
    GpioCtrlRegs.GPAMUX1.bit.RESETCD = GPIOMUX_GPIO;
    GpioCtrlRegs.GPADIR.bit.RESETCD = GPIODIR_OUTPUT;
    GpioCtrlRegs.GPAPUD.bit.RESETCD = GPIOPUD_PULLUP;

    GpioCtrlRegs.GPAMUX1.bit.RESETCD = GPIOMUX_GPIO;
    GpioCtrlRegs.GPADIR.bit.RESETCD = GPIODIR_OUTPUT;
    GpioCtrlRegs.GPAPUD.bit.RESETCD = GPIOPUD_PULLUP;
    EDIS;

    EPwm1A_SetCompare(0);
    EPwm1B_SetCompare(0);
    EPwm3A_SetCompare(0);
    EPwm3B_SetCompare(0);
    RESETAB_L;
    RESETCD_L;
    return &trolley;
}
void Power_trolley_menu(void){
    OLED_ShowString(25, 0, "Power_trolley", 1);
    OLED_ShowString(0, 8, "Traget_Speed:", 1);
    OLED_ShowString(0, 16, "Speed:", 1);

}

void Power_trolley_display(struct Powtrolley temp){
    OLED_Clear();
    Power_trolley_menu();
    OLED_ShowInt(42, 32, DirectionQep, 1);
    if(temp.targ_speed>=0)
        OLED_ShowInt(78, 8, temp.targ_speed, 1);
    else{
        OLED_ShowString(78, 8, "-", 1);
        OLED_ShowInt(84, 8, (-temp.targ_speed), 1);
    }
    if(temp.speed>=0)
        OLED_ShowInt(36, 16, temp.speed, 1);
    else{
        OLED_ShowString(36, 16, "-", 1);
        OLED_ShowInt(42, 16, (-temp.speed), 1);
    }


    OLED_Refresh();
}

void Power_trolley_contr(struct Powtrolley temp){
    Uint16 target=1;
    if(temp.speed>50 || temp.speed<-50){
        RESETAB_H;
        RESETCD_H;
    }
    else{
        RESETAB_L;
        RESETCD_L;
    }
    if(temp.speed>50){
        temp.targ_speed=30;
    }
    else if(temp.speed<-50){
        temp.targ_speed=-30;
    }
    else
        temp.targ_speed=0;
    if(temp.targ_speed>=0){
        target = temp.targ_speed * 15;  //pwm max:1500   targ_speed max:95
        EPwm1A_SetCompare(target);
        EPwm3A_SetCompare(target);

        EPwm1B_SetCompare(0);
        EPwm3B_SetCompare(0);
    }
    if(temp.targ_speed<0){
        target = -(temp.targ_speed * 15);  //pwm max:1500   targ_speed max:-95
        EPwm1A_SetCompare(0);
        EPwm3A_SetCompare(0);

        EPwm1B_SetCompare(target);
        EPwm3B_SetCompare(target);
    }

}
