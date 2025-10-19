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
  cout << "此时a的值为：" << a << ",b的值为：" << b << endl;
  swap(&a,&b);
  cout << "交换后，a的值为：" << a << ",b的值为：" << b << endl;
  return 0;
}