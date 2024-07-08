#include <stdio.h>
#include <stdbool.h>

// Structure to represent a process
struct Process {
    int pid;            // Process ID
    int arrival_time;   // Arrival time
    int burst_time;     // Burst time
    int completion_time; // Completion time
    int waiting_time;   // Waiting time
    int turnaround_time; // Turnaround time
};

// Function to sort processes based on arrival time
void sortProcessesByArrival(struct Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[j].arrival_time < processes[i].arrival_time) {
                // Swap processes[i] and processes[j]
                struct Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

// Function to find the next process to execute
int findNextProcess(struct Process processes[], int n, int current_time, bool completed[]) {
    int min_burst_time = 100000; // Large value for comparison
    int next_process = -1;
    for (int i = 0; i < n; i++) {
        if (processes[i].arrival_time <= current_time && !completed[i] && processes[i].burst_time < min_burst_time) {
            min_burst_time = processes[i].burst_time;
            next_process = i;
        }
    }
    return next_process;
}

// Function to calculate waiting time and turnaround time
void calculateTimes(struct Process processes[], int n) {
    bool completed[n];
    for (int i = 0; i < n; i++) completed[i] = false;

    int current_time = 0;
    int completed_processes = 0;

    while (completed_processes < n) {
        int next_process = findNextProcess(processes, n, current_time, completed);
        if (next_process == -1) {
            current_time++;
            continue;
        }
        
        current_time += processes[next_process].burst_time;
        processes[next_process].completion_time = current_time;
        processes[next_process].turnaround_time = processes[next_process].completion_time - processes[next_process].arrival_time;
        processes[next_process].waiting_time = processes[next_process].turnaround_time - processes[next_process].burst_time;
        
        completed[next_process] = true;
        completed_processes++;
    }
}

// Function to calculate average waiting time and turnaround time
void calculateAvgTimes(struct Process processes[], int n) {
    calculateTimes(processes, n);

    float avg_wt = 0, avg_tat = 0;
    printf("PID \tAT \tBT \tCT \tWT \tTAT\n");
    for (int i = 0; i < n; i++) {
        avg_wt += processes[i].waiting_time;
        avg_tat += processes[i].turnaround_time;
        printf("%d\t %d\t %d\t %d\t %d\t %d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    printf("Average waiting time = %.2f\n", avg_wt / n);
    printf("Average turnaround time = %.2f\n", avg_tat / n);
}

int main() {
    int n;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n]; // Array to store process information

    // Input the process details
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
    }

    // Sort processes based on arrival time
    sortProcessesByArrival(processes, n);
    
    // Calculate average waiting time and turnaround time
    calculateAvgTimes(processes, n);

    return 0;
}