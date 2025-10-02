#include <stdio.h>

int add(int a,int b){return a+b;}
int sub(int a,int b){return a-b;}

void calc(int x,int y,int (*op)(int,int)){
  printf("result:%d\n",op(x,y));
}

int main(){
  calc(5,3,add);
  calc(5,3,sub);

  return 0;
}