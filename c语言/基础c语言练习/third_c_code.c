#include <stdio.h>

int main(){
  float x,y,z;
  
  printf("这是一个比较2个数大小的程序。\n");
  printf("请输入2个浮点数，以空格分隔：");
  scanf("%f %f",&x,&y);
  z = (x > y) ? x : y;
  printf("较大值为：%.2f\n", z);

  return 0;
}