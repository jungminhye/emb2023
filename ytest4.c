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
    } else if (totalSecondsTime1 > totalSecondsTime2) {
        printf("Player 2 Wins! Time: %d minutes and %d seconds\n", timestamps[1].mi, timestamps[1].sec);
    } else {
        printf("It's a Tie! Both players finished at the same time!\n");
    }
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


int main() {
    bmp1(); // 게임 시작화면 띄우기
    printf("화면 띄우기 완료 1\n");

    touchInit(); // 터치스크린 초기화
             int fd = open(FILEPATH, O_WRONLY);

//        int msgID = msgget(MESSAGE_ID, IPC_CREAT | 0666);
  //      if (msgID == -1)
     //   {
      //  perror("msgget");
        //return 1;
        //}
        // BMP_MSG_T recvMsg; // 메세지큐 구조체 정의
        int msgID1 = msgget(MESSAGE_ID1, IPC_CREAT | 0666);
        if (msgID1 == -1)
        {
        perror("msgget1");
        return 1;
        }
        BUTTON_MSG_T recvdMsgBut;
//printf("Message Queue ID: %d, %d\n", msgID, msgID1);



//      BUTTON_MSG_T recvdMsgBut;
        buttonInit();
        bmp1();
      //  touchInit();

    int msgID = msgget(MESSAGE_ID, IPC_CREAT | 0666); // 메세지큐 아이디 얻어오기
    BMP_MSG_T recvMsg;                                  // 메세지큐 구조체 정의

    int gameStarted = 0; // 게임이 시작되었는지 여부를 나타내는 플래그

  
        // 터치 입력을 받을 때까지 대기
        do {
            msgrcv(msgID, &recvMsg, sizeof(recvMsg) - sizeof(long int), 0, 0);
        } while (recvMsg.keyInput != 999 || recvMsg.pressed != 1 || gameStarted);

        printf("다시 돌아옴?");

        // 게임 시작을 누르면
        if (240 < recvMsg.x && recvMsg.x < 800 && 210 < recvMsg.y && recvMsg.y < 380) {
            bmp2(); // race game. 자동차를 선택하세요! 화면
            // bgm 재생
            printf("자동차 선택화면 입니다!\n");

           
            do {  //값을 받아야지만 밑으로
                msgrcv(msgID, &recvMsg, sizeof(recvMsg) - sizeof(long int), 0, 0);
            } while (!((630 < recvMsg.x && recvMsg.x < 780 && 55 < recvMsg.y && recvMsg.y < 280)||(220 < recvMsg.x && recvMsg.x < 370 && 55 < recvMsg.y && recvMsg.y < 280)));
           while(1){
		
	       // 누른 값이 빨간 자동차라면
	    	if(630 < recvMsg.x && recvMsg.x < 780 && 55 < recvMsg.y && recvMsg.y < 280){
                    
            		bmp3(); // 빨간 자동차 준비
            		printf("빨간 자동차 준비중!\n");
            		gameStarted = 1; // 게임이 시작되었음을 플래그로 표시
        	
	    		    do {
         	   	        msgrcv(msgID1, &recvdMsgBut, sizeof(BUTTON_MSG_T) - sizeof(long int), 0, IPC_NOWAIT);
            		 } while (!(msgrcv(msgID1, &recvdMsgBut, sizeof(BUTTON_MSG_T) - sizeof(long int), 0, IPC_NOWAIT) >= 0));

			            if (recvdMsgBut.keyInput == 102){
                          
                       lseek(fd, 0, SEEK_SET);
                       read(fd, buffer, sizeof(buffer));
                       buffer[0] = (buffer[0] == '0') ? '1' : '0';
                       lseek(fd, 0, SEEK_SET);
                       write(fd, buffer, sizeof(buffer));
                       printf("Button Pressed: %c\n", buffer[0]);
                            }
                        do {
         	   	            msgrcv(msgID1, &recvdMsgBut, sizeof(BUTTON_MSG_T) - sizeof(long int), 0, IPC_NOWAIT);
            		     } while (!(msgrcv(msgID1, &recvdMsgBut, sizeof(BUTTON_MSG_T) - sizeof(long int), 0, IPC_NOWAIT) >= 0));
                        if (recvdMsgBut.keyInput == 102){
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
                        sleep(3);
                        bmp6();
                          }
                            }
			  
                     	do {
         	   	        msgrcv(msgID1, &recvdMsgBut, sizeof(BUTTON_MSG_T) - sizeof(long int), 0, IPC_NOWAIT);
            		 } while (!(msgrcv(msgID1, &recvdMsgBut, sizeof(BUTTON_MSG_T) - sizeof(long int), 0, IPC_NOWAIT) >= 0));
                            
                    	if (buffer[0] == '0' && ifPlay)
                      	{
                    		ifPlay = 0;
                    		bmp7();         // 시간을 k 구조체에 저장하는 코드 (예: clock_gettime 사용)
                       }
                       if (recvdMsgBut.keyInput == 102){
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
                       
                       do {  //값을 받아야지만 밑으로
                            msgrcv(msgID, &recvMsg, sizeof(recvMsg) - sizeof(long int), 0, 0);
                       } while (!(30 < recvMsg.x && recvMsg.x < 160 && 430 < recvMsg.y && recvMsg.y < 535));
                            break; 
                                 }
                            }
                            

		}
        	// 누른 값이 초록 자동차라면
        	else if (220 < recvMsg.x && recvMsg.x < 370 && 55 < recvMsg.y && recvMsg.y < 280) {
           	 	bmp4(); // 초록 자동차 준비
            		printf("초록 자동차 준비중!\n");
			gameStarted = 1; // 게임이 시작되었음을 플래그로 표시

			//do {
          //                   msgrcv(msgID, &recvMsg, sizeof(recvMsg) - sizeof(long int), 0, 0);
           //             } while (!())
			
             //           타이머 실행 코드

        	//}
		}
        printf("if문 나감..?\n");
    
	}	
    }
   
    return 0;
}
