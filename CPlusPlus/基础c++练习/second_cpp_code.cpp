#include <iostream>

using namespace std;

int main(){
  float C;
  float F;
  int choice;

  cout << "华氏度和摄氏度的转换程序，请输入选择：" << endl << "1.华氏度转摄氏度" << endl << "2.摄氏度转华氏度" << endl;
  cin >> choice;
  if(choice == 1){
    cout << "这是一个华氏度转摄氏度的转换程序。" << endl << "请输入华氏温度：" << endl;
    cin >> F;
    
    C = (F - 32) * 5 / 9;
    cout << "摄氏温度为：" << C << endl;
  }else if(choice == 2){
    cout << "这是一个摄氏度转华氏度的转换程序。" << endl << "请输入摄氏温度：" << endl;
    cin >> C;
    
    F = C * 9 / 5 + 32;
    cout << "华氏温度为：" << F << endl;
  }

  return 0;
}