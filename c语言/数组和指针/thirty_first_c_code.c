#include <stdio.h>

int main(){
  char menu_1[3][20] = {
    "1. Start",
    "2. Settings",
    "3. Exit"
  };

  printf("menu_1:\n");
  for (int i = 0; i < 3; i++){
    printf("%s\n",menu_1[i]);
  }

  char *menu_2[] = {
    "1. Start",
    "2. Settings",
    "3. Exit",
    NULL
  };

  printf("menu_2:\n");
  for (int i = 0; menu_2[i] != NULL; i++){
    printf("%s\n",menu_2[i]);
  }

  return 0;
}