//FIRST COME FIRST SERVED 
#include <stdio.h> 
void FCFS(int processes[], int n, int burst_time[]) { 
    int waiting_time[n], turnaround_time[n]; 
    // Calculate waiting time for the first process 
    waiting_time[0] = 0; 
    // Calculate waiting time for the rest of the processes 
    for (int i = 1; i < n; i++) { 
        waiting_time[i] = waiting_time[i - 1] + burst_time[i - 1]; 
    }
    // Calculate turnaround time for all processes 
     for (int i = 0; i < n; i++) { 
        turnaround_time[i] = waiting_time[i] + burst_time[i]; 
    } 
    // Calculate average waiting time and turnaround time 
    float total_waiting_time = 0, total_turnaround_time = 0; 
    for (int i = 0; i < n; i++) { 
        total_waiting_time += waiting_time[i]; 
        total_turnaround_time += turnaround_time[i]; 
    } 
    float average_waiting_time = total_waiting_time / n; 
    float average_turnaround_time = total_turnaround_time / n; 
    // Print the results 
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n"); 
    for (int i = 0; i < n; i++) { 
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i], waiting_time[i], turnaround_time[i]); 
    }
    printf("Average Waiting Time: %.2f\n", average_waiting_time); 
    printf("Average Turnaround Time: %.2f\n", average_turnaround_time); 
} 

int main() { 
    int n; 
    printf("Enter the number of processes: "); 
    scanf("%d", &n); 
    int processes[n], burst_time[n]; 
    printf("Enter burst time for each process:\n"); 
    for (int i = 0; i < n; i++) { 
        printf("Process %d: ", i + 1); 
        scanf("%d", &burst_time[i]); processes[i] = i + 1; 
    } 
    FCFS(processes, n, burst_time); 
    return 0; 
}
