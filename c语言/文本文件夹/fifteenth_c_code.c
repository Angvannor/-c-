#include <stdio.h>

int main(){
  FILE *fp;
  char buffer[100];

  fp = fopen("test2.txt","r");
  if(fp == NULL){
    perror("文件打开失败!");
    return 1;
  }

  if(fgets(buffer, sizeof(buffer), fp) != NULL){
    printf("读取的内容: %s", buffer);
  }

  fclose(fp);
  return 0;
}