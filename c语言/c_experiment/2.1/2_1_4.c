#include <stdio.h>

int main(){
    // 2.1.4
  float h,w,s;
  printf("Please input two numbers(h,w):\n");
  scanf("%f %f",&h,&w);
  s = h * w;
  printf("s = %.2f",s);

  return 0;
}