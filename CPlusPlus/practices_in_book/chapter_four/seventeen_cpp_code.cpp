#include<iostream>
#include<cmath>

using namespace std;

int main(){
  int x,a,b,c;
  cout << "������ax^2+bx+c=0��ϵ��a��b��c��" << endl;
  cin >> a >> b >> c;
  if(a == 0){
    cout << "ϵ��a����Ϊ0�����������룡" << endl;
    return 1;
  }

  int discriminant = b*b - 4*a*c;
  if(discriminant > 0){
    float root1 = (-b + sqrt(discriminant)) / (2.0 * a);
    float root2 = (-b - sqrt(discriminant)) / (2.0 * a);
    cout << "������������ͬ��ʵ����" << root1 << " �� " << root2 << endl;
  } else if(discriminant == 0){
    float root = -b / (2.0 * a);
    cout << "������һ��ʵ����" << root << endl;
  } else{
    cout << "������ʵ����" << endl;
  }

  return 0;
}