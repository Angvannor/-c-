#include <stdio.h>

int main(){
  float x,y,z;
  
  printf("����һ���Ƚ�2������С�ĳ���\n");
  printf("������2�����������Կո�ָ���");
  scanf("%f %f",&x,&y);
  z = (x > y) ? x : y;
  printf("�ϴ�ֵΪ��%.2f\n", z);

  return 0;
}