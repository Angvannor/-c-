#include <stdio.h>

int main(){
  FILE *fp;

  fp = fopen("test3.txt","w");
  if(fp == NULL){
    perror("�ļ���ʧ��!");
    return 1;
  }

  fputs("C�����ļ�����ʾ����\n", fp);
  fputs("���ǵڶ������ݡ�\n", fp);

  fclose(fp);
  return 0;
}