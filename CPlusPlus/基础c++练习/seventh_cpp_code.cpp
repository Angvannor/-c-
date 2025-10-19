#include <iostream>

using namespace std;

int main(){
  int score;
  cout << "这是一个根据成绩的分级系统" << endl << "请输入成绩：";
  cin >> score;
  if(score < 0 || score > 100){
    cout << "输入错误，成绩应在0到100之间。" << endl;
  }else if(score >= 90){
    cout << "等级：A" << endl;
  }else if(score >= 80){
    cout << "等级：B" << endl;
  }else if(score >= 70){
    cout << "等级：C" << endl;
  }else if(score >= 60){
    cout << "等级：D" << endl;
  }else{
    cout << "等级：E" << endl;
  }
  return 0;
}