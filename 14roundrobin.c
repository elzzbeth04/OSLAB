#include <stdio.h>
#include <stdlib.h>

// Structure to represent a process
struct Process {
    int id;
    int burst_time;
    int arrival_time;
    int wt; // Waiting time
    int tat; // Turnaround time
};

// Function to simulate Round Robin scheduling
void roundRobin(struct Process processes[], int n, int time_quantum) {
    int remaining_time[n];
    for (int i = 0; i < n; ++i)
        remaining_time[i] = processes[i].burst_time;

    int current_time = 0;
    int completed = 0;

    while (completed < n) {
        int flag = 0;
        for (int i = 0; i < n; ++i) {
            if (processes[i].arrival_time <= current_time && remaining_time[i] > 0) {
                flag = 1;
                if (remaining_time[i] <= time_quantum) {
                    current_time += remaining_time[i];
                    remaining_time[i] = 0;
                    processes[i].tat = current_time - processes[i].arrival_time;
                    processes[i].wt = processes[i].tat - processes[i].burst_time;
                    printf("Process P%d completed at time %d\n", processes[i].id, current_time);
                    printf("Process P%d WT=%d TAT=%d\n", processes[i].id, processes[i].wt, processes[i].tat);
                    completed++;
                } else {
                    current_time += time_quantum;
                    remaining_time[i] -= time_quantum;
                }
            }
        }
        if (!flag)
            current_time++;
    }

    float awt = 0, atat = 0;
    for (int i = 0; i < n; i++) {
        awt += processes[i].wt;
        atat += processes[i].tat;
    }
    printf("Average WT=%.2f Average TAT=%.2f\n", awt / n, atat / n);
}

// Function to sort processes based on arrival time using Bubble Sort
void sortProcessesByArrival(struct Process processes[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                // Swap the processes
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    // Input burst times and arrival times
    for (int i = 0; i < n; ++i) {
        processes[i].id = i + 1;
        printf("Enter the burst time for process P%d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        printf("Enter the arrival time for process P%d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        processes[i].wt = 0; // Initialize waiting time
        processes[i].tat = 0; // Initialize turnaround time
    }

    int time_quantum;
    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);

    // Sort the processes based on arrival time using Bubble Sort
    sortProcessesByArrival(processes, n);

    printf("Round Robin Scheduling:\n");
    roundRobin(processes, n, time_quantum);

    return 0;
}
