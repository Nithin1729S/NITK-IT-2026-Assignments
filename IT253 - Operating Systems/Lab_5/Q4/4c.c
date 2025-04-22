#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
    pid_t p;
    p = fork();
    if (p == 0)
    {
        sleep(10); // child goes to sleep and in the mean time parent terminates
        printf("I am child having PID %d\n", getpid());
        printf("My parent PID is %d\n", getppid());
    }
    else
    {
        printf("I am parent having PID %d\n", getpid());
        printf("My child PID is %d\n", p);
    }
}




//In this code, we add sleep(5) in the child section. This line of code makes the child process go to sleep for 5 seconds and the parent starts executing. Since, parent process has just two lines to print, which it does well within 5 seconds and it terminates. After 5 seconds when the child process wakes up, its parent has already terminated and hence the child becomes an orphan process. Hence, it prints the PID of its parent as 1 (1 means the init process has been made its parent now) and not 138.
