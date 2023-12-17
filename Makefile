CC = arm-linux-gnueabi-gcc
AR = arm-linux-gnueabi-ar

all:test_buzzer

test_buzzer:libMyPeri.a test_buzzer.c
	$(CC) -o test_buzzer test_buzzer.c -lMyPeri -L.
	scp test_buzzer ecube@172.20.10.3:/home/ecube/test_buzzer

libMyPeri.a: buzzer.o
	$(AR) rc libMyPeri.a buzzer.o

buzzer.o: buzzer.h buzzer.c
	$(CC) -o buzzer.o -c buzzer.c

clean:
	rm -f test_buzzer buzzer.o libMyPeri.a


