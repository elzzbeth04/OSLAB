#include <stdio.h>
#include <stdlib.h>

int main() {
    int RQ[100], initial, n, size, sum = 0, i, j, move;
    printf("Enter the number of Requests\n");
    scanf("%d", &n);
    
    // Reading the request sequence
    printf("Enter the Requests sequence\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &RQ[i]);
    }
    printf("Enter the head \n");
    scanf("%d", &initial);
    
    printf("Enter the disk size\n");
    scanf("%d", &size);
    
    printf("Enter the movement (0 for left, 1 for right): ");
    scanf("%d", &move);
    
    // Sort the requests
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (RQ[j] > RQ[j + 1]) {
                int temp = RQ[j];
                RQ[j] = RQ[j + 1];
                RQ[j + 1] = temp;
            }
        }
    }
    
    int index = 0;
    for (i = 0; i < n; i++) {
        if (RQ[i] > initial) {
            index = i;
            break;
        }
    }
    
    if (move == 1) {
        // Moving to the right first
        for (i = index; i < n; i++) {
            sum += abs(RQ[i] - initial);
            initial = RQ[i];
        }
        
        // Go to the end of the disk
        if (initial < size - 1) {
            sum += abs(size - 1 - initial);
            initial = size - 1;
        }
        
        // Wrap around to the start of the disk
        sum += abs(size - 1 - 0);
        initial = 0;
        
        // Service the requests on the left side
        for (i = 0; i < index; i++) {
            sum += abs(RQ[i] - initial);
            initial = RQ[i];
        }
    } else {
        // Moving to the left first
        for (i = index - 1; i >= 0; i--) {
            sum += abs(RQ[i] - initial);
            initial = RQ[i];
        }
        
        // Go to the start of the disk
        if (initial > 0) {
            sum += abs(initial - 0);
            initial = 0;
        }
        
        // Wrap around to the end of the disk
        sum += abs(size - 1 - 0);
        initial = size - 1;
        
        // Service the requests on the right side
        for (i = n - 1; i >= index; i--) {
            sum += abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }
    
    printf("Total head movements: %d\n", sum);
    return 0;
}
