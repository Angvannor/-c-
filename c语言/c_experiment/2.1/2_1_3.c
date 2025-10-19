#include <stdio.h>

// 2.1.3(1)
int sum(int x,int y){
  int z;
  z = x + y;
  return(z);
}

int main(){
  // 2.1.3(2)
  int a2,b2,c2;
  printf("Input two integers(a b):\n");
  scanf("%d %d",&a2,&b2);
  c2 = sum(a2,b2);
  printf("sum = %d + %d = %d\n",a2,b2,c2);

  return 0;
}