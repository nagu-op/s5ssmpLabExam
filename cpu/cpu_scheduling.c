#include<stdio.h>


int main(){ 
	int ch = 1;
	while(ch != 0){
	
		printf("\nMENU\n1.FCFS\n2.SJF\n3.Priority\n4.RoundRobin\n0.Exit");
		printf("\nEnter the choice: \n");
		scanf("%d",&ch);
		if (ch == 1){
			 int limit;
			  printf("Enter the no of process: ");
			  scanf("%d",&limit);
			  int process[limit],bt[limit],wt[limit],tat[limit];
			  for(int i = 1;i<limit;i++){
			  
			  	bt[i] = 0;
			  	wt[i] = 0;
			  	tat[i] = 0;
			  
			  }

			  printf("Enter the process and the bt");
			  for(int i = 0; i<limit;i++){

			    scanf("%d%d",&process[i],&bt[i]);
			  }
			  int tot_wt,tot_tat;
			  wt[0] = 0;
			  tat[0] = bt[0];
			  for(int i = 1;i<limit; i++){

			    wt[i] = wt[i-1] + bt[i-1];
			    tat[i] = tat[i-1]+ bt[i];
			    tot_wt += wt[i];
			    tot_tat += tat[i];
			  }
			  printf("Process\tbt\twt\ttat\n");
			  for(int i = 0;i<limit; i++){
			    printf("%d  %d  %d  %d",process[i],bt[i],wt[i],tat[i]);
			    printf("\n");
			  }
			  
			  printf("\nGantt Chart");
			  printf("\n");
			  
			 
			 for(int i = 0;i<limit;i++){
			 
			 	printf("   %d   ",process[i]);
			 
			 
			 }
			 printf("\n");
			 for(int i = 0;i<limit;i++){
			 
			 	printf("%d      ",wt[i]);
			 
			 
			 }
			 printf("%d",tat[limit-1]);
			 printf("\n");
			 
			 printf("\nTotal turn around time is %d\nTotal waiting time is %d",tot_tat,tot_wt);
			printf("\n Average turn around time is %d\n Average waiting time is %d\n ",tot_tat/limit,tot_wt/limit);			


}
			
		else if(ch == 2){



		  printf("Enter the no of process: ");
		  int limit;
		  scanf("%d",&limit);
		  int process[limit],bt[limit],wt[limit],tat[limit];
		   for(int i = 0;i<limit;i++){
			  
			  	bt[i] = 0;
			  	wt[i] = 0;
			  	tat[i] = 0;
			  
			  }

		  printf("Enter the no of process and bt: ");
		  

		  for(int i = 0; i<limit;i++){
		    scanf("%d%d",&process[i],&bt[i]);
		  }
		  int temp;
		  for(int i = 0;i<limit;i++){
		    for(int j = i+1; j<limit;j++){
		      if(bt[j]<bt[i]){
			temp = bt[i];
			bt[i] = bt[j];
			bt[j] = temp;

			temp = process[i];
			process[i] = process[j];
			process[j] = temp;

		      }
		    }
		  }
		  int tot_wt,tot_tat;
		  wt[0] = 0;
		  tat[0] = bt[0];
		  

		  for(int i = 1;i<limit; i++){
		    wt[i] = wt[i-1] + bt[i-1];
		    tat[i] = tat[i-1] + bt[i];
		    tot_tat+= tat[i];
		    tot_wt += wt[i];

		  }

		  printf("Process\tbt\twt\ttat\n");
		  for(int i = 0;i<limit; i++){
		    printf("%d  %d  %d  %d",process[i],bt[i],wt[i],tat[i]);
		    printf("\n");
		  }
		  
		  printf("\nGantt Chart");
			  printf("\n");
			  
			 
			 for(int i = 0;i<limit;i++){
			 
			 	printf("   %d   ",process[i]);
			 
			 
			 }
			 printf("\n");
			 for(int i = 0;i<limit;i++){
			 
			 	printf("%d      ",wt[i]);
			 
			 
			 }
			 printf("%d",tat[limit-1]);
			 printf("\n");
			 
			 printf("\nTotal turn around time is %d\nTotal waiting time is %d",tot_tat,tot_wt);


				}
				
			else if(ch == 3){
		
			printf("Enter the no of process: ");
			  int limit;
			  scanf("%d",&limit);

			  printf("Enter the no of process, bt and priority: ");
			  int process[limit],bt[limit],wt[limit],tat[limit],priority[limit];

			  for(int i = 0; i<limit;i++){
			    scanf("%d%d%d",&process[i],&bt[i],&priority[i]);
			  }
			  int temp;
			  for(int i = 0;i<limit;i++){
			    for(int j = i+1; j<limit;j++){
			      if(priority[i]>priority[j]){
				temp = priority[i];
				priority[i] = priority[j];
				priority[j] = temp;

				temp = process[i];
				process[i] = process[j];
				process[j] = temp;

				temp = bt[i];
				bt[i] = bt[j];
				bt[j] = temp;
			      }
			    }
			  }
			  wt[0] = 0;
			  tat[0] = bt[0];
			int tot_wt = 0,tot_tat = 0;
			  for(int i = 1; i<limit; i++){

			    wt[i] = wt[i-1] + bt[i-1];
			    tat[i] = wt[i] + bt[i];
			    tot_tat = tot_tat + tat[i];
			    tot_wt = tot_wt + wt[i];
			  }

			   printf("Process\tpriority\tbt\twt\ttat\n");
			  for(int i = 0;i<limit; i++){
			    printf("%d    %d    %d    %d    %d",process[i],priority[i],bt[i],wt[i],tat[i]);
			    printf("\n");
			  }
			  printf("\nGantt Chart");
			  printf("\n");
			  
			 
			 for(int i = 0;i<limit;i++){
			 
			 	printf("   %d   ",process[i]);
			 
			 
			 }
			 printf("\n");
			 for(int i = 0;i<limit;i++){
			 
			 	printf("%d      ",wt[i]);
			 
			 
			 }
			 printf("%d",tat[limit-1]);
			 printf("\n");
			 
			 printf("\nToata turn around time is %d\nTotal waiting time is %d",tot_tat,tot_wt);

		
		}
		else if(ch == 4){
		  printf("Input the time Quantum");
		  int TIME_QUANTUM;
		  scanf("%d",&TIME_QUANTUM);

		  int limit;

		  printf("Enter the no of processes: ");
		  scanf("%d",&limit);

		  int porcess[limit],bt[limit],rem_bt[limit],wt[limit],tat[limit];

		  int time = 0,completed = 0;

		  printf("Enter the process no and bt: ");
		  for(int i = 0; i<limit; i++){
		      scanf("%d%d",&porcess[i],&bt[i]);

		  }
		 for(int i = 0; i<limit; i++){
		      rem_bt[i] = bt[i];

		  }
		  
		 int TimeArr[10],ProArr[10],FinalTime = 0;
		 int x=0;
		    while(completed<limit){
		       for(int i = 0; i<limit; i++){
			  if(rem_bt[i]>0){
			    if (rem_bt[i]>TIME_QUANTUM){
			      time += TIME_QUANTUM;
			      rem_bt[i] -= TIME_QUANTUM;
			     TimeArr[x] = TIME_QUANTUM;
			     ProArr[x] = porcess[i]; 
			     x++;
			      
			    }
			    else{
			      time += rem_bt[i];
			      wt[i] = time -bt[i];
			      tat[i] = time;
			      TimeArr[x] = rem_bt[i];
			      rem_bt[i] = 0;
			      completed++;
			     
			     ProArr[x] = porcess[i];
			    x++;
			    }

		      }
		    }

		  }
		  printf("Process\tBT\tWT\tTAT\n");
		    for (int i = 0; i < limit; i++) {
			printf("%d\t%d\t%d\t%d\n", porcess[i], bt[i], wt[i], tat[i]);
		
	    }
	    
	    printf("Gantt chart");
	    
	    for(int i = 0;i<limit; i++){
	    	FinalTime += bt[i];
	    }
	    printf("\n");
	    for(int i = 0; i<x; i++){
	    	printf("   %d   ",ProArr[i]);
	    	
	    }
	    int y = 0;
	    printf("\n0     ");
	    for(int i = 0; i<x; i++){
	    	printf("%d     ",y+=TimeArr[i]);
	    	
	    }
	    
	    
	    
			
			
			}
			
			}
			
		
  return 0;
}