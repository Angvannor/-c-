#include <iostream>

using namespace std;

void counter(){
  static int count = 0;
  count++;
  cout << "函数被调用了" << count << "次" << endl;
}

int main(){
  counter();
  counter();
  counter();

  return 0;
}