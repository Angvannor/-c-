#include <stdio.h>

int main(){
  int ownMoney = 1000;
  int saveMoney = 1000;
  int inputMoney = 0;
  int takeMoney = 0;
  int choice,operation = 1;

  printf("��ӭʹ��ATM��ȡ��ϵͳ��\n");
  
  
  do{
    printf("��ѡ��������ͣ�1.��� 2.ȡ��\n");
    printf("��ǰ�˻���%d\n", ownMoney);
    printf("��ǰ�����%d\n", saveMoney);
    scanf("%d", &choice);

    if(choice == 1){
    printf("���������");
    scanf("%d",&inputMoney);
    if(inputMoney > ownMoney){
      printf("���㣬�޷���\n");
    }else{
      saveMoney += inputMoney;
      ownMoney -= inputMoney;
      printf("���ɹ�!\n");
    } 
  }else if(choice == 2){
    printf("������ȡ���");
    scanf("%d",&takeMoney);
    if(takeMoney > saveMoney){
      printf("���㣬�޷�ȡ�\n");
    }else{
      saveMoney -= takeMoney;
      ownMoney += takeMoney;
      printf("ȡ��ɹ�!\n");
    }
  }else{
    printf("���������������\n");
  }
  printf("�Ƿ����������1.�� 2.��\n");
    scanf("%d", &operation);
    if(operation == 2){
      printf("��лʹ��ATM��ȡ��ϵͳ��\n");
      break;
    }else if(operation != 1 && operation != 2){
      printf("���������������\n");
      break;
    }
}while(operation == 1);
  
  return 0;
}