all:test_buzzer

test_buzzer:libMyPeri.a test_buzzer.c
	arm-linux-gnueabi-gcc -o test_buzzer test_buzzer.c -lMyPeri -L.

libMyPeri.a:buzzer.o
	arm-linux-gnueabi-ar rc libMyPeri.a buzzer.o

buzzer.o:buzzer.c
	arm-linux-gnueabi-gcc -o buzzer.o -c buzzer.c

clean:
	rm -f test_buzzer buzzer.o libMyPeri.a


