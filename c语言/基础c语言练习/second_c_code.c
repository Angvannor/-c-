#include <stdio.h>

int main(){
  float C;
  float F;

  printf("这是一个华氏度转摄氏度的转换程序。\n");
  printf("请输入华氏温度：");
  scanf("%f",&F);

  C = (F - 32) * 5 / 9;
  printf("摄氏温度为：%.2f\n", C);

  return 0;
}