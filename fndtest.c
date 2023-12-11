
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

// fndtest.c

#include "fnd.h"


int main() 
{	
	int number;

	printf("숫자 입력: ");
	scanf("%d", &number);
	fndDisp(number, 0);
}
