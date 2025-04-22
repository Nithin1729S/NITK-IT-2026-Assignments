#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    printf("This is pid.c\n");
    printf("PID of pid.c = %d\n", getpid());
    return 0;
}
