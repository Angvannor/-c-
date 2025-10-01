#include <stdio.h>

int find_max(int *a,int n){
  int max=a[0];
  for(int i=1;i<n;i++){
    if(a[i]>max){
      max=a[i];
    }
  }
  return max;
}

void reverse(int *a,int n){
  for(int i=0;i<n/2;i++){
    int temp=a[i];
    a[i]=a[n-1-i];
    a[n-1-i]=temp;
  }
}

void copy_array(int *src,int *dest,int n){
  for(int i=0;i<n;i++){
    dest[i]=src[i];
  }
}

void print_array(int *a,int n){
  for(int i=0;i<n;i++){
    printf("%d ",a[i]);
  }
  printf("\n");
}

int main(){
  int arr1[]={5,9,7,6,8};
  int n=sizeof(arr1)/sizeof(arr1[0]);
  printf("Max element is: %d\n",find_max(arr1,n));
  reverse(arr1,n);
  printf("Reversed array is: ");
  print_array(arr1,n);
  int arr2[5];
  copy_array(arr1,arr2,n);
  printf("Copied array is: ");
  print_array(arr2,n);
  return 0;
}