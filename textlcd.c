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
#include "textlcd.h"


#define TEXTLCD_DRIVER_NAME "/dev/peritextlcd"

void doHelp(void)
{
    printf("usage: textlcdtest <linenum> <'string'>\n");
    printf("       linenum => 1 ~ 2\n");
    printf("  ex) textlcdtest 2 'test hello'\n");
}



void lcdtextwrite(const char *str1, int lineFlag)
{
	unsigned int linenum = 0;
	stTextLCD stlcd;  // stTextLCD 구조체를 가지고 드라이버와 인터페이스
	int fd;
	int len;
	printf("Debug: Entering lcdtextwrite\n");
	memset(&stlcd, 0, sizeof(stTextLCD)); // 구조체 초기화
		
    
	if (lineFlag == 1)
        stlcd.cmdData = CMD_DATA_WRITE_LINE_1;
	else if (lineFlag == 2)
        stlcd.cmdData = CMD_DATA_WRITE_LINE_2;
	else
    	{
        	printf("라인 번호: %d 올바르지 않습니다. 범위는 (1 ~ 2)\n", lineFlag);
        	return;
    	}

    len = strlen(str1);
    if (len > COLUMN_NUM)
        memcpy(stlcd.TextData[stlcd.cmdData - 1], str1, COLUMN_NUM);
    else
        memcpy(stlcd.TextData[stlcd.cmdData - 1], str1, len);

    stlcd.cmd = CMD_WRITE_STRING;

    fd = open(TEXTLCD_DRIVER_NAME, O_RDWR); // 드라이버 열기
    if (fd < 0)
    {
        perror("드라이버 (//dev//peritextlcd) 열기 오류.\n");
        return;
    }
	printf("Debug: Writing to driver\n");
    write(fd, &stlcd, sizeof(stTextLCD));
    close(fd);

}

