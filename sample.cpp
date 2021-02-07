#include "mbed.h"

//ステッピングモータのピンの指定
DigitalOut step_a(D2);
DigitalOut step_b(D3);

int mode = 0;       //ピンの出力の切り替えに用いる変数
double TIME = 0.01; //タイマ割り込みの周期
Ticker timer;       //ステッピングモーターのタイマー割り込み

void add_stepper_CW(void){   //ステッピングモーターを時計回りに回転

    switch(mode){
        case 0:
        step_a = 1;
        step_b = 1;
        mode++;
        break;

        case 1:
        step_a = 1;
        step_b = 0;
        mode++;
        break;

        case 2:
        step_a = 0;
        step_b = 0;
        mode++;
        break;

        case 3:
        step_a = 0;
        step_b = 1;
        mode = 0;
        break;

    }
}

void rotateCW(void){                        //タイマ割り込み用関数（時計回り）
    timer.attach(&add_stepper_CW,TIME);
}

int main (){    //main関数
    rotateCW();
}
