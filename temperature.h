#ifndef TEMPERATURE_H
#define TEMPERATURE_H

int spi_init(char filename[40]);
char *spi_read_lm74(int file);
double convert_lm74_temperature(char *buffer);

#endif /* TEMPERATURE_H */

