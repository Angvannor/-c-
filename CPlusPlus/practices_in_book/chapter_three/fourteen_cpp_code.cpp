#include<iostream>
#include<cmath>

using namespace std;

int main(){
  int a;
  cout << "������һ��������" << endl;
  cin >> a;
  
  if(a < 0){
    cout << "����û��ʵ��ƽ������" << endl;
    return 0;
  }

  double sqrt_a = sqrt(a);
  int int_sqrt_a = static_cast<int>(sqrt_a);
  if(int_sqrt_a * int_sqrt_a == a){
    cout << "����������ȫƽ������" << endl;
    cout << "��������ƽ����Ϊ��" << int_sqrt_a << endl;
  }else{
    cout << "������������ȫƽ������" << endl;
    cout << "��������ƽ����Ϊ��" << sqrt_a << endl;
  }

  return 0;
}