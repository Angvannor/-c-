#include <stdio.h>

int main(){
  FILE *fp;
  char name[] = "Alice";
  int age = 30;

  fp = fopen("test4.txt","w");
  if(fp == NULL){
    perror("�ļ���ʧ��!");
    return 1;
  }

  fprintf(fp,"������%s,���䣺%d\n",name,age);
  
  fclose(fp);
  return 0; 
}