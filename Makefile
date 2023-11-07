final.elf:1.o 2.o 3.o
	gcc -g -o final.elf 1.o 2.o 3.o

1.o:1.c
	gcc -g -o 1.o 1.c

2.o:2.c
	gcc -g -o 2.o 2.c

3.o:3.c
	gcc -g -o 3.o 3.c
