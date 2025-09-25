#include <stdio.h>

int main(){
  FILE *fp;
  char name[] = "Alice";
  int age = 30;

  fp = fopen("test4.txt","w");
  if(fp == NULL){
    perror("文件打开失败!");
    return 1;
  }

  fprintf(fp,"姓名：%s,年龄：%d\n",name,age);
  
  fclose(fp);
  return 0; 
}