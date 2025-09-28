#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
  srand (time(NULL));
  int target = rand()%100+1;
  int guess;
  int attempts = 0;

  printf("这是一个猜数字小游戏。\n");
  printf("请输入一个1到100之间的整数。\n");

  do{
    printf("请输入你的猜测：");
    scanf("%d",&guess);
    attempts++;

    if(guess>target){
       printf("大了，请再猜一遍。\n");
    }else if(guess<target){
      printf("小了，请再猜一遍。\n");
    }else{
      printf("你猜对了！！！\n你猜了%d次",attempts);
    }
  }while (guess!=target);

  return 0;
}