#include <iostream>

using namespace std;

void swap(int *a,int *b){
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int main(){
  int a = 12;
  int b = 13;
  cout << "��ʱa��ֵΪ��" << a << ",b��ֵΪ��" << b << endl;
  swap(&a,&b);
  cout << "������a��ֵΪ��" << a << ",b��ֵΪ��" << b << endl;
  return 0;
}