#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

int insert(){
  FILE *file;
  file = fopen("insert_sqrt.dat", "w");
  if(file == NULL){
    cout << "�޷����ļ���" << endl;
    return 0;
  }
  else{
    for(int i = 1; i <= 10; i++){
      fprintf(file, "%d %.2f\n", i, sqrt(i));
    }
  }
  fclose(file);
  return 0;
}

int main(){
  insert();
  return 0;
}