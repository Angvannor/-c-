#include <stdio.h>

// ɸѡ�������Ԫ��
int maxValue(int arr[],int n){
  int max = arr [0];
  for(int i = 1;i< n;i++){
    if(arr[i]>max){
      max = arr[i];
    }
  }
  return max; 
}

//ɸѡ������СԪ��
int minValue(int arr[],int n){
  int min = arr [0];
  for(int i = 1;i< n;i++){
    if(arr[i]<min){
      min = arr[i];
    }
  }
  return min; 
}

//��������ƽ��ֵ
double average(int arr[],int n){
  int sum = 0;
  for(int i = 0;i< n;i++){
    sum += arr[i];
  }
  return (double)sum/n; 
}

//��ת����
void reverse(int arr[],int n){
  for(int i = 0;i < n/2;i++){
    int temp = arr[i];
    arr[i] = arr[n-i-1];
    arr[n-i-1] = temp;
  }
}

//��������
void sort(int arr[],int n){
  for(int i = 0;i<n-1;i++){
    int minIndex = i;
    for(int j = i+1;j<n;j++){
      if(arr[j]<arr[minIndex]){
        minIndex = j;
      }
    }
    // �����ҵ�����Сֵ�͵�ǰֵ44
    if(minIndex != i){
      int temp = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = temp;
    }
  }
}

int main(){
  int n;
  printf("����������Ԫ�ظ���: ");
  scanf("%d", &n);

  int arr[n];
  printf("����������Ԫ��: ");
  for(int i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }

  printf("�������ֵ: %d\n", maxValue(arr, n));
  printf("������Сֵ: %d\n", minValue(arr, n));
  printf("����ƽ��ֵ: %.2f\n", average(arr, n));

  reverse(arr, n);
  printf("��ת�������: ");
  for(int i = 0; i < n; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");

  sort(arr, n);
  printf("����������: ");
  for(int i = 0; i < n; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}