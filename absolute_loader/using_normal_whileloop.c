#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main() {
    FILE *fp;
    int i, length;
    char line[50], arr[10];

    fp = fopen("objectcode.txt", "r");
    if (fp == NULL) return;

    fscanf(fp, "%s", line);
    printf("Program name is: ");
    for (i = 2; i < 8; i++) {
        printf("%c", line[i]);
    }
    printf("\n");

    fscanf(fp, "%s", line);
    while (!feof(fp)) {
        if (line[0] == 'T') {
            for (i = 0; i < 6; i++) {
                arr[i] = line[i + 2];
               
            }
            arr[i] = '\0';
            length = atoi(arr);

            i = 12;
            while (line[i] != '\0') {
                if (line[i] != '^') {
                    printf("%d : \t %c%c\n", length, line[i], line[i + 1]);
                    length++;
                    i += 2;
                } else {
                    i++;
                }
            }
        } else if (line[0] == 'E') {
            break;
        }
        fscanf(fp, "%s", line);
    }
    fclose(fp);
}
