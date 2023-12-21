#include <stdio.h>
#include <fcntl.h>
#include <pthread.h>
#include "button.h"
#include <sys/msg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <stdlib.h>
#include <linux/fb.h>
#include "touch.h"
#include "bmpviewer.h"
#include "button.h"
#include "led.c"
#define FILEPATH "/home/ecube/startflag"

#define MAX_TIMESTAMPS 2
int currentIndex = 0; // 현재 인덱스를 나타내는 변수

typedef struct timelist {
    int mi;
    int sec;
    int ssec;
} timelist;

timelist timestamps[MAX_TIMESTAMPS];


timelist k = {0, 0, 0};

char buffer[2];

int ifPlay = 0; // 시간을 재는 쓰레드를 실행 중인지 여부를 나타내는 플래그

void printTimestamps()
{
        printf("Stored Timestamps:\n");
        for (int i = 0; i < MAX_TIMESTAMPS; ++i)
                {
                printf("Timestamp %d: %d minutes, %d seconds, %d milliseconds\r\n ", i + 1, timestamps[i].mi, timestamps[i].sec, timestamps[i].ssec);
                }
        printWinnerMessage(timestamps);
}

void printWinnerMessage(timelist timestamps[MAX_TIMESTAMPS]) {
        int totalSecondsTime1 = timestamps[0].mi * 60 + timestamps[0].sec;
        int totalSecondsTime2 = timestamps[1].mi * 60 + timestamps[1].sec;

    if (totalSecondsTime1 < totalSecondsTime2) {
        printf("Player 1 Wins! Time: %d minutes and %d seconds\n", timestamps[0].mi, timestamps[0].sec);
	lcdtextwrite("PLAYER 1 IS WINNER!",1);
    } else if (totalSecondsTime1 > totalSecondsTime2) {
        printf("Player 2 Wins! Time: %d minutes and %d seconds\n", timestamps[1].mi, timestamps[1].sec);
	lcdtextwrite("PLAYER 2 IS WINNER!",1);
    } else {
        printf("It's a Tie! Both players finished at the same time!\n");
    }
}


void* musicThread(void* arg) {
    playCNT();
    playBGM();

    // 여기에 음악을 재생하는 코드를 추가
    printf("Music Thread Started\n");

   // int fd = open(FILEPATH, O_RDONLY);
   // if (fd == -1) {
    //    perror("open err");
     //   exit(1);
   // }

    
       // char buffer[2];
       // lseek(fd, 0, SEEK_SET);
     //   read(fd, buffer, sizeof(buffer));

        if (buffer[0] == '0') {
            // startflag가 0이면 노래를 멈추고 쓰레드 종료
            printf("Stop Music\n");
            buzzerStopSong();
	    // 여기에 노래 정지 코드 추가
           // break;
        }

        // 추가적인 음악 처리나 대기 코드
        // ...

        usleep(100000);  // 100ms 대기
    

    close(fd);
    printf("Music Thread Finished\n");
    return NULL;
}



void* timerThread()
{
         timelist k = {0, 0, 0};
        if(buffer[0] =='1')
        {
                sleep (3);

                while (1)
                {
                startTimer(&k);
                usleep(10000); // 10ms 대기
                if(buffer[0] == '0')
                        {
                                timestamps[currentIndex] = k; // 현재 시간값을 배열에 저장
                                currentIndex++;
                                if (currentIndex >= MAX_TIMESTAMPS)
                                printTimestamps();
                                // Assume timelist player1Time and player2Time have been populated with their respective times
                                //printWinnerMessage(timestamps);
                                break;
                        }
                }
        }

    return 0;
}


