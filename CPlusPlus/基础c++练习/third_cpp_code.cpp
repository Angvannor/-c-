#include <iostream>

using namespace std;

int main(){
  float x,y,z;

  cout << "����һ���Ƚ�2������С�ĳ���" << endl << "������2�����������Կո�ָ���";
  cin >> x >> y;
  z = (x > y) ? x : y;
  cout << "�ϴ�ֵΪ��" << z << endl;

  return 0;
}