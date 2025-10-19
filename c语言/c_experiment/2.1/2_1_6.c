#include <stdio.h>

int main(){
    // 2.1.6
  for(int i = 0;i < 5;i++){
    for(int j = 0;j < i;j++){
      printf("M");
    }
    printf("\n");
  }

  return 0;
}