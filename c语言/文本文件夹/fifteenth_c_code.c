#include <stdio.h>

int main(){
  FILE *fp;
  char buffer[100];

  fp = fopen("test2.txt","r");
  if(fp == NULL){
    perror("�ļ���ʧ��!");
    return 1;
  }

  if(fgets(buffer, sizeof(buffer), fp) != NULL){
    printf("��ȡ������: %s", buffer);
  }

  fclose(fp);
  return 0;
}