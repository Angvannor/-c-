#include<iostream>
#include<cmath>

using namespace std;

int main(){
  int a;
  cout << "请输入一个整数：" << endl;
  cin >> a;
  
  if(a < 0){
    cout << "负数没有实数平方根！" << endl;
    return 0;
  }

  double sqrt_a = sqrt(a);
  int int_sqrt_a = static_cast<int>(sqrt_a);
  if(int_sqrt_a * int_sqrt_a == a){
    cout << "该整数是完全平方数！" << endl;
    cout << "该整数的平方根为：" << int_sqrt_a << endl;
  }else{
    cout << "该整数不是完全平方数！" << endl;
    cout << "该整数的平方根为：" << sqrt_a << endl;
  }

  return 0;
}