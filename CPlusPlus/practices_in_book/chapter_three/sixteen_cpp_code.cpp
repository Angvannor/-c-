#include<iostream>

using namespace std;

int main(){
  cout << "请输入三位数的范围：" << endl;
  int start, end;
  cin >> start >> end;

  if(start < 100 || end > 999 || start >= end){
    cout << "输入范围有误，请重新输入！" << endl;
    return 1;
  }

  for(int i = start;i <= end;i++){
    int hundred = i / 100;
    int ten = (i / 10) % 10;
    int unit = i % 10;
    if(i == hundred * hundred * hundred + ten * ten * ten + unit * unit * unit){
      cout << i << "是水仙花数！" << endl;
    } else{
      continue;
    }
  }

  return 0;
}