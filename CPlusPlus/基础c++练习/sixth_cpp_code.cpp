#include <iostream>

using namespace std;

int main(){
  int ownMoney = 1000;
  int saveMoney = 1000;
  int inputMoney = 0;
  int takeMoney = 0;
  int choice,operation = 1;

  cout << "��ӭʹ��ATMȡ���ϵͳ��" << endl;
  
  do{
    cout << "��ѡ��������ͣ�1.��� 2.ȡ��" << endl << "��ǰ�˻���" << ownMoney << endl << "��ǰ�����" << saveMoney << endl;
    cin >> choice;

    if(choice == 1){
      cout << "����������";
      cin >> inputMoney;
      if(inputMoney > ownMoney){
        cout << "���㣬�޷���" << endl;
      }else{
        saveMoney += inputMoney;
        ownMoney -= inputMoney;
        cout << "���ɹ���" << endl;
      }
    }else if(choice == 2){
      cout << "������ȡ���";
      cin >> takeMoney;
      if(takeMoney > saveMoney){
        cout << "���㣬�޷�ȡ�" << endl;
      }else{
        saveMoney -= takeMoney;
        ownMoney += takeMoney;
        cout << "ȡ��ɹ���" << endl;
      }
    }else{
      cout << "���������������" << endl;
    }
    cout << "�Ƿ���������� 1.�� 2.��" << endl;
    cin >> operation;
    if(operation == 2){
      cout << "��лʹ��ATM��ȡ��ϵͳ��" << endl;
      break;
    }else if(operation != 1 && operation != 2){
      cout << "���������������" << endl;
      break;
    }
  }while(operation == 1);

  return 0;
}