#include<iostream>
#include<cmath>

using namespace std;

#define s(a,b,c) (1/2.0*(a)+(b)+(c))
#define area(a,b,c) (sqrt(s(a,b,c)*(s(a,b,c)-(a))*(s(a,b,c)-(b))*(s(a,b,c)-(c))))

int main(){
  float a,b,c;
  cout << "�����������ε������߳���" << endl;
  cin >> a >> b >> c;
  if(a+b>c && a+c>b && b+c>a){
    cout << "�����ε����Ϊ��" << area(a,b,c) << endl;
  }else{
    cout << "�޷����������Σ�" << endl;
  }
  return 0;
}