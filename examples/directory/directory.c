#include <dirent.h>
#include <stdio.h>

int main()
{
    DIR *dir = opendir(".");
    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL)
    {
        printf("%s -> (inode %lu)\n", entry->d_name, entry->d_ino);
    }

    closedir(dir);
    return 0;
}
