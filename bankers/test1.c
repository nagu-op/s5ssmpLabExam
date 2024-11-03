#include<stdio.h>

int  main(){

  int n, r;
  printf("Enter the number of processes: ");
  scanf("%d",&n);
  printf("Enter the no of resources: ");
  scanf("%d",&r);

  int alloc[n][r], max[n][r], need[n][r], avail[r];
  printf("Enter the available resources: ");
  for(int i = 0; i<r ; i++){
   
    scanf("%d", &avail[i]);
  }
  for(int i = 0;i<n; i++){
    printf("Enter the max matrix of process %d",i);
    for(int j = 0;j<r;j++){
      scanf("%d",&max[i][j]);
    }
    printf("Enter the alocation matrix of process %d",i);
    for(int j = 0 ;j < r; j++){
      scanf("%d",&alloc[i][j]);
      need[i][j] = max[i][j] - alloc[i][j];
    }
  }
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


   int finish[n], safeSeq[n], index = 0;
   for(int i = 0; i< n; i++){
    finish [i] = 0;
   }
   int found;

   while(index < n){
    found = 0;
    for(int i = 0;i<n;i++){
      if(finish[i] == 0){
        int canAllocate = 1;
        for(int j = 0;j<r;j++){
          if (need[i][j] > max[i][j]){
            canAllocate = 0;
            break;

          }
          
        }
        if(canAllocate == 1){
          for(int j = 0;j<r; j++){
            avail[j] += alloc[i][j];
          }
          safeSeq[index++] = i;
          finish[i] = 1;
          found = 1;

        }
      }
    }
    if(found == 0){
      printf("no safe sequence");
      return 0;
    }
   }
   printf("\nThe safe sequence is :\n");
   for(int i = 0; i< n-1; i++){
    printf("P%d->",safeSeq[i]);
   }
   printf("P%d",safeSeq[n-1]);


return 0;

}