#include <iostream>

using namespace std;

int main(){
  float C;
  float F;
  int choice;

  cout << "���϶Ⱥ����϶ȵ�ת������������ѡ��" << endl << "1.���϶�ת���϶�" << endl << "2.���϶�ת���϶�" << endl;
  cin >> choice;
  if(choice == 1){
    cout << "����һ�����϶�ת���϶ȵ�ת������" << endl << "�����뻪���¶ȣ�" << endl;
    cin >> F;
    
    C = (F - 32) * 5 / 9;
    cout << "�����¶�Ϊ��" << C << endl;
  }else if(choice == 2){
    cout << "����һ�����϶�ת���϶ȵ�ת������" << endl << "�����������¶ȣ�" << endl;
    cin >> C;
    
    F = C * 9 / 5 + 32;
    cout << "�����¶�Ϊ��" << F << endl;
  }

  return 0;
}