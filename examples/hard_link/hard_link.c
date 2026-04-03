#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    /*create hardlink on file.txt*/
    if (link("file.txt", "file_hardlink.txt") == -1)
    {
        perror("link");
        return 1;
    }

    struct stat st1, st2;

    /*get inode struct for file.txt and file_hardlink.txt*/
    stat("file.txt", &st1);
    stat("file_hardlink.txt", &st2);

    /*output stats. Can see, that inode id is same and n_link = 2*/
    printf("inode1 = %lu\n", st1.st_ino);
    printf("inode2 = %lu\n", st2.st_ino);
    printf("nlink  = %lu\n", st1.st_nlink);

    /*file.txt and file_hardlink.txt refer to general inode -> we can write info in file.txt and this info we can see in file_hardlink.txt*/
    /*inode exist in system, while all links on inode will not be deleted*/
    int fd1 = open("file.txt", O_WRONLY | O_CREAT, 0644);
    int fd2 = open("file_hardlink.txt", O_RDONLY | O_CREAT, 0644);

    char write_buff[10] = "TEXT";
    char read_buff[10];

    int w_bytes = write(fd1, write_buff, strlen(write_buff));
    int r_bytes = read(fd2, read_buff, strlen(write_buff));

    read_buff[r_bytes] = '\0';

    printf("WRITE TO file.txt: %s\n", write_buff);
    printf("READ FROM file_hardlink.txt: %s\n", read_buff);

    return 0;
}