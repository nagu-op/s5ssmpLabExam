#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(){

  FILE *fp;
  fp = fopen("objectcode.txt","r");
  char arr[10], line[50];
  int i,length;
  fscanf(fp,"%s",line);
  for( i = 2;i<8;i++){
    printf("%c",line[i]);
  }

  fscanf(fp,"%s",line);
  while(!feof(fp)){
    if(line[0] == 'T'){
      for(i = 0;i<6;i++){
        arr[i] = line[i+2];
      }
      arr[i] = '\0';
      length = atoi(arr);
      i = 12;
      while(line[i]!='\0'){
        if(line[i]!='^'){
          printf("%d: %c%c \n",length,line[i],line[i+1]);
          length++;
          i += 2;
        }
        else{
          i++;
        }


      }
      
    }
    else if (line[0] == 'E'){
      break;
    }
    fscanf(fp,"%s",line);



  }
  while(feof(fp)){
     fclose(fp);

  }
 

}