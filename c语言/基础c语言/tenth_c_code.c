#include <stdio.h>

char counter(){
  static int count = 0;
  count++;
  printf("������������%d��\n",count);
}

int main() {
  counter();
  counter();
  counter();
  return 0;
}