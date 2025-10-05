// Program that illustrates a basic file write
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <assert.h>
#include <sys/types.h>
#include <string.h>

int main(void)
{
    int fd = open("/tmp/file", O_WRONLY | O_CREAT | O_TRUNC | S_IRWXU);
    assert(fd > -1);
    char buffer[20];
    sprintf(buffer, "hello world\n");
    int rc = write(fd, buffer, (int) strlen(buffer));
    assert(rc == (int) strlen(buffer));
    close(fd);
    return 0;
}
