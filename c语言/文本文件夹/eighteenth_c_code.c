#include <stdio.h>

int main(){
  FILE *fp;
  char name[20];
  int age;

  fp = fopen("test4.txt","r");
  if(fp == NULL){
    perror("文件打开失败!");
    return 1;
  }

  fscanf(fp,"姓名：%20[^,],年龄：%d",name,&age);
  printf("读取的内容: 姓名：%s, 年龄：%d\n", name, age);

  fclose(fp);
  return 0;
}