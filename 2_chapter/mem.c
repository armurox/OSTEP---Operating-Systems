#include <unistd.h> // for getpid
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "common.h"

int main(void)
{
    int *p = malloc(sizeof(int));
    assert(p != NULL);
    printf("(%d) address pointed to by p: %p\n", getpid(), (void *) p);
    *p = 0;
    while (1)
    {
        Spin(1);
        (*p)++;
        printf("(%d) p: %d\n", getpid(), *p);
    }
}
