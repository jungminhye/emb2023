// button.h

#ifndef _BUTTON_H_
#define _BUTTON_H_

#define MESSAGE_ID1 1123
typedef struct
{
    long int messageNum;
    int keyInput;
    int pressed;
} BUTTON_MSG_T;

void* buttonThFunc(void*arg);
int probeButtonPath(char *newPath);
int buttonInit(void);
int buttonExit(void);

#endif

