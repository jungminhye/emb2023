#include <stdio.h>
#include <stdlib.h>     // for exit
#include "../libfbdev/libfbdev.h"
#include "../libbmp/libbmp.h"

int bmp1()
{
    int screen_width;
    int screen_height;
    int bits_per_pixel;
    int line_length;
    int cols = 0, rows = 0;
    char *data;
    char name[] = "001.bmp"; 

    printf("=================================\n");
    printf("Frame buffer Application - Bitmap\n");
    printf("=================================\n\n");
    printf("File Name!!!: ");
  
  
	//FrameBuffer init
    if ( fb_init(&screen_width, &screen_height, &bits_per_pixel, &line_length) < 0 )
	{
		printf ("FrameBuffer Init Failed\r\n");
		return 0;
	}

	//Clear FB.
	fb_clear();

	//FileRead
    if (read_bmp(name, &data, &cols, &rows) < 0)
	{
		printf ("File open failed\r\n");
		return 0;
	}
    printf("\tBitmapFile: %dx%d pixels\n", cols, rows);
    printf("\tFB Screen: %dx%d\n", screen_width, screen_height);
    printf("\tFB bits_per_pixel: %d, FB line_length: %d\n", bits_per_pixel, line_length);
	
	//FileWrite
	fb_write(data, cols,rows);
    
	close_bmp();
	fb_close();

return 0;
}

int bmp2()
{
    int screen_width;
    int screen_height;
    int bits_per_pixel;
    int line_length;
    int cols = 0, rows = 0;
    char *data;
    char name[] = "002.bmp";

    printf("=================================\n");
    printf("Frame buffer Application - Bitmap\n");
    printf("=================================\n\n");
    printf("File Name!!!: ");


        //FrameBuffer init
    if ( fb_init(&screen_width, &screen_height, &bits_per_pixel, &line_length) < 0 )
        {
                printf ("FrameBuffer Init Failed\r\n");
                return 0;
        }

        //Clear FB.
        fb_clear();

        //FileRead
    if (read_bmp(name, &data, &cols, &rows) < 0)
        {
                printf ("File open failed\r\n");
                return 0;
        }
    printf("\tBitmapFile: %dx%d pixels\n", cols, rows);
    printf("\tFB Screen: %dx%d\n", screen_width, screen_height);
    printf("\tFB bits_per_pixel: %d, FB line_length: %d\n", bits_per_pixel, line_length);

        //FileWrite
        fb_write(data, cols,rows);

        close_bmp();
        fb_close();

return 0;
}

int bmp3()
{
    int screen_width;
    int screen_height;
    int bits_per_pixel;
    int line_length;
    int cols = 0, rows = 0;
    char *data;
    char name[] = "003.bmp";

    printf("=================================\n");
    printf("Frame buffer Application - Bitmap\n");
    printf("=================================\n\n");
    printf("File Name!!!: ");


        //FrameBuffer init
    if ( fb_init(&screen_width, &screen_height, &bits_per_pixel, &line_length) < 0 )
        {
                printf ("FrameBuffer Init Failed\r\n");
                return 0;
        }

        //Clear FB.
        fb_clear();

        //FileRead
    if (read_bmp(name, &data, &cols, &rows) < 0)
        {
                printf ("File open failed\r\n");
                return 0;
        }
    printf("\tBitmapFile: %dx%d pixels\n", cols, rows);
    printf("\tFB Screen: %dx%d\n", screen_width, screen_height);
    printf("\tFB bits_per_pixel: %d, FB line_length: %d\n", bits_per_pixel, line_length);

        //FileWrite
        fb_write(data, cols,rows);

        close_bmp();
        fb_close();

return 0;
}

