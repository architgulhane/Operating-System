#include <stdio.h>

struct Process {
    int pid, arrivalTime, burstTime, waitingTime, turnaroundTime, completionTime;
};

void sortByArrivalTime(struct Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrivalTime > processes[j + 1].arrivalTime) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    struct Process processes[n];
    
    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for Process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrivalTime, &processes[i].burstTime);
        processes[i].pid = i + 1;
    }
    
    sortByArrivalTime(processes, n);
    
    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (currentTime < processes[i].arrivalTime) {
            currentTime = processes[i].arrivalTime;
        }
        processes[i].completionTime = currentTime + processes[i].burstTime;
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
        currentTime = processes[i].completionTime;
    }
    
    printf("\nProcess Table:\n");
    printf("%-10s %-15s %-15s %-15s %-15s %-15s\n", "PID", "Arrival Time", "Burst Time", "Completion Time", "Turnaround Time", "Waiting Time");
    for (int i = 0; i < n; i++) {
        printf("%-10d %-15d %-15d %-15d %-15d %-15d\n", 
               processes[i].pid, processes[i].arrivalTime, processes[i].burstTime, 
               processes[i].completionTime, processes[i].turnaroundTime, processes[i].waitingTime);
    }
    
    return 0;
}
