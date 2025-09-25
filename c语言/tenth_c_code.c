#include <stdio.h>

char counter(){
  static int count = 0;
  count++;
  printf("函数被调用了%d次\n",count);
}

int main() {
  counter();
  counter();
  counter();
  return 0;
}