int bmp4()
{
    int screen_width;
    int screen_height;
    int bits_per_pixel;
    int line_length;
    int cols = 0, rows = 0;
    char *data;
    char name[] = "004.bmp";

    printf("=================================\n");
    printf("Frame buffer Application - Bitmap\n");
    printf("=================================\n\n");
    printf("File Name!!!: ");


        //FrameBuffer init
    if ( fb_init(&screen_width, &screen_height, &bits_per_pixel, &line_length) < 0 )
        {
                printf ("FrameBuffer Init Failed\r\n");
                return 0;
        }

        //Clear FB.
        fb_clear();

        //FileRead
    if (read_bmp(name, &data, &cols, &rows) < 0)
        {
                printf ("File open failed\r\n");
                return 0;
        }
    printf("\tBitmapFile: %dx%d pixels\n", cols, rows);
    printf("\tFB Screen: %dx%d\n", screen_width, screen_height);
    printf("\tFB bits_per_pixel: %d, FB line_length: %d\n", bits_per_pixel, line_length);

        //FileWrite
        fb_write(data, cols,rows);

        close_bmp();
        fb_close();

return 0;
}
int bmp5()
{
    int screen_width;
    int screen_height;
    int bits_per_pixel;
    int line_length;
    int cols = 0, rows = 0;
    char *data;
    char name[] = "005.bmp";

    printf("=================================\n");
    printf("Frame buffer Application - Bitmap\n");
    printf("=================================\n\n");
    printf("File Name!!!: ");


        //FrameBuffer init
    if ( fb_init(&screen_width, &screen_height, &bits_per_pixel, &line_length) < 0 )
        {
                printf ("FrameBuffer Init Failed\r\n");
                return 0;
        }

        //Clear FB.
        fb_clear();

        //FileRead
    if (read_bmp(name, &data, &cols, &rows) < 0)
        {
                printf ("File open failed\r\n");
                return 0;
        }
    printf("\tBitmapFile: %dx%d pixels\n", cols, rows);
    printf("\tFB Screen: %dx%d\n", screen_width, screen_height);
    printf("\tFB bits_per_pixel: %d, FB line_length: %d\n", bits_per_pixel, line_length);

        //FileWrite
        fb_write(data, cols,rows);

        close_bmp();
        fb_close();

return 0;
}

int bmp6()
{
    int screen_width;
    int screen_height;
    int bits_per_pixel;
    int line_length;
    int cols = 0, rows = 0;
    char *data;
    char name[] = "006.bmp";

    printf("=================================\n");
    printf("Frame buffer Application - Bitmap\n");
    printf("=================================\n\n");
    printf("File Name!!!: ");


        //FrameBuffer init
    if ( fb_init(&screen_width, &screen_height, &bits_per_pixel, &line_length) < 0 )
        {
                printf ("FrameBuffer Init Failed\r\n");
                return 0;
        }

        //Clear FB.
        fb_clear();

        //FileRead
    if (read_bmp(name, &data, &cols, &rows) < 0)
        {
                printf ("File open failed\r\n");
                return 0;
        }
    printf("\tBitmapFile: %dx%d pixels\n", cols, rows);
    printf("\tFB Screen: %dx%d\n", screen_width, screen_height);
    printf("\tFB bits_per_pixel: %d, FB line_length: %d\n", bits_per_pixel, line_length);

        //FileWrite
        fb_write(data, cols,rows);

        close_bmp();
        fb_close();

return 0;
}

