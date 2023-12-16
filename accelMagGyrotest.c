#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include "accelMagGyro.h"


int main(void){

//accel[0],accel[1],accel[2]
//magne[0],magne[1],magne[2]
AccelMagneGyro();

return 0;
}
