#include<iostream>

using namespace std;

const float PI = 3.14;

float calCircumference(int r){
  return 2*PI*r;
}

float calArea(int r){
  return PI*r*r;
}

int main(){
  int radius;
  cout << "请输入圆的半径：" << endl;
  cin >> radius;
  cout << "半径为" << radius << "的圆的周长为：" << calCircumference(radius) << endl;
  cout << "半径为" << radius << "的圆的面积为：" << calArea(radius) << endl;
  return 0;
}