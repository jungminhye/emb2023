#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <ctype.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/msg.h>
#include "myMessage.h"
#include "accelMagGyro.h"
#include "timer.h"
#include "colorled.h"



int main(){   

typedef struct timelist {
	int mi;
	int sec;
	int ssec;
}timelist;

    timelist k = {0, 0, 0}; // 초기화된 timelist 구조체 선언
    int flag = 0;

    while (1)
    {
        startTimer(&k);
	//메세지큐에 값이 바뀌었는지 확인
       
        }
    

   printf("timer  stopped.\n");

    return 0;
}

