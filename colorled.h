#ifndef _COLORLED_DRV_H
#define _COLORLED_DRV_H

int pwmActiveAll(void);
int pwmInactiveAll(void);
int pwmSetDuty(int dutyCycle, int pwmIndex);
int pwmSetPeriod(int Period, int pwmIndex);
int pwmSetPercent(int percent, int ledColor);
int pwmStartAll(void);
int pwmLedInit(void);
void red(void);
void green(void);
void blue(void);
void redled(void);
void greenled(void);
void blueled(void);


#endif// _COLORLED_DRV_H



