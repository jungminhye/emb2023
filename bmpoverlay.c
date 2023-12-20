#include <stdio.h>
#include <stdlib.h>     // for exit
#include "bmpoverlay.h"
#include "libfbdev.h"
#include "libbmp.h"

//Newly added.

int bmpover1 ()
{
    int screen_width;
    int screen_height;
    int bits_per_pixel;
    int line_length;
    int cols = 0, rows = 0;
	char *data;
    char name[] = "011.bmp";

    printf("=================================\n");
    printf("Frame buffer Application - Bitmap\n");
    printf("=================================\n\n");


	//FrameBuffer init
    if ( fb_init(&screen_width, &screen_height, &bits_per_pixel, &line_length) < 0 )
	{
		printf ("FrameBuffer Init Failed\r\n");
		return 0;
	}

	//Clear FB.
	fb_clear();

	//overlay framebuffer init
	fb_init2();
	fb_clear2(0,0,1024,600);

	//FileRead
    if (read_bmp(name, &data, &cols, &rows) < 0)
	{
		printf ("File open failed\r\n");
		return 0;
	}
//    close_bmp();
    printf("\tBitmapFile: %dx%d pixels\n", cols, rows);
    printf("\tFB Screen: %dx%d\n", screen_width, screen_height);
    printf("\tFB bits_per_pixel: %d, FB line_length: %d\n", bits_per_pixel, line_length);
	
	//FileWrite
	fb_write(data, cols,rows);
	printf ("DO this seg.Fault?\r\n");
 	close_bmp();

	printf ("Try to read New BMP\r\n");

	char *newData;
	int newCols;
	int newRows;


	read_bmp("char1.bmp", &newData, &newCols, &newRows);
	printf ("%d %d bmp read\r\n",newCols, newRows);

	while(1)
    {
        int xpos = 0;
        for (xpos = 0; xpos < 1024; xpos++)
        {
            fb_write2(newData, newCols, newRows, xpos, 110);
            usleep(20000);
            fb_clear2(xpos, 110, 1, newRows); // 딱 한라인만 지우쟈...
            //fb_clear2(xpos+newCols-1, 200, 1, newRows);
        }
    }
	close_bmp();

	
	fb_close();
	fb_close2();
    return 0;
}

int bmpover2 ()
{
    int screen_width;
    int screen_height;
    int bits_per_pixel;
    int line_length;
    int cols = 0, rows = 0;
	char *data;
    char name[] = "011.bmp";

    printf("=================================\n");
    printf("Frame buffer Application - Bitmap\n");
    printf("=================================\n\n");


	//FrameBuffer init
    if ( fb_init(&screen_width, &screen_height, &bits_per_pixel, &line_length) < 0 )
	{
		printf ("FrameBuffer Init Failed\r\n");
		return 0;
	}

	//Clear FB.
	fb_clear();

	//overlay framebuffer init
	fb_init2();
	fb_clear2(0,0,1024,600);

	//FileRead
    if (read_bmp(name, &data, &cols, &rows) < 0)
	{
		printf ("File open failed\r\n");
		return 0;
	}
//    close_bmp();
    printf("\tBitmapFile: %dx%d pixels\n", cols, rows);
    printf("\tFB Screen: %dx%d\n", screen_width, screen_height);
    printf("\tFB bits_per_pixel: %d, FB line_length: %d\n", bits_per_pixel, line_length);
	
	//FileWrite
	fb_write(data, cols,rows);
	printf ("DO this seg.Fault?\r\n");
 	close_bmp();

	printf ("Try to read New BMP\r\n");

	char *newData;
	int newCols;
	int newRows;


	read_bmp("char2.bmp", &newData, &newCols, &newRows);
	printf ("%d %d bmp read\r\n",newCols, newRows);

	while(1)
    {
        int xpos = 0;
        for (xpos = 0; xpos < 1024; xpos++)
        {
            fb_write2(newData, newCols, newRows, xpos, 110);
            usleep(20000);
            fb_clear2(xpos, 110, 1, newRows); // 딱 한라인만 지우쟈...
            //fb_clear2(xpos+newCols-1, 200, 1, newRows);
        }
    }
	close_bmp();

	
	fb_close();
	fb_close2();
    return 0;
}
