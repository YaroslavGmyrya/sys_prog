#include <stdio.h>
#include <fcntl.h>

int main()
{
    int fd = open("../../../../dev/tty", O_RDONLY | O_CREAT, 0644);
    char symb[1];
    while (1)
    {
        int r_bytes = read(fd, symb, 1);

        if (r_bytes != 0)
        {
            printf("%c\n", symb);
        }
    }
    return 0;
}