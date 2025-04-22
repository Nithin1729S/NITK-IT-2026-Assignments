#include <stdio.h>
#include<stdbool.h>

struct Process
{
    int pid;
    int AT;
    int BT;
    int Priority;
    int CT;
    int TAT;
    int WT;
    bool visited;
};

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
        processes[i].visited=false;
        printf("\n");
    }

    int i,j;
    int minCT=0;
    for(j=0;j<n;)
    {
        int minBT,idx;
        minBT=idx=1e9;
        for(int i=0;i<n;i++)
        {
            if(processes[i].visited==false)
            {
                if(minCT>=processes[i].AT && minBT>processes[i].BT)
                {
                    minBT=processes[i].BT;
                    idx=i;
                }
                else if(minCT>=processes[i].AT && minBT==processes[i].BT)
                {
                    if(processes[idx].AT>processes[i].AT)
                    {
                        minBT=processes[i].BT;
                        idx=i;
                    }
                }
            }
        }

        if(idx==1e9)
        {
            minCT++;
        }
        else
        {
            minCT+=minBT;
            processes[idx].visited=true;
            processes[idx].CT=minCT;
            j++;
        }
    }
    int avg_TAT=0;
    int avg_WT=0;
    for(int i=0;i<n;i++)
    {
        processes[i].TAT=processes[i].CT-processes[i].AT;
        processes[i].WT=processes[i].TAT-processes[i].BT;
        avg_TAT+=processes[i].TAT;
        avg_WT+=processes[i].WT;
    }

    
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", processes[i].pid, processes[i].AT, processes[i].BT,
               processes[i].CT, processes[i].TAT, processes[i].WT);
    }

    printf("\nAverage Turn Around Time: %.2f", (float)avg_TAT / n);
    printf("\nAverage Waiting Time: %.2f\n", (float)avg_WT / n);

    return 0;
}
