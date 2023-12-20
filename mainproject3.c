#include <stdio.h>
#include <fcntl.h>
#include <pthread.h>
#include "button.h"
#include <sys/msg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define FILEPATH "/home/ecube/startflag"

volatile char buffer [3];
 pthread_mutex_t bufferMutex = PTHREAD_MUTEX_INITIALIZER;
void* musicThread(void* arg) {
   // playCNT();
   // playBGM();

    // 여기에 음악을 재생하는 코드를 추가
    printf("Music Thread Started\n");
    int fd = open(FILEPATH, O_RDONLY);
    if (fd == -1) {
        perror("open err");
        exit(1);
    }

    while (1) {
       // char buffer[2];
        lseek(fd, 0, SEEK_SET);
        read(fd, buffer, sizeof(buffer));
	pthread_mutex_lock(&bufferMutex);
        if (buffer[0] == '1') {
            // startflag가 0이면 노래를 멈추고 쓰레드 종료
            //printf("Stop Music\n");
            // 여기에 노래 정지 코드 추가
	 //buzzerStopSong();		
            // 쓰레드 종료
            playCNT();
            playBGM();
        }
	else
		break;
	   pthread_mutex_unlock(&bufferMutex);
        // 추가적인 음악 처리나 대기 코드
        // ...

        usleep(100000);  // 100ms 대기
    }

    close(fd);
    printf("Music Thread Finished\n");
    return NULL;
}

int main(void) {
    int fd = open(FILEPATH, O_WRONLY);

    if (fd == -1) {
        perror("open err");
        return 1;
    }

    buttonInit();

    int msgID = msgget(MESSAGE_ID, IPC_CREAT | 0666);
    BUTTON_MSG_T recvdMsg;

    int ifPlay = 0;
    pthread_t musicThreadID;  // 음악을 재생할 스레드의 ID

    while (1) {
        if (msgrcv(msgID, &recvdMsg, sizeof(BUTTON_MSG_T) - sizeof(long int), 0, IPC_NOWAIT) >= 0) {
            // Button!
            if (recvdMsg.keyInput == 114) {  // 제일 오른쪽거.
                // startflag를 0으로 설정하고 쓰레드 종료
                //char buffer = '0';
                lseek(fd, 0, SEEK_SET);
		pthread_mutex_lock(&bufferMutex);
                write(fd, &buffer, 1);
		pthread_mutex_unlock(&bufferMutex);
                break;
            } else if (recvdMsg.keyInput == 102) {  // 제일 왼쪽거 Play
                //char buffer[2];
                lseek(fd, 0, SEEK_SET);
		pthread_mutex_lock(&bufferMutex);
                read(fd, buffer, sizeof(buffer));

                // 현재 값이 0이면 1로, 1이면 0으로 바꾸기
                buffer[0] = (buffer[0] == '0') ? '1' : '0';

                // 파일에 새로운 값 쓰기
                lseek(fd, 0, SEEK_SET);
                write(fd, buffer, sizeof(buffer));

                if (buffer[0] == '1' && !ifPlay) {
                    // 쓰레드 시작
                    pthread_create(&musicThreadID, NULL, musicThread, NULL);
                    ifPlay = 1;
                }
                printf("Button Pressed: %c\n", buffer[0]);
		pthread_mutex_unlock(&bufferMutex);
            } else if (recvdMsg.keyInput == 158) {  // 두번째 거. Pause
                ifPlay = 0;
            } else if (recvdMsg.keyInput == 217) {  // 세번째 거. Stop
                ifPlay = 0;
            }
        }
        usleep(1000);  // Every 1ms.
    }

    // 음악 스레드가 끝날 때까지 대기
    if (ifPlay) {
        pthread_join(musicThreadID, NULL);
    }

    buttonExit();
    close(fd);

    return 0;
}

