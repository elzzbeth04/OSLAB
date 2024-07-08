#include <stdio.h>

int main() {
    int n, m, i, j, k, ind = 0; // Declare variables
    int alloc[20][20], max[20][20], avail[50]; // Matrices for allocation, maximum, and available resources
    int finish[20], safesequence[20], work[20], need[20][20]; // Additional arrays for the algorithm

    printf("Enter the number of Processes: ");
    scanf("%d", &n); // Read the number of processes

    printf("Enter the number of Resources: ");
    scanf("%d", &m); // Read the number of resource types

    // Input the Allocation Matrix
    printf("Enter the Allocation Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]); // Read each element of the allocation matrix
        }
    }

    // Input the Max Matrix
    printf("Enter the Max Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &max[i][j]); // Read each element of the maximum matrix
        }
    }

    // Input the Available Matrix
    printf("Enter the Available Matrix:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &avail[i]); // Read each element of the available matrix
    }

    // Initialize the work array with available resources
    for (i = 0; i < m; i++) {
        work[i] = avail[i];
    }

    // Initialize the finish array to 0 (indicating no process is finished yet)
    for (i = 0; i < n; i++) {
        finish[i] = 0;
    }
for (i = 0; i < n; i++) {
        safesequence[i] = 0;
    }
    // Calculate the Need matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j]; // Need = Max - Allocation
        }
    }

    // Print the Need matrix
    printf("NEED matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    // Determine the Safe Sequence
    for (k = 0; k < n; k++) {
      int  found=0;
        for (i = 0; i < n; i++) {
            
            if (finish[i] == 0) { // If the process is not finished
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) { // Check if the process's need exceeds the available resources
                        flag = 1;
                        break;
                    }
                   }
                
                    if(flag==0)
                        {
                         safesequence[ind++] = i;
                         for(int w=0;w<m;w++){
                             work[w]+=alloc[i][w];
                         }
                         finish[i]=1;
                         found=1;
                    }
                
               
                }
            }
            if(found=0)
            break;
        }
        int safe =1;
        for(i=0;i<n;i++)
        {
            if(finish[i]==0)
            {safe=0;
                printf("not safe");
                break;
            }
        }
        if(safe)
        {
            printf("safe sequence\n");
        for(i=0;i<n;i++)
        {printf("P%d ",safesequence[i]);
    }
}  
        }
        
    
      

    // Print the Safe Sequence
 
    


