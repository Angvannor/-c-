#include <stdio.h>

int main(){
  // 1.transpose array
  int a[2][3]={
    {1,2,3},
    {4,5,6}
  };
  int b[3][2];

  printf("Original array:\n");
  for(int i = 0; i<2; i++){
    for(int j = 0; j<3; j++){
      printf("%d ",a[i][j]);
    }
    printf("\n");
  }

  printf("Transposed array:\n");
  for(int j = 0; j<3; j++){
   for(int i = 0; i<2; i++){
      b[j][i] = a[i][j] ;
      printf("%d ",b[j][i]);
    }
    printf("\n");
  }

  // 2. matrix multiplication
  int A[3][3]={
    {1,2,3},
    {4,5,6},
    {7,8,9}
  };

  int B[3][3]={
    {9,8,7},
    {6,5,4},
    {3,2,1}
  };
  int C[3][3]={0};  

  for(int i = 0; i<3; i++){
    for(int j = 0; j<3; j++){
      for(int k = 0; k<3; k++){
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }

  printf("Matrix multiplication result:\n");
  for(int i = 0; i<3; i++){
    for(int j = 0; j<3; j++){
      printf("%d ",C[i][j]);
    }
    printf("\n");
  }

  return 0;
}