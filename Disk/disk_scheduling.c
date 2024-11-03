#include <stdio.h>
#include <stdlib.h>

void main(){

	int ch = 0;
	while(ch != 4){
		printf("\nMENU\n1.FCFS\n2.SCAN\n3.C-SCAN\n");
		printf("Enter the choice : ");
		scanf("%d",&ch);
		if (ch == 1){
			int limit;
			printf("Enter the no of elements in the sequence: ");
			scanf("%d",&limit);
			int head;
			printf("\nEnter the head position: ");
			scanf("%d",&head);
			int arr[limit];
			arr[0] = head;
			printf("\nEnter the sequence: ");
			for(int i = 1; i<limit+1; i++){
			
				scanf("%d",&arr[i]);
			
			}
			
			printf("\nThe seek movement is \n");
			for(int i = 0; i<limit+1; i++){
			
				printf("%d ",arr[i]);
			
			}
			
			
			int distance,seektime = 0;
			
			for(int i = 0; i<limit; i++){
				
				distance = abs(arr[i]-arr[i+1]);
				seektime += distance;
			}
			printf("\nThe seek time is %d",seektime);
			
			
			
		}
		
		else if(ch == 2){
			int limit;
			printf("Enter the no of elements in the sequence: ");
			scanf("%d",&limit);
			int head;
			printf("\nEnter the head position: ");
			scanf("%d",&head);
			int arr1[limit],arr2[limit],MAX;
			printf("\nEnter the maximum value: ");
			scanf("%d",&MAX);
			printf("\nEnter the sequence: ");
			
			int element,x=0,y=0;
			for(int i = 0; i<limit; i++){
				scanf("%d",&element);
				if (element <head){
					arr1[x] = element;
					x++; 
				}
				else{
					arr2[y] = element;
					y++;
				
				}
			}
			//Sorting
			int temp;
			for(int i = 0;i<x+1;i++){
				for(int j = i+1;j<x;j++){
					if(arr1[i]<arr1[j]){
						temp = arr1[i];
						arr1[i] = arr1[j];
						arr1[j] = temp;
					}
				
				}
				
			
			}
			for(int i = 0;i<y+1;i++){
				for(int j = i+1;j<y;j++){
					if(arr2[i]>arr2[j]){
						temp = arr2[i];
						arr2[i] = arr2[j];
						arr2[j] = temp;
					}
				
				}
				
			
			}
			
			int arr[limit],z=0;
			arr[0] = head;
			for(int i=0;i<=y;i++){
				arr[i+1] = arr2[i];
				z++;
			
			
			}
			arr[z] = MAX;
			z++;
			for(int i=0;i<=x;i++){
				arr[z] = arr1[i];
				z++;
			
			
			}
			
			printf("\nThe seek movement is ->  ");
			for(int i = 0;i <=limit+1; i++){
			
				printf("%d ",arr[i]);
			
			}
			int distance = 0,seektime = 0;
			for(int i = 0; i <=limit; i++){
				
				
				distance = abs(arr[i]-arr[i+1]);
				seektime += distance;
			}
			printf("\nThe seek time is %d",seektime);
			
			
			
		
		}
		else if(ch == 3){
			int limit;
			printf("Enter the no of elements in the sequence: ");
			scanf("%d",&limit);
			int head;
			printf("\nEnter the head position: ");
			scanf("%d",&head);
			int arr1[limit],arr2[limit],MAX;
			printf("\nEnter the maximum value: ");
			scanf("%d",&MAX);
			printf("\nEnter the sequence: ");
			
			int element,x=0,y=0;
			for(int i = 0; i<limit; i++){
				scanf("%d",&element);
				if (element <head){
					arr1[x] = element;
					x++; 
				}
				else{
					arr2[y] = element;
					y++;
				
				}
			}
			//Sorting
			int temp;
			for(int i = 0;i<x+1;i++){
				for(int j = i+1;j<x;j++){
					if(arr1[i]>arr1[j]){
						temp = arr1[i];
						arr1[i] = arr1[j];
						arr1[j] = temp;
					}
				
				}
				
			
			}
			for(int i = 0;i<y+1;i++){
				for(int j = i+1;j<y;j++){
					if(arr2[i]>arr2[j]){
						temp = arr2[i];
						arr2[i] = arr2[j];
						arr2[j] = temp;
					}
				
				}
				
			
			}
			
			int arr[limit],z=0;
			arr[0] = head;
			for(int i=0;i<=y;i++){
				arr[i+1] = arr2[i];
				z++;
			
			
			}
			arr[z] = MAX;
			z++;
			arr[z] = 0;
			z++;
			for(int i=0;i<=x;i++){
				arr[z] = arr1[i];
				z++;
			
			
			}
			
			
			printf("\nThe seek movement is ->  ");
			for(int i = 0;i <=limit+2; i++){
			
				printf("%d ",arr[i]);
			
			}
			int distance,seektime = 0;
			for(int i = 0; i <=limit+1; i++){
			
				distance = abs(arr[i]-arr[i+1]);
				seektime += distance;
			}
			printf("\nThe seek time is %d",seektime);
			
			
		
		}
	
	}


}