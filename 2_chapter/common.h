#ifndef __common_h__
#define __common_h__

#include <sys/time.h>
#include <sys/stat.h>
#include <assert.h>

// Gets the current time of days as the sum of the number of seconds and microseconds since Jan 1 1970 (collapses the struct essentially)
double get_time(void) 
{
    struct timeval t;
    int rc = gettimeofday(&t, NULL);
    assert(rc == 0);
    return (double) t.tv_sec + (double) t.tv_usec / 1e6;
}

void Spin(int howlong)
{
    double t = get_time();
    while (get_time() - t < (double) howlong)
    ; // do nothing in loop
}


#endif
