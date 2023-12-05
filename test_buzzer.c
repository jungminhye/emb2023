#include "buzzer.h"


int main(int argc, char **argv){
        int freIndex;
        freIndex = atoi(argv[1]);
        printf("freIndex : %d\n",freIndex);
	if(argc<2||findBuzzerSysPath()){
		printf("error,,\n");
		doHelp();
		return 1;
	}
	if(freIndex==0){
		printf("0");
		buzzerEnable(0);
	}
	else if(freIndex==99){
		printf("99");
		BGM();
	}
	else{
		printf("%d",freIndex);
		BuzzerStart(freIndex);
	}
		return 0;
}
