/*
 * eQEP.c
 *
 *  Created on: 2024��6��5��
 *      Author: alpha
 */

#include <eQEP.h>

 unsigned int motor_speed=0;
 int DirectionQep=0;
//extern int LineEncoder;
 int Encoder_N=2000;
 float Speed_Mr_RPM=0;
 Uint32 Position_k_1=0;
 Uint32 Position_k=0;

void eQEP_Init(void){
    EALLOW;
    SysCtrlRegs.PCLKCR1.bit.EQEP1ENCLK = 1;
    EDIS;

    InitEQep1Gpio();
    Frencal_Init();
    //FREQCAL freq=FREQCAL_DEFAULTS;
}

void Frencal_Init(void){
#if(CPU_FRQ_150MHZ) // set unit timer overflow frequency
    EQep1Regs.QUPRD = 150000;  //1000Hz
#endif
#if(CPU_FRQ_100MHZ)
    EQep1Regs.QUPRD = 100000;  //1000Hz
#endif

    EQep1Regs.QDECCTL.bit.QSRC = 2;     //up count mode //freq measurement
    EQep1Regs.QDECCTL.bit.XCR = 0;      //2x resolution cnt falling and rising edges

    EQep1Regs.QEPCTL.bit.FREE_SOFT = 2;
    EQep1Regs.QEPCTL.bit.PCRM = 00;     //QPOSCNT reset on index event
    //EQep1Regs.QEPCTL.bit.PCRM = 3;     //QPOSCNT reset on unit time event
    EQep1Regs.QEPCTL.bit.UTE = 1;       //Unit Timer out Enable
    EQep1Regs.QEPCTL.bit.QCLM = 1;      //latch on unit time out
    EQep1Regs.QPOSMAX = Encoder_N;
    EQep1Regs.QEPCTL.bit.QPEN = 1;      //QEP enable
#if (CPU_FRQ_150MHZ)
    EQep1Regs.QCAPCTL.bit.UPPS=2; // 1/4 for unit position at 150MHz SYSCLKOUT
#endif
#if (CPU_FRQ_100MHZ)
    EQep1Regs.QCAPCTL.bit.UPPS=3; // 1/8 for unit position at 100MHz SYSCLKOUT;
#endif

    EQep1Regs.QCAPCTL.bit.CCPS=7; // 1/128 for CAP clock
    EQep1Regs.QCAPCTL.bit.CEN=1; // QEP Capture Enable

}

Uint32 QEP_pos_speed_get_Calc(void){
    Uint32 tmp1;

    DirectionQep=EQep1Regs.QEPSTS.bit.QDF; //���ת������

    if(EQep1Regs.QFLG.bit.IEL==1){ //��������ź�
        EQep1Regs.QCLR.bit.IEL=1;//����ж��ź�
    }
    if(EQep1Regs.QFLG.bit.UTO==1){//�����ʱ����׼��Ԫ��������¼� 0.001�ж�һ��
        Position_k_1=1.0*EQep1Regs.QPOSLAT;//��ȡ��ǰλ��
        if(DirectionQep==0){ //POSCNT is counting down
            if(Position_k >= Position_k_1)
                tmp1=Position_k - Position_k_1;//��ǰλ�û�û�й���
            else
                tmp1=Encoder_N+(Position_k - Position_k_1);//��ǰλ���ѹ���
        }
        else if(DirectionQep==1){//POSCNT is counting up
            if(Position_k <= Position_k_1)
                tmp1=Position_k_1 - Position_k;//��ǰλ�û�û�й���
            else
                tmp1=Encoder_N+(Position_k_1 - Position_k);//��ǰλ���ѹ���
        }
        //Speed_Mr_RPM=(tmp1/80)*60;//ת/����
        Position_k=Position_k_1;//������һ��λ��
        EQep1Regs.QCLR.bit.UTO=1;
        /*
        if(delay_show%1000==0){//1����ʾһ��
            motor_speed=Speed_Mr_RPM;
            LCD_ShowNum(7,0,motor_speed/100%10);//��ʾ��λ
            LCD_ShowNum(8,0,motor_speed/10%10);//��ʾʮλ
            LCD_ShowNum(9,0,motor_speed/1%10);//��ʾ��λ
            delay_show=0;
        }
        */

    }
    return tmp1;
}
