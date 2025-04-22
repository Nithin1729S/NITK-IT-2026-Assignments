#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    printf("prog2 has replaced prog1\n");
    printf("PID of prog2= %d\n", getpid());
    return 0;
}