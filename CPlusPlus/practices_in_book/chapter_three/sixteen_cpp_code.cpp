#include<iostream>

using namespace std;

int main(){
  cout << "��������λ���ķ�Χ��" << endl;
  int start, end;
  cin >> start >> end;

  if(start < 100 || end > 999 || start >= end){
    cout << "���뷶Χ�������������룡" << endl;
    return 1;
  }

  for(int i = start;i <= end;i++){
    int hundred = i / 100;
    int ten = (i / 10) % 10;
    int unit = i % 10;
    if(i == hundred * hundred * hundred + ten * ten * ten + unit * unit * unit){
      cout << i << "��ˮ�ɻ�����" << endl;
    } else{
      continue;
    }
  }

  return 0;
}