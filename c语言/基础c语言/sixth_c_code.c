#include <stdio.h>

int main(){
  int ownMoney = 1000;
  int saveMoney = 1000;
  int inputMoney = 0;
  int takeMoney = 0;
  int choice,operation = 1;

  printf("欢迎使用ATM存取款系统！\n");
  
  
  do{
    printf("请选择操作类型：1.存款 2.取款\n");
    printf("当前账户余额：%d\n", ownMoney);
    printf("当前存款余额：%d\n", saveMoney);
    scanf("%d", &choice);

    if(choice == 1){
    printf("请输入存款金额：");
    scanf("%d",&inputMoney);
    if(inputMoney > ownMoney){
      printf("余额不足，无法存款！\n");
    }else{
      saveMoney += inputMoney;
      ownMoney -= inputMoney;
      printf("存款成功!\n");
    } 
  }else if(choice == 2){
    printf("请输入取款金额：");
    scanf("%d",&takeMoney);
    if(takeMoney > saveMoney){
      printf("余额不足，无法取款！\n");
    }else{
      saveMoney -= takeMoney;
      ownMoney += takeMoney;
      printf("取款成功!\n");
    }
  }else{
    printf("操作类型输入错误！\n");
  }
  printf("是否继续操作？1.是 2.否\n");
    scanf("%d", &operation);
    if(operation == 2){
      printf("感谢使用ATM存取款系统！\n");
      break;
    }else if(operation != 1 && operation != 2){
      printf("操作类型输入错误！\n");
      break;
    }
}while(operation == 1);
  
  return 0;
}