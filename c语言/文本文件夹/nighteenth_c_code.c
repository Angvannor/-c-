#include <stdio.h>

int main(){
  FILE *fp;

  fp = fopen("�����ڵ��ļ�.txt","r");
  if(fp == NULL){
    perror("�ļ���ʧ��!");
    return 1;
  }

  fclose(fp);
  return 0;
}