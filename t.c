#include <stdio.h>
#include "textlcdtest.h"
#include <stdlib.h> 

int main(int argc, char **argv)
{
        if (argc < 3 )
        {
                perror(" Args number is less than 2\n");
                doHelp();
                return 1;
	}

        lcdtextwrite(argv[0], argv[1], atoi(argv[2]));
        return 0;

}

