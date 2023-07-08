//PRIORITY SCHEDULING 
#include <stdio.h> 
void Priority(int processes[], int n, int burst_time[], int priority[]) { 
  int waiting_time[n], turnaround_time[n], completion_time[n], total_completion_time = 0; 
  // Sort the processes based on priority in ascending order using selection sort 
  for (int i = 0; i < n - 1; i++) { 
    int min_index = i; 
    for (int j = i + 1; j < n; j++) { 
      if (priority[j] < priority[min_index]) { 
        min_index = j; 
      } 
    } 
    // Swap the processes, burst time, and priority 
    int temp = burst_time[i]; 
    burst_time[i] = burst_time[min_index]; 
    burst_time[min_index] = temp; 
    temp = processes[i]; 
    processes[i] = processes[min_index]; 
    processes[min_index] = temp; 
    temp = priority[i]; 
    priority[i] = priority[min_index]; 
    priority[min_index] = temp; 
  }
  // Calculate waiting time and completion time for all processes 
  for (int i = 0; i < n; i++) { 
    if (i == 0) { 
      waiting_time[i] = 0;
      completion_time[i] = burst_time[i]; 
    } else { 
      waiting_time[i] = completion_time[i - 1]; 
      completion_time[i] = completion_time[i - 1] + burst_time[i]; 
    } 
    total_completion_time += completion_time[i]; 
  } 
  // Calculate turnaround time for all processes 
  for (int i = 0; i < n; i++) { 
    turnaround_time[i] = completion_time[i]; 
  } 
  // Calculate average waiting time and turnaround time 
  float average_waiting_time = 0, average_turnaround_time = 0; 
  for (int i = 0; i < n; i++) { 
    average_waiting_time += waiting_time[i]; 
    average_turnaround_time += turnaround_time[i]; 
  } 
  average_waiting_time /= n; 
  average_turnaround_time /= n; 
  // Print the results 
  printf("Process\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n"); 
  for (int i = 0; i < n; i++) { 
    printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i], priority[i], waiting_time[i], turnaround_time[i]); 
  } 
  printf("Average Waiting Time: %.2f\n", average_waiting_time); 
  printf("Average Turnaround Time: %.2f\n", average_turnaround_time); 
} 

int main() { 
  int n; 
  printf("Enter the number of processes: "); 
  scanf("%d", &n); int processes[n], burst_time[n], priority[n]; 
  printf("Enter burst time and priority for each process:\n"); 
  for (int i = 0; i < n; i++) { 
    printf("Process %d:\n", i + 1); 
    printf("Burst Time: "); 
    scanf("%d", &burst_time[i]); 
    printf("Priority: "); 
    scanf("%d", &priority[i]); 
    processes[i] = i + 1; 
  }
  Priority(processes, n, burst_time, priority); 
  return 0; 
}
