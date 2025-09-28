#include <stdio.h>

// 筛选数组最大元素
int maxValue(int arr[],int n){
  int max = arr [0];
  for(int i = 1;i< n;i++){
    if(arr[i]>max){
      max = arr[i];
    }
  }
  return max; 
}

//筛选数组最小元素
int minValue(int arr[],int n){
  int min = arr [0];
  for(int i = 1;i< n;i++){
    if(arr[i]<min){
      min = arr[i];
    }
  }
  return min; 
}

//计算数组平均值
double average(int arr[],int n){
  int sum = 0;
  for(int i = 0;i< n;i++){
    sum += arr[i];
  }
  return (double)sum/n; 
}

//反转数组
void reverse(int arr[],int n){
  for(int i = 0;i < n/2;i++){
    int temp = arr[i];
    arr[i] = arr[n-i-1];
    arr[n-i-1] = temp;
  }
}

//排序数组
void sort(int arr[],int n){
  for(int i = 0;i<n-1;i++){
    int minIndex = i;
    for(int j = i+1;j<n;j++){
      if(arr[j]<arr[minIndex]){
        minIndex = j;
      }
    }
    // 交换找到的最小值和当前值44
    if(minIndex != i){
      int temp = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = temp;
    }
  }
}

int main(){
  int n;
  printf("请输入数组元素个数: ");
  scanf("%d", &n);

  int arr[n];
  printf("请输入数组元素: ");
  for(int i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }

  printf("数组最大值: %d\n", maxValue(arr, n));
  printf("数组最小值: %d\n", minValue(arr, n));
  printf("数组平均值: %.2f\n", average(arr, n));

  reverse(arr, n);
  printf("反转后的数组: ");
  for(int i = 0; i < n; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");

  sort(arr, n);
  printf("排序后的数组: ");
  for(int i = 0; i < n; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}