#include <unistd.h>
#include <stdio.h>

int main()
{
    symlink("/home/yaroslav/main/sys_prog/examples/a.out", "../../a_symlink");

    printf("Hello world!\n");

    return 0;
}