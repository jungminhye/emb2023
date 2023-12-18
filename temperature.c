#include "temperature.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>

int spi_init(char filename[40]) {
    int file;
    __u8 mode, lsb, bits;
    __u32 speed = 20000;

    if ((file = open(filename, O_RDWR)) < 0) {
        printf("Failed to open the bus.");
        printf("Error Type: %d\r\n", errno);
        exit(1);
    }

    if (ioctl(file, SPI_IOC_RD_MODE, &mode) < 0) {
        perror("SPI rd_mode");
        return 0;
    }
    if (ioctl(file, SPI_IOC_RD_LSB_FIRST, &lsb) < 0) {
        perror("SPI rd_lsb_fist");
        return 0;
    }
    if (ioctl(file, SPI_IOC_RD_BITS_PER_WORD, &bits) < 0) {
        perror("SPI bits_per_word");
        return 0;
    }

    printf("%s: spi mode %d, %d bits %sper word, %d Hz max\n", filename, mode, bits, lsb ? "(lsb first) " : "", speed);

    return file;
}

char *spi_read_lm74(int file) {
    int len;
    static char gbuf[10]; // Changed to static to maintain state between function calls
    memset(gbuf, 0, sizeof(gbuf));
    len = read(file, gbuf, 2);

    if (len != 2) {
        perror("read error");
        return NULL;
    }

    return gbuf;
}

double convert_lm74_temperature(char *buffer) {
    int value = 0;
    value = (buffer[1] >> 3);
    value = (value & 0x1F) | ((buffer[0]) << 5);
    double temp = (double)value * 0.0625;

    return temp;
}

