#include <stdio.h>

int main(){
  float C;
  float F;

  printf("����һ�����϶�ת���϶ȵ�ת������\n");
  printf("�����뻪���¶ȣ�");
  scanf("%f",&F);

  C = (F - 32) * 5 / 9;
  printf("�����¶�Ϊ��%.2f\n", C);

  return 0;
}