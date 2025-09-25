#include <stdio.h>

int main(){
  FILE *fp;

  fp = fopen("test3.txt","w");
  if(fp == NULL){
    perror("文件打开失败!");
    return 1;
  }

  fputs("C语言文件操作示例。\n", fp);
  fputs("这是第二行内容。\n", fp);

  fclose(fp);
  return 0;
}