#include <stdio.h>

int main(){
  FILE *fp;
  char name[20];
  int age;

  fp = fopen("test4.txt","r");
  if(fp == NULL){
    perror("�ļ���ʧ��!");
    return 1;
  }

  fscanf(fp,"������%20[^,],���䣺%d",name,&age);
  printf("��ȡ������: ������%s, ���䣺%d\n", name, age);

  fclose(fp);
  return 0;
}