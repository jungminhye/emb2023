#ifndef _BUZZER_H_
#define _BUZZER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <time.h>

#define MAX_SCALE_STEP  14
#define BUZZER_BASE_SYS_PATH "/sys/bus/platform/devices/"
#define BUZZER_FILENAME "peribuzzer"
#define BUZZER_ENABLE_NAME "enable"
#define BUZZER_FREQUENCY_NAME "frequency"

int findBuzzerSysPath(void);
void doHelp(void);
void buzzerEnable(int bEnable);
void setFrequency(int frequency);
void BGM(void);
int BuzzerStart(int n);

#endif
