#include <stdio.h>
#include <stdlib.h>

int main(){
  int n;
  printf("����������Ĵ�С: ");
  scanf("%d", &n);

  int *arr = (int *)malloc(n * sizeof(int));
  if(arr == NULL){
    printf("�ڴ����ʧ��\n");
    return 1;
  }

  printf("������ %d ������:\n", n);
  for(int i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }

  printf("�����������Ԫ����:\n");
  for(int i = 0; i < n; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");

  free(arr);  // �ͷŶ�̬������ڴ�
  arr = NULL; // ��������ָ��
  return 0;
}