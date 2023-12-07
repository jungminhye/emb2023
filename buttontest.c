#include <stdio.h>
#include "button.h"

int main() {
    // 버튼 초기화 함수 호출
    if (buttonInit() == 0) {
        printf("Button initialization failed.\n");
        return -1;
    }

    // 여기에 추가적인 작업을 수행할 수 있습니다.

    // 버튼 쓰레드 함수 호출 (무한 루프에서 버튼 입력을 처리합니다)
    buttonThFunc(NULL);

    // 버튼 종료 함수 호출
    buttonExit();

    return 0;
}

