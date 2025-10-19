#include <iostream>

using namespace std;

int main(){
  int day;
  cout << "这是一个课表查询系统" << endl << "请输入星期几(1-7): ";
  cin >> day;
  switch(day){
    case 1:cout << "1-2节：无课" << endl << "3-4节：C语言程序设计" << endl << "5-6节：雅思英语" << endl << "7-8节：高等数学" << endl;
    break;
    case 2:cout << "1-2节：雅思英语" << endl << "3-4节：体育" << endl << "5-6节：思想道德与法治" << endl << "7-8节：无课" << endl;
    break;
    case 3:cout << "1-2节：高等数学" << endl << "3-4节：雅思英语" << endl << "5-6节：无课" << endl << "7-8节：无课" << endl;
    break;
    case 4:cout << "1-2节：雅思英语" << endl << "3-4节：C语言程序设计" << endl << "5-6节：软件技术基础" << endl << "7-8节：无课" << endl;
    break;
    case 5:cout << "1-2节：无课" << endl << "3-4节：无课" << endl << "5-6节：思想道德与法治" << endl << "7-8节：高等数学" << endl;
    break;
    case 6:cout << "1-2节：无课" << endl << "3-4节：无课" << endl << "5-6节：无课" << endl << "7-8节：国家安全与军事理论" << endl;
    break;
    case 7:cout << "1-2节：无课" << endl << "3-4节：无课" << endl << "5-6节：无课" << endl << "7-8节：国家安全与军事理论" << endl;
    break;
    default:cout << "输入错误，请输入1到7之间的数字。" << endl;
  }

  return 0;
}