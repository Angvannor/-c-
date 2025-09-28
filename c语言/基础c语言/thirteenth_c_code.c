#include <stdio.h>

void swap(int *a,int *b){
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int main(){
  int a = 12;
  int b = 13;
  printf("此时a的值为：%d\n，b的值为：%d\n", a,b);
  swap(&a,&b);
  printf("交换后，a的值为：%d\n，b的值为：%d\n", a,b);
  return 0;
}