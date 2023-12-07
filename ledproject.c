#include <stdio.h>
#include "led.h"  // libMyPeri.a를 사용하기 위해 헤더 파일을 include합니다.

int main(int argc, char **argv)
{
    ledcntl(argc,argv);
}

