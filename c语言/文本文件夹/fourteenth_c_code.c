#include <stdio.h>

int main(){
  FILE *fp;

  fp = fopen("test1.txt","w");
  if(fp == NULL){
    perror("文件打开失败!");
    return 1;
  }

  printf("文件打开成功!\n");
  
  fclose(fp);
  return 0;
}