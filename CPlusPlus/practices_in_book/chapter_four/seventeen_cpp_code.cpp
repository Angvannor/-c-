#include<iostream>
#include<cmath>

using namespace std;

int main(){
  int x,a,b,c;
  cout << "请输入ax^2+bx+c=0的系数a、b、c：" << endl;
  cin >> a >> b >> c;
  if(a == 0){
    cout << "系数a不能为0，请重新输入！" << endl;
    return 1;
  }

  int discriminant = b*b - 4*a*c;
  if(discriminant > 0){
    float root1 = (-b + sqrt(discriminant)) / (2.0 * a);
    float root2 = (-b - sqrt(discriminant)) / (2.0 * a);
    cout << "方程有两个不同的实根：" << root1 << " 和 " << root2 << endl;
  } else if(discriminant == 0){
    float root = -b / (2.0 * a);
    cout << "方程有一个实根：" << root << endl;
  } else{
    cout << "方程无实根。" << endl;
  }

  return 0;
}