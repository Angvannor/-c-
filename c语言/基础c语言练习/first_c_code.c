#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
  srand (time(NULL));
  int target = rand()%100+1;
  int guess;
  int attempts = 0;

  printf("����һ��������С��Ϸ��\n");
  printf("������һ��1��100֮���������\n");

  do{
    printf("��������Ĳ²⣺");
    scanf("%d",&guess);
    attempts++;

    if(guess>target){
       printf("���ˣ����ٲ�һ�顣\n");
    }else if(guess<target){
      printf("С�ˣ����ٲ�һ�顣\n");
    }else{
      printf("��¶��ˣ�����\n�����%d��",attempts);
    }
  }while (guess!=target);

  return 0;
}