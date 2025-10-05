// Program illustrating some of the problems with concurrency
#include <stdio.h>
#include <stdlib.h>
#include "common_threads.h"

volatile int counter = 0;
int loops;

/*
Function that is the work horse of the thread. It will increment the counter up to the loop times
*/
void *worker(void *arg)
{
    for (int i = 0; i < loops; i++)
        counter++;
    return NULL;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./threads <loops>\n");
        return 1;
    }

    loops = atoi(argv[1]);
    pthread_t p1;
    pthread_t p2;
    printf("Initial value of counter %d\n", counter);
    Pthread_create(&p1, NULL, worker, NULL);
    Pthread_create(&p2, NULL, worker, NULL);
    Pthread_join(p1, NULL);
    Pthread_join(p2, NULL);
    printf("Final value of counter %d\n", counter);
    return 0;
}
