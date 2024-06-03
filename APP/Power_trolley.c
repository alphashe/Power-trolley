/*
 * power_trolley.c
 *
 *  Created on: 2024Äê5ÔÂ31ÈÕ
 *      Author: alpha
 */

#include <Power_trolley.h>

struct Powtrolley* Power_trolley_Init(void){
    static struct Powtrolley trolley;
    trolley.targ_speed=-15;
    trolley.l_speed=-54;
    trolley.r_speed=67;

    EPWM1_Init(1500);   //150MHz 1500 => 100kHz
    EPWM3_Init(1500);

    EPwm1A_SetCompare(0);
    EPwm1B_SetCompare(0);
    EPwm3A_SetCompare(0);
    EPwm3B_SetCompare(0);

    return &trolley;
}
void Power_trolley_menu(void){
    OLED_ShowString(25, 0, "Power_trolley", 1);
    OLED_ShowString(0, 8, "Traget_Speed:", 1);
    OLED_ShowString(0, 16, "Left_Speed:", 1);
    OLED_ShowString(0, 24, "Right_Speed:", 1);
}

void Power_trolley_display(struct Powtrolley temp){
    OLED_Clear();
    Power_trolley_menu();

    if(temp.targ_speed>=0)
        OLED_ShowInt(78, 8, temp.targ_speed, 1);
    else{
        OLED_ShowString(78, 8, "-", 1);
        OLED_ShowInt(84, 8, (-temp.targ_speed), 1);
    }
    if(temp.l_speed>=0)
        OLED_ShowInt(66, 16, temp.l_speed, 1);
    else{
        OLED_ShowString(66, 16, "-", 1);
        OLED_ShowInt(72, 16, (-temp.l_speed), 1);
    }
    if(temp.r_speed>=0)
        OLED_ShowInt(72, 24, temp.r_speed, 1);
    else{
        OLED_ShowString(72, 24, "-", 1);
        OLED_ShowInt(78, 24, (-temp.r_speed), 1);
    }

    OLED_Refresh();
}

void Power_trolley_contr(struct Powtrolley temp){
    Uint16 target=1;
    if(temp.targ_speed>=0){
        target = temp.targ_speed * 15;  //pwm max:1500   targ_speed max:100
        EPwm1A_SetCompare(target);
        EPwm3A_SetCompare(target);

        EPwm1B_SetCompare(0);
        EPwm3B_SetCompare(0);
    }
    if(temp.targ_speed<0){
        target = -(temp.targ_speed * 15);  //pwm max:1500   targ_speed max:100
        EPwm1A_SetCompare(0);
        EPwm3A_SetCompare(0);

        EPwm1B_SetCompare(target);
        EPwm3B_SetCompare(target);
    }

}
