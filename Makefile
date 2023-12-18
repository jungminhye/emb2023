CC = arm-linux-gnueabi-gcc
AR = arm-linux-gnueabi-ar

all:kartrider

kartrider:libMyPeri.a kartrider.c
	$(CC) -o kartrider kartrider.c -lMyPeri -L.
	scp kartrider ecube@172.20.10.3:/home/ecube/kartrider

libMyPeri.a: buzzer.o accelMagGyro.o colorled.o temperature.o button.o textlcd.o fnd.o led.o 
	$(AR) rc libMyPeri.a buzzer.o accelMagGyro.o colorled.o temperature.o button.o textlcd.o fnd.o led.o

buzzer.o: buzzer.h accelMagGyro.h colorled.h temperature.h button.h textlcd.h fnd.h led.h buzzer.c accelMagGyro.c colorled.c temperature.c button.c textlcd.c fnd.c led.c
	$(CC) -o buzzer.o -c buzzer.c
	$(CC) -o accelMagGyro.o -c accelMagGyro.c
	$(CC) -o colorled.o -c colorled.c
	$(CC) -o temperature.o -c temperature.c
	$(CC) -o button.o -c button.c
	$(CC) -o textlcd.o -c textlcd.c
	$(CC) -o fnd.o -c fnd.c
	$(CC) -o led.o -c led.c


clean:
	rm -f kartrider buzzer.o accelMagGyro.o colorled.o temperature.o button.o textlcd.o fnd.o led.o libMyPeri.a


