#include <stdio.h>

int main(){
   // 2.1.7
  for(int i = 0;i < 6;i++){
    int k = i <= 3 ? 2 * i - 1 : 2 * (6 - i) - 1;
    for(int j = 0;j < k;j++){
      printf("M");
    }
    printf("\n");
  }

  return 0;
}