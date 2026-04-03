#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

#define FIFO_NAME "MY_FIFO"

int main()
{
    /*create FIFO channel*/
    if (mkfifo(FIFO_NAME, 0666) == -1)
    {
        printf("ERROR: mkfifo\n");
        return 1;
    }

    /*get FIFO file fd*/
    int fd = open(FIFO_NAME, O_RDONLY);

    char buffer[20];

    int n_bytes = 0;

    /*wait message from other process*/
    while (!n_bytes)
    {
        n_bytes = read(fd, buffer, 20);
    }

    buffer[n_bytes] = '\0';

    /*output info*/
    printf("Programm FIFO_channel_2.c recieve: %s\n", buffer);

    return 0;
}