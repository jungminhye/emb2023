#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int main(){
	//기본 상태는 정지상태
	//while문 계속 돌다가 read 해서 출발신호 받으면 출발(기본 속도)
	//계속 read 하면서 센서 값 바뀌면 모터 속도, 방향 제어
	
	const char *usbPath = "/dev/ttyACM0";
	const char *dataPath = "/home/ecube/data";
	const char *startPath = "/home/ecube/startflag";

	const char *clearall = "gpio writeall 00\r";
	const char *clear0 = "gpio clear 0\r";
	const char *clear1 = "gpio clear 1\r";
	const char *clear2 = "gpio clear 2\r";
	const char *clear3 = "gpio clear 3\r";
 	const char *set0 = "gpio set 0\r";
	const char *set1 = "gpio set 1\r";
        const char *set2 = "gpio set 2\r";
        const char *set3 = "gpio set 3\r";
		
	int gyro[4];
	int startflag;

	int fdusb = open(usbPath, O_WRONLY);

	if(fdusb<= -1){
		perror("Error opening serial port");
		return 1;
	}
	
	write(fdusb,clearall,strlen(clearall));

	while(1){
		FILE *fpdata = fopen(dataPath, "rt");
		FILE *fpstart = fopen(startPath, "rt");

		fscanf(fpdata,"%d",&startflag);
		fscanf(fpdata,"%d, %d, %d, %d",&gyro[1],&gyro[2],&gyro[3],&gyro[0]);
		
		printf("startFlag:%d\ngyroscope:%d,%d,%d\n",startflag,gyro[1],gyro[2],gyro[3]);
		fclose(fpdata);

	if(startflag==1)	//출발 신호
		{	
			if(gyro[1]>=-1000&&gyro[1]<=1000)	//직진
			{
				if(gyro[2]>=-1000&&gyro[2]<=1000)  //멈춰
                        	{
                                	write(fdusb,clearall,strlen(clearall));
                        	}
				else if(gyro[2]<-1000)   //전진, 속도
                        	{
                                	write(fdusb,clear1,strlen(clear1));
                                	write(fdusb,clear3,strlen(clear3));
                                	write(fdusb,set2,strlen(set2));
                                	write(fdusb,set0,strlen(set0));
                                	usleep(10000-gyro[2]);
                                	write(fdusb,clear2,strlen(clear2));
                                	write(fdusb,clear0,strlen(clear0));
                                	usleep(50);
                        	}
				else            //후진, 속도
	                        {
					write(fdusb,clear0,strlen(clear0));
                                        write(fdusb,clear2,strlen(clear2));
        	                        write(fdusb,set1,strlen(set1));
                	                write(fdusb,set3,strlen(set3));
                        	        usleep(10000+gyro[2]);
                                	write(fdusb,clear1,strlen(clear1));
              	        	        write(fdusb,clear3,strlen(clear3));
                	                usleep(50);

                        	}


			}
			else if (gyro[1]<-1000)		//좌회전
			{
                                        write(fdusb,clear1,strlen(clear1));
                                        write(fdusb,clear3,strlen(clear3));
                                        write(fdusb,set0,strlen(set0));
					usleep(500);
					write(fdusb,clear0,strlen(clear0));
					usleep(1000);
                                        write(fdusb,set2,strlen(set2));
                                        usleep(10000-gyro[1]);
                                        write(fdusb,clear2,strlen(clear2));
                                        usleep(500);
                         }
			else //우회전
			{
				        write(fdusb,clear1,strlen(clear1));
                                        write(fdusb,clear3,strlen(clear3));
                                        write(fdusb,set2,strlen(set2));
                                        usleep(500);
                                        write(fdusb,clear2,strlen(clear2));
                                        usleep(1000);
                                        write(fdusb,set0,strlen(set0));
                                        usleep(10000-gyro[1]);
                                        write(fdusb,clear0,strlen(clear0));
                                        usleep(500);
	
			}
			
		
		}
		else if(startflag==0) 	//정지 신호
		{
			write(fdusb,clearall,strlen(clearall));
			close(fdusb);
			break;

		}
	}
}

