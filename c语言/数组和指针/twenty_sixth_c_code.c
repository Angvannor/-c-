#include <stdio.h>

int main(){
  int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int *p = array; // 指针指向数组的首元素
  for(int i = 0; i < 10; i++){
    printf("Element %d: %d\n", i, *(p + i)); // 通过指针访问数组元素
  }
}
