#include <iostream>

using namespace std;

int main(){
  float x,y,z;

  cout << "这是一个比较2个数大小的程序。" << endl << "请输入2个浮点数，以空格分隔：";
  cin >> x >> y;
  z = (x > y) ? x : y;
  cout << "较大值为：" << z << endl;

  return 0;
}