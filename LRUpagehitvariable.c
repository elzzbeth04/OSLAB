#include <stdio.h>

int main() {
    int n, rs[10], m[10], count[10], flag[10], f, next = 1, min, pf = 0;

    // Input the length of the reference string
    printf("Enter the length of the reference string: ");
    scanf("%d", &n);

    // Input the reference string
    printf("Enter the reference string: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &rs[i]);
        flag[i] = 0; // Initialize flag array
    }

    // Input the number of frames
    printf("Enter the number of frames: ");
    scanf("%d", &f);

    // Initialize frames and count arrays
    for(int i = 0; i < f; i++) {
        m[i] = -1;    // Initialize frames to -1 (empty)
        count[i] = 0; // Initialize count array
    }

    // Process the reference string
    for(int i = 0; i < n; i++) {
        int pageHit = 0;
        
        // Check if the page is already in a frame
        for(int j = 0; j < f; j++) {
            if(m[j] == rs[i]) {
                flag[i] = 1; // Page hit
                count[j] = next; // Update the count for LRU tracking
                next++;
                pageHit = 1;
                break;
            }
        }

        // Handle page fault
        if(!pageHit) {
            if (i < f) {
                // Initially fill the frames if they are empty
                m[i] = rs[i];
                count[i] = next;
                next++;
            } else {
                // Find the least recently used page (minimum count value)
                min = 0;
                for(int j = 1; j < f; j++) {
                    if(count[min] > count[j]) {
                        min = j;
                    }
                }
                // Replace the LRU page with the current page
                m[min] = rs[i];
                count[min] = next;
                next++;
            }
            pf++; // Increment the page fault count
        }

        // Print the current state of frames
        printf("Frames: ");
        for(int j = 0; j < f; j++) {
            if (m[j] != -1) {
                printf("%d ", m[j]);
            } else {
                printf("- "); // Show empty slots as "-"
            }
        }

        // Print page fault information
        if(!pageHit) {
            printf(" -> Page Fault No. %d", pf);
        }
        printf("\n");

        // Reset the flag array for the next iteration
        for(int k = 0; k < n; k++) {
            flag[k] = 0;
        }
    }

    // Print the total number of page faults
    printf("\nThe number of page faults using LRU are %d\n", pf);

    return 0;
}
