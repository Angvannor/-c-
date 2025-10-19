#include <iostream>

using namespace std;

int main(){
  int ownMoney = 1000;
  int saveMoney = 1000;
  int inputMoney = 0;
  int takeMoney = 0;
  int choice,operation = 1;

  cout << "欢迎使用ATM取存款系统！" << endl;
  
  do{
    cout << "请选择操作类型：1.存款 2.取款" << endl << "当前账户余额：" << ownMoney << endl << "当前存款余额：" << saveMoney << endl;
    cin >> choice;

    if(choice == 1){
      cout << "请输入存款余额：";
      cin >> inputMoney;
      if(inputMoney > ownMoney){
        cout << "余额不足，无法存款！" << endl;
      }else{
        saveMoney += inputMoney;
        ownMoney -= inputMoney;
        cout << "存款成功！" << endl;
      }
    }else if(choice == 2){
      cout << "请输入取款金额：";
      cin >> takeMoney;
      if(takeMoney > saveMoney){
        cout << "余额不足，无法取款！" << endl;
      }else{
        saveMoney -= takeMoney;
        ownMoney += takeMoney;
        cout << "取款成功！" << endl;
      }
    }else{
      cout << "操作类型输入错误！" << endl;
    }
    cout << "是否继续操作？ 1.是 2.否" << endl;
    cin >> operation;
    if(operation == 2){
      cout << "感谢使用ATM存取款系统！" << endl;
      break;
    }else if(operation != 1 && operation != 2){
      cout << "操作类型输入错误！" << endl;
      break;
    }
  }while(operation == 1);

  return 0;
}