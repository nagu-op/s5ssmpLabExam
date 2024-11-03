#include <stdio.h>

int main() {
    int n, r; // Number of processes and resources
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &r);

    int alloc[n][r], max[n][r], avail[r], need[n][r];

    // Input available resources
    printf("Enter the available resources:\n");
    for (int i = 0; i < r; i++) {
        scanf("%d", &avail[i]);
    }

    // Input max resources and allocated resources for each process
    for (int i = 0; i < n; i++) {
        printf("Enter the max resources for Process P%d:\n", i);
        for (int j = 0; j < r; j++) {
            scanf("%d", &max[i][j]);
        }
        printf("Enter the allocated resources for Process P%d:\n", i);
        for (int j = 0; j < r; j++) {
            scanf("%d", &alloc[i][j]);
            need[i][j] = max[i][j] - alloc[i][j]; // Calculate the need matrix
        }
    }

    // Print the Allocation, Max, and Need matrices
    printf("\nAllocation\tMax\t\tNeed\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < r; j++) {
            printf("%d ", alloc[i][j]);
        }
        printf("\t\t");
        for (int j = 0; j < r; j++) {
            printf("%d ", max[i][j]);
        }
        printf("\t\t");
        for (int j = 0; j < r; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    int finish[n], safeSeq[n], index = 0; // Track finished processes
    for (int i = 0; i < n; i++) {
        finish[i] = 0; // Initialize finish array
    }

    // Banker's algorithm to find a safe sequence
    while (index < n) {
        int found = 0; // Flag to check if a process can be executed
        for (int i = 0; i < n; i++) {
            if (finish[i] == 0) { // If the process is not finished
                int canAllocate = 1; // Assume we can allocate resources
                for (int j = 0; j < r; j++) {
                    if (need[i][j] > avail[j]) { // Check if need is greater than available
                        canAllocate = 0; // Can't allocate
                        break;
                    }
                }
                if (canAllocate) {
                    for (int j = 0; j < r; j++) {
                        avail[j] += alloc[i][j]; // Release allocated resources
                    }
                    safeSeq[index++] = i; // Add process to safe sequence
                    finish[i] = 1; // Mark process as finished
                    found = 1; // We found a process that can be executed
                }
            }
        }
        if (!found) { // If no process can be executed
            printf("No safe sequence exists!\n");
            return 0; // Exit
        }
    }

    // Print the safe sequence
    printf("Safe Sequence: ");
    for (int i = 0; i < n; i++) {
        printf("P%d ", safeSeq[i]);
    }
    printf("\n");

    return 0;
}
