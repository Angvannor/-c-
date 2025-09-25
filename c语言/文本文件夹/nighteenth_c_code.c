#include <stdio.h>

int main(){
  FILE *fp;

  fp = fopen("不存在的文件.txt","r");
  if(fp == NULL){
    perror("文件打开失败!");
    return 1;
  }

  fclose(fp);
  return 0;
}