int main(void)
{
        int fd = open(FILEPATH, O_WRONLY);

        int msgID = msgget(MESSAGE_ID, IPC_CREAT | 0666);
        if (msgID == -1)
        {
        perror("msgget");
        return 1;
        }
         BMP_MSG_T recvMsg; // 메세지큐 구조체 정의
        int msgID1 = msgget(MESSAGE_ID1, IPC_CREAT | 0666);
        if (msgID1 == -1)
        {
        perror("msgget1");
        return 1;
        }
        BUTTON_MSG_T recvdMsgBut;

        buttonInit();
        bmp1();
        touchInit();


do{
    msgrcv(msgID, &recvMsg, sizeof (recvMsg)-sizeof (long int), 0, 0);
    printf("화면 띄우기 완료 2");
                switch (recvMsg.keyInput)
                    {
                        case 999:  //recvMsg.keyInput가 999일 때만 수행
                                if (recvMsg.pressed == 1) // 터치를 눌렀을 때
                                {
                                         // 게임 시작을 누르면
                                        if (240 < recvMsg.x && recvMsg.x < 800 && 210 < recvMsg.y && recvMsg.y < 380)
                                        {
                                                bmp2();
                                                if(630 < recvMsg.x && recvMsg.x < 780 && 55 < recvMsg.y && recvMsg.y < 280)
                                                {
                                                        // 빨간 자동차 누르면
                                                        bmp3(); // 빨간 자동차 준비
                                                                    do{
                                                                                                                                                
                                                                        
                                                                                 if (msgrcv(msgID1, &recvdMsgBut, sizeof(BUTTON_MSG_T) - sizeof(long int), 0, IPC_NOWAIT) >= 0)
                                                                {
                                                                        if (recvdMsgBut.keyInput == 102)
                                                                        {
                                                                        lseek(fd, 0, SEEK_SET);
                                                                        read(fd, buffer, sizeof(buffer));

                                                                        buffer[0] = (buffer[0] == '0') ? '1' : '0';
                                                                        lseek(fd, 0, SEEK_SET);
                                                                        write(fd, buffer, sizeof(buffer));
                                                                        printf("Button Pressed: %c\n", buffer[0]);
                                                                        if (buffer[0] == '1' && !ifPlay)
                                                                                {

											ifPlay = 1;
                                                                                pthread_t musicThreadID;
											pthread_create(&musicThreadID, NULL, musicThread, NULL);

									       	pthread_t timerThreadId;
                                                                                pthread_create(&timerThreadId, NULL, timerThread, buffer);
                                                                                bmp5();
                                                                                ledcntl(0xDB);
										sleep(1);
										ledcntl(0x1B);
										sleep(1);
										ledcntl(0x03);
										sleep(1);
										ledcntl(0xff);
                                                                                bmp6();
                                                                                }
                                                                        else if (buffer[0] == '0' && ifPlay)
                                                                                {
                                                                                ifPlay = 0;
                                                                                bmp7();         // 시간을 k 구조체에 저장하는 코드 (예: clock_gettime 사용)
                                                                                }
                                                                        }
                                                                }

                                                                                }
while(1);//second o
						}
						else if (220 < recvMsg.x && recvMsg.x < 370 && 55 < recvMsg.y && recvMsg.y < 280)
                                                 {
                                                        // 초록 자동차 누르면
                                                        bmp4(); // 초록 자동차 준비
						do{
							if (msgrcv(msgID1, &recvdMsgBut, sizeof(BUTTON_MSG_T) - sizeof(long int), 0, IPC_NOWAIT) >= 0)
                                                                {
                                                                        if (recvdMsgBut.keyInput == 102)
                                                                        {
                                                                        lseek(fd, 0, SEEK_SET);
                                                                        read(fd, buffer, sizeof(buffer));

                                                                        buffer[0] = (buffer[0] == '0') ? '1' : '0';
                                                                        lseek(fd, 0, SEEK_SET);
                                                                        write(fd, buffer, sizeof(buffer));
                                                                        printf("Button Pressed: %c\n", buffer[0]);
                                                                        if (buffer[0] == '1' && !ifPlay)
                                                                                {
                                                                                ifPlay = 1;
                                                                                pthread_t timerThreadId;
                                                                                pthread_create(&timerThreadId, NULL, timerThread, buffer);
                                                                                bmp5();
                                                                                ledcntl(0xDB);
										sleep(1);
										ledcntl(0x1b);
										sleep(1);
										ledcntl(0x03);
										sleep(1);
										ledcntl(0xff);
                                                                                bmp6();
                                                                                }
                                                                        else if (buffer[0] == '0' && ifPlay)
                                                                                {
                                                                                ifPlay = 0;
                                                                                bmp7();         // 시간을 k 구조체에 저장하는 코드 (예: clock_gettime 사용)
                                                                                }
                                                                        }
                                                                }

						 }
						while(1);
						 }
					}

				}
		    }
}

		while(1);
		}

