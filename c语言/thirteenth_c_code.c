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
  printf("��ʱa��ֵΪ��%d\n��b��ֵΪ��%d\n", a,b);
  swap(&a,&b);
  printf("������a��ֵΪ��%d\n��b��ֵΪ��%d\n", a,b);
  return 0;
}