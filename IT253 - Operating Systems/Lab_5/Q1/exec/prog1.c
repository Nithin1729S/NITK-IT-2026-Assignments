#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    printf("PID of prog1= %d\n", getpid());
    char *args[] = {"arguments", "for", "prog2", NULL};
    execv("./prog2", args);
    printf("Control back to prog1");
    return 0;
}