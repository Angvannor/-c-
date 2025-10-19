#include <iostream>

using namespace std;

int main(){
  int array[5];
  int sum = 0;

  cout << "这是一个计算5个整数和的程序。" << endl << "请输入5个整数，以空格分隔：" << endl;
  for(int i = 0;i<5;i++){
    cin >> array[i];
    sum += array[i];
  }
  cout << "5个整数的和为：" << sum << endl;
  return 0;
}