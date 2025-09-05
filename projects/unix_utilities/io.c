// Includes the definitions of the functions that will be used by wcat
#include "io.h"
#include <stdio.h>
#include <stdlib.h>

void print_error_message_and_return(void)
{
    printf("wcat: cannot open file\n");
    exit(1);
}



int print_file(const char *file)
{
    FILE *f = fopen(file, "r");
    if (f == NULL)
        return 0;

    // Read each character one by one until the end of the file
    char c;
    while ((c = fgetc(f)) != EOF)
        putchar(c);
    fclose(f);
    return 1;
}
