#include <stdio.h>
#include <stdlib.h>

int main(){
  int n;
  printf("请输入数组的大小: ");
  scanf("%d", &n);

  int *arr = (int *)malloc(n * sizeof(int));
  if(arr == NULL){
    printf("内存分配失败\n");
    return 1;
  }

  printf("请输入 %d 个整数:\n", n);
  for(int i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }

  printf("你输入的数组元素是:\n");
  for(int i = 0; i < n; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");

  free(arr);  // 释放动态分配的内存
  arr = NULL; // 避免悬空指针
  return 0;
}