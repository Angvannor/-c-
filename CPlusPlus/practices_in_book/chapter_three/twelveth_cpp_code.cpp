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
  cout << "������Բ�İ뾶��" << endl;
  cin >> radius;
  cout << "�뾶Ϊ" << radius << "��Բ���ܳ�Ϊ��" << calCircumference(radius) << endl;
  cout << "�뾶Ϊ" << radius << "��Բ�����Ϊ��" << calArea(radius) << endl;
  return 0;
}