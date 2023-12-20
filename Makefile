CC = arm-linux-gnueabi-gcc
AR = arm-linux-gnueabi-ar

all:controller

controller:libMyPeri.a controller.c
	$(CC) -o controller controller.c -lMyPeri -L.

libMyPeri.a: buzzer.o accelMagGyro.o colorled.o button.o textlcd.o fnd.o led.o touch.o
	$(AR) rc libMyPeri.a buzzer.o accelMagGyro.o colorled.o button.o textlcd.o fnd.o led.o touch.o

buzzer.o: buzzer.h buzzer.c
	$(CC) -o buzzer.o -c buzzer.c
accelMagGyro.o: accelMagGyro.h accelMagGyro.c
	$(CC) -o accelMagGyro.o -c accelMagGyro.c
colorled.o: colorled.h colorled.c
	$(CC) -o colorled.o -c colorled.c
button.o: button.h button.c
	$(CC) -o button.o -c button.c

textlcd.o:textlcd.h textlcd.c
	$(CC) -o textlcd.o -c textlcd.c

fnd.o: fnd.h fnd.c
	$(CC) -o fnd.o -c fnd.c

led.o: led.h led.c
	$(CC) -o led.o -c led.c

touch.o: touch.c touch.h
	$(CC) touch.c -c -o touch.o


clean:
	rm -f controller buzzer.o accelMagGyro.o colorled.o temperature.o button.o textlcd.o fnd.o led.o libMyPeri.a
