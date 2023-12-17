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
#include <string.h>

#include "colorled.h"


int main(void) {
redled();
sleep(1);
greenled();
sleep(1);
blueled();
sleep(1);
whiteled();
colorledoff();
}
~
~
