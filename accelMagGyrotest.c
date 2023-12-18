#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include "accelMagGyro.h"

int main(void){

int accel1, accel2, accel3;
int magne1, magne2, magne3;
int gyro1, gyro2, gyro3;

Accel(&accel1, &accel2, &accel3);
Mage(&magne1, &magne2, &magne3);
Gyro(&gyro1, &gyro2, &gyro3);

printf("\n accel 1번 값은 %d\n",accel1);

printf("\n magne 1번 값은 %d\n",magne1);

printf("\n gyro 1번 값은 %d\n", gyro1);

}

