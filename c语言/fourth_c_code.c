#include <stdio.h>?

int main(){
  int array[5];
  int sum = 0;

  printf("这是一个计算5个整数和的程序。\n");
  printf("请输入5个整数，以空格分隔：");
  for(int i = 0;i<5;i++){
    scanf("%d",&array[i]);
    sum += array[i];
  }
  printf("5个整数的和为：%d\n", sum);
  return 0;
}