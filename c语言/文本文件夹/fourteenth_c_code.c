#include <stdio.h>

int main(){
  FILE *fp;

  fp = fopen("test1.txt","w");
  if(fp == NULL){
    perror("�ļ���ʧ��!");
    return 1;
  }

  printf("�ļ��򿪳ɹ�!\n");
  
  fclose(fp);
  return 0;
}