int bmp7()
{
    int screen_width;
    int screen_height;
    int bits_per_pixel;
    int line_length;
    int cols = 0, rows = 0;
    char *data;
    char name[] = "007.bmp";

    printf("=================================\n");
    printf("Frame buffer Application - Bitmap\n");
    printf("=================================\n\n");
    printf("File Name!!!: ");


        //FrameBuffer init
    if ( fb_init(&screen_width, &screen_height, &bits_per_pixel, &line_length) < 0 )
        {
                printf ("FrameBuffer Init Failed\r\n");
                return 0;
        }

        //Clear FB.
        fb_clear();

        //FileRead
    if (read_bmp(name, &data, &cols, &rows) < 0)
        {
                printf ("File open failed\r\n");
                return 0;
        }
    printf("\tBitmapFile: %dx%d pixels\n", cols, rows);
    printf("\tFB Screen: %dx%d\n", screen_width, screen_height);
    printf("\tFB bits_per_pixel: %d, FB line_length: %d\n", bits_per_pixel, line_length);

        //FileWrite
        fb_write(data, cols,rows);

        close_bmp();
        fb_close();

return 0;
}
int bmp8()
{
    int screen_width;
    int screen_height;
    int bits_per_pixel;
    int line_length;
    int cols = 0, rows = 0;
    char *data;
    char name[] = "008.bmp";

    printf("=================================\n");
    printf("Frame buffer Application - Bitmap\n");
    printf("=================================\n\n");
    printf("File Name!!!: ");


        //FrameBuffer init
    if ( fb_init(&screen_width, &screen_height, &bits_per_pixel, &line_length) < 0 )
        {
                printf ("FrameBuffer Init Failed\r\n");
                return 0;
        }

        //Clear FB.
        fb_clear();

        //FileRead
    if (read_bmp(name, &data, &cols, &rows) < 0)
        {
                printf ("File open failed\r\n");
                return 0;
        }
    printf("\tBitmapFile: %dx%d pixels\n", cols, rows);
    printf("\tFB Screen: %dx%d\n", screen_width, screen_height);
    printf("\tFB bits_per_pixel: %d, FB line_length: %d\n", bits_per_pixel, line_length);

        //FileWrite
        fb_write(data, cols,rows);

        close_bmp();
        fb_close();

return 0;
}
int bmp9()
{
    int screen_width;
    int screen_height;
    int bits_per_pixel;
    int line_length;
    int cols = 0, rows = 0;
    char *data;
    char name[] = "009.bmp";

    printf("=================================\n");
    printf("Frame buffer Application - Bitmap\n");
    printf("=================================\n\n");
    printf("File Name!!!: ");


        //FrameBuffer init
    if ( fb_init(&screen_width, &screen_height, &bits_per_pixel, &line_length) < 0 )
        {
                printf ("FrameBuffer Init Failed\r\n");
                return 0;
        }

        //Clear FB.
        fb_clear();

        //FileRead
    if (read_bmp(name, &data, &cols, &rows) < 0)
        {
                printf ("File open failed\r\n");
                return 0;
        }
    printf("\tBitmapFile: %dx%d pixels\n", cols, rows);
    printf("\tFB Screen: %dx%d\n", screen_width, screen_height);
    printf("\tFB bits_per_pixel: %d, FB line_length: %d\n", bits_per_pixel, line_length);

        //FileWrite
        fb_write(data, cols,rows);

        close_bmp();
        fb_close();

return 0;
}
int bmp10()
{
    int screen_width;
    int screen_height;
    int bits_per_pixel;
    int line_length;
    int cols = 0, rows = 0;
    char *data;
    char name[] = "010.bmp";

    printf("=================================\n");
    printf("Frame buffer Application - Bitmap\n");
    printf("=================================\n\n");
    printf("File Name!!!: ");


        //FrameBuffer init
    if ( fb_init(&screen_width, &screen_height, &bits_per_pixel, &line_length) < 0 )
        {
                printf ("FrameBuffer Init Failed\r\n");
                return 0;
        }

        //Clear FB.
        fb_clear();

        //FileRead
    if (read_bmp(name, &data, &cols, &rows) < 0)
        {
                printf ("File open failed\r\n");
                return 0;
        }
    printf("\tBitmapFile: %dx%d pixels\n", cols, rows);
    printf("\tFB Screen: %dx%d\n", screen_width, screen_height);
    printf("\tFB bits_per_pixel: %d, FB line_length: %d\n", bits_per_pixel, line_length);

        //FileWrite
        fb_write(data, cols,rows);

        close_bmp();
        fb_close();

return 0;
}

