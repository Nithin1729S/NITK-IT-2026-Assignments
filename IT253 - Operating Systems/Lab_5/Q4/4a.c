#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    pid_t pid;
    pid=fork();

    if(pid<0) printf("Error in creating child process");
    else if(pid==0) printf("Child Process PID = %d\n",getpid());
    else printf("Parent Process PID = %d\n",getpid());
    return 0;
}



