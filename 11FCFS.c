#include <stdio.h>

struct process {
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
} p[10];

int main() {
    int n, i;
    float awt = 0.0, atat = 0.0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &p[i].at);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &p[i].bt);
    }

    // Sort processes by arrival time (FCFS)
    struct process temp;
    for (i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (p[j].at > p[j + 1].at) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    int current = 0;
    for (i = 0; i < n; i++) {
        if (current < p[i].at) {
            current = p[i].at;  // If CPU is idle, wait until process arrives
        }
        current += p[i].bt;
        p[i].ct = current;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;

        // Accumulate total waiting and turnaround times
        awt += p[i].wt;
        atat += p[i].tat;
    }

    printf("PID  AT  BT  CT  TAT  WT\n");
    for (i = 0; i < n; i++) {
        printf("%2d%5d%5d%5d%5d%5d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("Average Waiting Time = %.2f\n", awt / n);
    printf("Average Turnaround Time = %.2f\n", atat / n);

    return 0;
}
