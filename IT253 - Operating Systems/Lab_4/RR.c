#include <stdio.h>
#include <stdbool.h>

struct Process
{
    int pid;
    int AT;
    int BT;
    int BTF;
    int Priority;
    int CT;
    int TAT;
    int WT;
    bool visited;
};

int ready_queue[10000];

int main()
{
    int n;
    printf("Enter the number of processes:");
    scanf("%d", &n);

    struct Process processes[n];

    printf("Enter the details of processes:\n");
    int minAT=1e9;
    int initial_idx=-1;
    for (int i = 0; i < n; i++)
    {
        printf("Process %d:\n", i + 1);
        printf("Enter the PID: ");
        scanf("%d", &processes[i].pid);
        printf("Enter the Arrival Time: ");
        scanf("%d", &processes[i].AT);
        printf("Enter the Burst Time: ");
        scanf("%d", &processes[i].BT);
        processes[i].BTF = processes[i].BT;
        processes[i].visited = false;
        if(minAT>processes[i].AT)
        {
            minAT=processes[i].AT;
            initial_idx=i;
        }
        printf("\n");
    }
    int TQ;
    printf("Enter Time Quantum: ");
    scanf("%d",&TQ);
    int ans=0,curr_queue_idx=0,ready_queue_idx=0;
    ready_queue[ready_queue_idx++]=initial_idx;
    processes[initial_idx].visited=true;

    for(int j=0;j<n;)
    {
        int rem_time=processes[ready_queue[curr_queue_idx]].BT;
        int sub;
        if(rem_time>TQ)
        {
            ans+=TQ;
            processes[ready_queue[curr_queue_idx]].BT-=TQ;
            for(int i=0;i<n;i++)
            {
                if(processes[i].visited==false && processes[i].AT<=ans)
                {
                    ready_queue[ready_queue_idx++]=i;
                    processes[i].visited=true;
                }
            }
            ready_queue[ready_queue_idx++]=ready_queue[curr_queue_idx];   
        }
        else
        {
            ans+=rem_time;
            processes[ready_queue[curr_queue_idx]].BT-=0;
            for(int i=0;i<n;i++)
            {
                if(processes[i].visited==false && processes[i].AT<=ans)
                {
                    ready_queue[ready_queue_idx++]=i;
                    processes[i].visited=true;
                }
            }
            processes[ready_queue[curr_queue_idx]].CT=ans;
            j++;
        }
        curr_queue_idx++;


    }
    
    int avg_TAT = 0;
    int avg_WT = 0;
    for (int i = 0; i < n; i++)
    {
        processes[i].TAT = processes[i].CT - processes[i].AT;
        processes[i].WT = processes[i].TAT - processes[i].BTF;
        avg_TAT += processes[i].TAT;
        avg_WT += processes[i].WT;
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", processes[i].pid, processes[i].AT, processes[i].BTF,
               processes[i].CT, processes[i].TAT, processes[i].WT);
    }

    printf("\nAverage Turn Around Time: %.2f", (float)avg_TAT / n);
    printf("\nAverage Waiting Time: %.2f\n", (float)avg_WT / n);

    return 0;
}
