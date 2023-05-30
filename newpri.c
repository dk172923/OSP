#include <stdio.h>
#define MAX_PROCESSES 10

typedef struct 
{
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
} Process;

int main() 
{
    Process processes[MAX_PROCESSES];
    int num_processes, i;

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    for (i = 0; i < num_processes; i++) 
    {
        printf("\nEnter burst time and priority for process %d: ", i+1);
        scanf("%d%d", &processes[i].burst_time, &processes[i].priority);
        processes[i].waiting_time = 0;
    }

    int total_waiting_time = 0, total_turnaround_time = 0;

    for (i = 0; i < num_processes; i++) 
    {
        if (i > 0)
            processes[i].waiting_time = processes[i-1].turnaround_time;

        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < num_processes; i++) 
    {
        printf("%d\t%d ms\t\t%d\t\t%d ms\t\t%d ms\n", i+1, processes[i].burst_time, processes[i].priority, processes[i].waiting_time, processes[i].turnaround_time);
    }

    printf("\nAverage waiting time: %.2f ms", (float)total_waiting_time / num_processes);
    printf("\nAverage turnaround time: %.2f ms\n", (float)total_turnaround_time / num_processes);

    return 0;
}

