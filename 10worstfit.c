#include <stdio.h>

int main() {
    int pno, bno, psize[10], bsize[10], allocation[10];

    // Initialize allocation array to -1
    for (int i = 0; i < 10; i++) {
        allocation[i] = -1;
    }

    // Input number of processes
    printf("Enter number of processes: ");
    scanf("%d", &pno);

    // Input size of each process
    for (int i = 0; i < pno; i++) {
        printf("Enter size of process %d: ", i + 1);
        scanf("%d", &psize[i]);
    }

    // Input number of blocks
    printf("Enter number of blocks: ");
    scanf("%d", &bno);

    // Input size of each block
    for (int i = 0; i < bno; i++) {
        printf("Enter size of block %d: ", i + 1);
        scanf("%d", &bsize[i]);
    }

    // Worst-fit allocation
    for (int i = 0; i < pno; i++) {
        int worstplace = -1;
        for (int j = 0; j < bno; j++) {
            if (bsize[j] >= psize[i]) {
                if (worstplace == -1 || bsize[worstplace] < bsize[j]) {
                    worstplace = j;
                }
            }
        }
        if (worstplace != -1) {
            allocation[i] = worstplace;
            bsize[worstplace] -= psize[i];
        }
    }

    // Print allocation results
    printf("\nProcess No\tProcess Size\tBlock No\n");
    for (int i = 0; i < pno; i++) {
        printf("%d\t\t%d\t\t", i + 1, psize[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1);
        } else {
            printf("Not Allocated\n");
        }
    }

    return 0;
}