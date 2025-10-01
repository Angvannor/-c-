#include <stdio.h>

void increment(int *p){
  (*p)++;
}

int swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}

int main(){
    int x = 5;
    int y = 10;
    printf("Before swap:\n");
    printf("x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("After swap:\n");
    printf("x = %d, y = %d\n", x, y);
    increment(&x);
    printf("After incrementing x:\n");
    printf("x = %d\n", x);
    return 0;
}

