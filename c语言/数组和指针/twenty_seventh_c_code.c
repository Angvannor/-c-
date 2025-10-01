#include <stdio.h>

void print_array(int arr[],int n){
  for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
  }
  printf("\n");
}

void print_array_by_pointer(int *arr,int n){
  for(int i=0;i<n;i++){
    printf("%d ",*(arr+i));
  }
  printf("\n");
}

int main(){
  int arr[5]={2,5,6,4,8};
  printf("Array elements are:\n");
  print_array(arr,5);
  printf("Array elements by pointer are:\n");
  print_array_by_pointer(arr,5);

  return 0;
}