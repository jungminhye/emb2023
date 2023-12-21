#include "led.h"
#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#define LED_DRIVER_NAME "/dev/periled"

static unsigned int ledValue = 0;
static int fd = 0;
int ledOnOff (int ledNum, int onOff)
{
	int i=1;
	i = i<<ledNum;
	ledValue = ledValue& (~i);
	if (onOff !=0) ledValue |= i;
	write (fd, &ledValue, 4);
}
int ledLibInit(void)
{
	fd=open("/dev/periled", O_WRONLY);
	ledValue = 0;
}
int ledLibExit(void)
{
ledValue = 0;
ledOnOff (0, 0);
close(fd);
}
int ledcntl(int argc)
{

unsigned int data = 0;
data = argc;
printf("write data: 0x%X\n", data);
fd = open(LED_DRIVER_NAME, O_RDWR);
if ( fd < 0 )
{
	perror("driver (//dev//cnled) open error.\n");
	return 1;
}
write(fd,&data,4);
close(fd);
return 0;
}   


