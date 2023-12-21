#include <sys/ipc.h>
#include <stdio.h>
#include <stdlib.h>
#include <linux/fb.h>
#include "touch.h"
#include "bmpviewer.h"

int main() {
    bmp1(); // 게임 시작화면 띄우기
    printf("화면 띄우기 완료 1\n");

    touchInit(); // 터치스크린 초기화

    int msgID = msgget(MESSAGE_ID, IPC_CREAT | 0666); // 메세지큐 아이디 얻어오기
    BMP_MSG_T recvMsg;                                  // 메세지큐 구조체 정의

    int gameStarted = 0; // 게임이 시작되었는지 여부를 나타내는 플래그

    while (1) {
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
		
	       // 누른 값이 빨간 자동차라면
	    	if(630 < recvMsg.x && recvMsg.x < 780 && 55 < recvMsg.y && recvMsg.y < 280){
            		bmp3(); // 빨간 자동차 준비
            		printf("빨간 자동차 준비중!\n");
            		gameStarted = 1; // 게임이 시작되었음을 플래그로 표시
        	
	    		do {
         	   	     msgrcv(msgID, &recvMsg, sizeof(recvMsg) - sizeof(long int), 0, 0);
            		} while (!(버튼이 눌림))
			
			타이머시
		}
        	// 누른 값이 초록 자동차라면
        	else if (220 < recvMsg.x && recvMsg.x < 370 && 55 < recvMsg.y && recvMsg.y < 280) {
           	 	bmp4(); // 초록 자동차 준비
            		printf("초록 자동차 준비중!\n");
			gameStarted = 1; // 게임이 시작되었음을 플래그로 표시

			do {
                             msgrcv(msgID, &recvMsg, sizeof(recvMsg) - sizeof(long int), 0, 0);
                        } while (!(버튼이 눌림))
			
                        타이머 실행 코드

        	}

        printf("if문 나감..?\n");
    
	}	
    }

    return 0;
}
