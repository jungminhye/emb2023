#include "buzzer.h"

const int musicScale[MAX_SCALE_STEP] = { 262,294,330,349,392,440,494,523,587,659,698,784,880,988 };

char gBuzzerBaseSysDir[128];

int findBuzzerSysPath(){	//부저 파일 경로 찾는 함수
        DIR* dir_info = opendir(BUZZER_BASE_SYS_PATH);  //해당 디렉토리를 열면 >포인터를 반환하고 아니면 NULL
        int ifNotFound = 1;
        if(dir_info != NULL){
                while(1){
                        struct dirent *dir_entry;
                        dir_entry = readdir(dir_info);
                        if(dir_entry==NULL) break;
                        if(strncasecmp(BUZZER_FILENAME,dir_entry->d_name,strlen(BUZZER_FILENAME))==0){
                                ifNotFound = 0;
                                sprintf(gBuzzerBaseSysDir,"%s%s/",BUZZER_BASE_SYS_PATH,dir_entry->d_name);
                        }
                }
        }
        printf("find %s\n",gBuzzerBaseSysDir);  //부저 경로 출력
        return ifNotFound;      //경로 확인 못했으면 1 아니면 0
}

void doHelp(void){
        printf("Usage:\n");
        printf("buzzertest <buzzerNo>\n");
        printf("buzzerNo:\n");
        printf("do(1),re(2),mi(3),fa(4),sol(5),ra(6),si(7)\n");
	printf("[high]do(8),re(9),mi(10),fa(11),sol(12),ra(13),si(14)\n");
        printf("off(0)");
}
void buzzerEnable(int bEnable){
        char path[200];	
        sprintf(path,"%s%s",gBuzzerBaseSysDir,BUZZER_ENABLE_NAME);	//enable 파일 경로 복사
        int fd=open(path,O_WRONLY);	//쓰기모드로 오픈
        if(bEnable) write(fd,&"1",1);	//입력값 1이면 enable
        else  write(fd,&"0",0);		//1이 아니면 enable X
        close(fd);	//파일 close
}
void setFrequency(int frequency){
        char path[200];
        sprintf(path,"%s%s",gBuzzerBaseSysDir,BUZZER_FREQUENCY_NAME);	//frequency 파일 경로 복사
	int fd = open(path,O_WRONLY);	//쓰기모드로 오픈
	dprintf(fd,"%d",frequency);	//입력값 쓰기
        close(fd);	//파일 close
}
void BGM(void){
	struct timespec delay1;
	struct timespec delay3;
	
	printf("BGM\n");

    	delay1.tv_sec = 0;
    	delay1.tv_nsec = 500000000; // 0.5초를 나노초로 표현

	delay3.tv_sec = 1;
        delay3.tv_nsec = 500000000; // 0.5초를 나노초로 표현
    	
	setFrequency(musicScale[11]);
	buzzerEnable(1);
	nanosleep(&delay3, NULL);

	setFrequency(musicScale[9]);
	nanosleep(&delay1, NULL);

	setFrequency(musicScale[11]);
        nanosleep(&delay3, NULL);

        setFrequency(musicScale[9]);
        nanosleep(&delay1, NULL);

	setFrequency(musicScale[12]);
        nanosleep(&delay1, NULL);

	setFrequency(musicScale[11]);
        nanosleep(&delay1, NULL);

	setFrequency(musicScale[10]);
        nanosleep(&delay1, NULL);

	setFrequency(musicScale[9]);
        nanosleep(&delay1, NULL);

}

int BuzzerStart(int n){
 	printf("buzzerOn");

	setFrequency(musicScale[n-1]);   //부저
        buzzerEnable(1);
	
	return 0;
}

