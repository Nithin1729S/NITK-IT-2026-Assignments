#include <stdio.h>

struct Process
{
    int pid;
    int AT;
    int BT;
    int CT;
    int TAT;
    int WT;
};

void sortOnAT(struct Process *processes, int size)
{
    int i, j;
    struct Process tmp;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (processes[j].AT > processes[j + 1].AT)
            {
                
                tmp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = tmp;
            }
        }
    }
}

void sortOnPID(struct Process *processes, int size)
{
    int i, j;
    struct Process tmp;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (processes[j].pid > processes[j + 1].pid)
            {
                
                tmp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = tmp;
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of processes:");
    scanf("%d", &n);

    struct Process processes[n];

    printf("Enter the details of processes:\n");

    for (int i = 0; i < n; i++)
    {
        printf("Process %d:\n", i + 1);
        printf("Enter the PID: ");
        scanf("%d", &processes[i].pid);
        printf("Enter the Arrival Time: ");
        scanf("%d", &processes[i].AT);
        printf("Enter the Burst Time: ");
        scanf("%d", &processes[i].BT);
        printf("\n");
    }

    sortOnAT(processes, n);

    int ct_previous = 0;
    ct_previous += processes[0].AT;
    int avg_TAT = 0;
    int avg_WT = 0;

    for (int i = 0; i < n; i++)
    {
        ct_previous += processes[i].BT;
        processes[i].CT = ct_previous;
        processes[i].TAT = processes[i].CT - processes[i].AT;
        processes[i].WT = processes[i].TAT - processes[i].BT;
        if (ct_previous < processes[i + 1].AT)
        {
            int t = processes[i + 1].AT - ct_previous;
            ct_previous += t;
        }
        avg_TAT += processes[i].TAT;
        avg_WT += processes[i].WT;
    }
    
    
    sortOnPID(processes, n);
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", processes[i].pid, processes[i].AT, processes[i].BT,
               processes[i].CT, processes[i].TAT, processes[i].WT);
    }

    printf("\nAverage Turn Around Time: %.2f units", (float)avg_TAT / n);
    printf("\nAverage Waiting Time: %.2f units\n", (float)avg_WT / n);

    return 0;
}
