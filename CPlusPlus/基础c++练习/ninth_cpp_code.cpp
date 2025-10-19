#include <iostream>

using namespace std;

int print_multification_table(){
  for(int i = 1;i <= 9;i++){
    for(int j = 1;j <= i;j++){
      cout << j << "*" << i << "=" << i*j << " ";
    }
    cout << endl;
  }
}

int main(){
  print_multification_table();
  return 0;
}