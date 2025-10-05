#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>
#include "common.h" // for Spin

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "usage: ./cpu <string>\n");
        exit(1);
    }

    while (1)
    {
        Spin(1);  // Wait 1 second
        printf("%s\n", argv[1]);
    }

    return 0;
}
