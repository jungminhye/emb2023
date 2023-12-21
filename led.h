#ifndef _LED_H_

#define _LED_H_

#define LED_DRIVER_NAME "/dev/periled”

int ledLibInit(void);
int ledOnOff (int ledNum, int onOff);
int ledStatus (void);
int ledLibExit(void);
int ledcntl(int argc);
#endif _LED_H_
