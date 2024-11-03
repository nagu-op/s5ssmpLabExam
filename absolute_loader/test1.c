#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main() {
    FILE *fp;
    int i, length;
    char line[50], arr[10];

    // Attempt to open the file
    fp = fopen("objectcode.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file 'objectcode.txt'\n");
        return; // Exit the program if the file cannot be opened
    }

    // Read the first line from the file
    if (fscanf(fp, "%s", line) != 1) {
        printf("Error: Could not read from file or file is empty.\n");
        fclose(fp);
        return; // Exit if the file is empty or reading failed
    }

    // Print the line read for debugging
    printf("Read line: %s\n", line);

    // Check if the line is an H record
    if (line[0] == 'H') {
        // Process H record (Header Record)
        printf("Processing H record:\n");
        for (i = 0; i < 6; i++) {
            arr[i] = line[i + 1];  // Starting from index 1 to skip 'H'
            printf("arr[%d] = %c\n", i, arr[i]);  // Print each character assigned to arr
        }
        arr[i] = '\0';  // Null-terminate the string
        printf("Program Name: %s\n", arr); // Print the program name
        printf("Starting Address: %s\n", &line[8]); // Print the starting address (next 6 characters)
        
    } else if (line[0] == 'T') {
        // If it is a T record, process it as before
        for (i = 0; i < 6; i++) {
            arr[i] = line[i + 2];
            printf("arr[%d] = %c\n", i, arr[i]);  // Print each character assigned to arr
        }
        arr[i] = '\0';  // Null-terminate the string
        length = atoi(arr);  // Convert arr to integer
        
        // Print the extracted length
        printf("Extracted length: %d\n", length);
        
        // Continue processing object code...
        i = 12;
        while (line[i] != '\0') {
            if (line[i] != '^') {
                length++; // Increment length for each byte processed
                i += 2; // Move to the next byte in the object code
            } else {
                i++;
            }
        }
    } else if (line[0] == 'E') {
        // End processing if needed
        printf("End of records.\n");
        fclose(fp);
        return; // Exit the program if the end record is found
    }

    fclose(fp);
}
