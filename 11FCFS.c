// Online C compiler to run C program online
#include <stdio.h>

 struct process{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
}p[10];
int main() {
    // Write C code here
   int n,i;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &p[i].at);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &p[i].bt);
    }
    struct process temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (p[j].btime > p[j + 1].btime)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    int current=0;
    for(i=0;i<n;i++)
    {
        current=current+p[i].bt;
        p[i].ct=current;
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
    }
    float awt=0.0;
    float atat=0.0;
    printf("PID AT  BT  CT  TAT  WT\n");
    for(i=0;i<n;i++)
    {
        printf("%d%5d%5d%5d%5d%5d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    }
    printf("Average Waiting Time = %f\n", awt / n);
    printf("Average Turnaround Time = %f\n", atat / n);

}