#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

#define FIFO_NAME "MY_FIFO"

int main()
{
    /*get FIFO file fd*/
    int fd = open(FIFO_NAME, O_WRONLY);

    char message[] = "Hello World!";

    /*send message*/
    int w_bytes = write(fd, message, strlen(message));

    return 0;
}
