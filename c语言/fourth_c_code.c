#include <stdio.h>?

int main(){
  int array[5];
  int sum = 0;

  printf("����һ������5�������͵ĳ���\n");
  printf("������5���������Կո�ָ���");
  for(int i = 0;i<5;i++){
    scanf("%d",&array[i]);
    sum += array[i];
  }
  printf("5�������ĺ�Ϊ��%d\n", sum);
  return 0;
}