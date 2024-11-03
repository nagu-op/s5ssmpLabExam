#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

void main(){

  FILE *source, *optab, *intermediate, *length, *symtab;

  source = fopen("source.txt","r");
  optab = fopen("optab.txt","r");
  intermediate = fopen("intermediate.txt","w");
  length = fopen("length.txt","w");
  symtab = fopen("symtab.txt","w+");

  char symtab_data[20], label[20], operand[20], opcode[20],optab_data[20];// temp storing of datas for checking and all
  int locctr, starting_address, program_length; // storing data for the flow of the program

  bool symbol_found, opcode_found; // for flagging wheather the symbol or opcode exist

  fscanf(source,"%s%s%s",label,opcode,operand);

  if (strcmp(opcode,"START") == 0){

    starting_address = atoi(operand);
    locctr = starting_address;
    fprintf(intermediate,"\t\t%s\t\t%s\t\t%s\n",label,opcode,operand);
  }
  else {
    locctr = 0;
  }

  fscanf(source,"%s%s%s",label,opcode,operand);
  while(strcmp(operand,"END")!=0){
    if(strcmp(label,"**")!=0){
      symbol_found = false;
      rewind(symtab);
      while(!feof(symtab)){
        fscanf(symtab,"%s",symtab_data);
        if(strcmp(symtab_data,label)== 0){
          printf("Error duplicate symbol");
          symbol_found = true;
        }
      }
      if(symbol_found == false){
        fprintf(symtab,"%s%d",label,locctr);
      }
    }
    opcode_found = false;
    rewind(optab);
    while(!feof(optab)){
      fscanf(optab,"%s",optab_data);
      if(strcmp(opcode,optab_data)==0){
        opcode_found = true;
      }

    }
    fprintf(intermediate,"%d",locctr);
    if(opcode_found == true){
      locctr  += 3;
    }
    else if(strcmp(opcode,"WORD")){
      locctr += 3;

    }
    else if(strcmp(opcode,"RESW")){
      locctr += atoi(operand)*3;
    }
    else if(strcmp(opcode,"RESB")){
      locctr += atoi(operand);
    }
    else if(strcmp(opcode,"BYTE")){
      locctr += strlen(operand)-3;
    }
    else{
      printf("Inalid operantor");
    }

    fprintf(intermediate,"\t\t%s\t\t%s\t\t%s\n",label,opcode,operand);
    fscanf(source,"%s%s%s",label,opcode,operand);
  }
  fprintf(intermediate,"%d\t\t%s\t\t%s\t\t%s\n",locctr,label,opcode,operand);
  program_length = locctr-starting_address;
  printf("the length of the program is %d",program_length);
  fprintf(length,"%d",program_length);
  fclose(symtab);
  fclose(intermediate);
  fclose(optab);
  fclose(length);
  fclose(source);




}
