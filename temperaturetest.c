#include "temperature.h"

int main(int argc, char **argv) {
    char *buffer;
    int file;

    file = spi_init("/dev/spidev1.0");
    buffer = (char *)spi_read_lm74(file);
    close(file);

    double temperature = convert_lm74_temperature(buffer);

    printf("Current Temp: %lf \n", temperature);

    return 0;
}

