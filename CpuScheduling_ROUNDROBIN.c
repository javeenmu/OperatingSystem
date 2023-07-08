//ROUND ROBIN 
#include <stdio.h> 

void RoundRobin(int processes[], int n, int burst_time[], int time_quantum) { 
  int remaining_time[n], waiting_time[n], turnaround_time[n]; 
  // Copy burst time to remaining time 
  for (int i = 0; i < n; i++) { 
    remaining_time[i] = burst_time[i]; 
  } 
  int current_time = 0; 
  // Current time 
  int completed = 0; 
  // Number of completed processes 
  while (completed != n) { 
    for (int i = 0; i < n; i++) { 
      if (remaining_time[i] > 0) { 
        if (remaining_time[i] > time_quantum) { 
          current_time += time_quantum; remaining_time[i] -= time_quantum; 
        } 
        else { 
          current_time += remaining_time[i]; 
          waiting_time[i] = current_time - burst_time[i]; 
          remaining_time[i] = 0; 
          completed++; 
        } 
      } 
    } 
  } 
  // Calculate turnaround time for all processes 
  for (int i = 0; i < n; i++) { 
    turnaround_time[i] = burst_time[i] + waiting_time[i]; 
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
  printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n"); 
  for (int i = 0; i < n; i++) { 
    printf("%d\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i], waiting_time[i], turnaround_time[i]); 
  } 
  printf("Average Waiting Time: %.2f\n", average_waiting_time); 
  printf("Average Turnaround Time: %.2f\n", average_turnaround_time); 
} 

int main() { 
  int n, time_quantum; 
  printf("Enter the number of processes: "); 
  scanf("%d", &n); int processes[n], burst_time[n]; 
  printf("Enter burst time for each process:\n"); 
  for (int i = 0; i < n; i++) { 
    printf("Process %d: ", i + 1); 
    scanf("%d", &burst_time[i]); processes[i] = i + 1; 
  } 
  printf("Enter time quantum: "); 
  scanf("%d", &time_quantum); 
  RoundRobin(processes, n, burst_time, time_quantum); 
  return 0; 
}
