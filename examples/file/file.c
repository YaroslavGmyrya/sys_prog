#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
    /*open file and get fd*/
    int fd = open("test.txt", O_WRONLY | O_CREAT, 0644);

    /*check error*/
    if (fd == -1)
    {
        printf("Invalid file descriptor!\n");
        return 1;
    }

    struct stat stats;

    /*with fstat get copy of inode struct*/
    if (fstat(fd, &stats) == -1)
    {
        printf("Error in fstat");
        return 1;
    }

    /*output info about file*/
    printf("inode: %lu\n", stats.st_ino);       // inode id
    printf("size: %lld\n", stats.st_size);      // file size
    printf("blocks: %lld\n", stats.st_blocks);  // how many 512-byte blocks in files
    printf("blksize: %ld\n", stats.st_blksize); // recomendated block_size for writing
    printf("uid: %u\n", stats.st_uid);          // user id (owner)
    printf("gid: %u\n", stats.st_gid);          // group id
    printf("mode: %o\n", stats.st_mode);        // work mode (file type + access rights)
    printf("nlink: %lu\n", stats.st_nlink);     // number of links leading to the inode

    printf("atime: %ld.%09ld\n", // time of last usage
           stats.st_atim.tv_sec,
           stats.st_atim.tv_nsec);

    printf("mtime: %ld.%09ld\n", // time of last edit file
           stats.st_mtim.tv_sec,
           stats.st_mtim.tv_nsec);

    printf("ctime: %ld.%09ld\n", // time of last edit inode
           stats.st_ctim.tv_sec,
           stats.st_ctim.tv_nsec);

    close(fd);

    return 0;
}
