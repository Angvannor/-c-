#include <iostream>

using namespace std;

int main(){
  int score;
  cout << "����һ�����ݳɼ��ķּ�ϵͳ" << endl << "������ɼ���";
  cin >> score;
  if(score < 0 || score > 100){
    cout << "������󣬳ɼ�Ӧ��0��100֮�䡣" << endl;
  }else if(score >= 90){
    cout << "�ȼ���A" << endl;
  }else if(score >= 80){
    cout << "�ȼ���B" << endl;
  }else if(score >= 70){
    cout << "�ȼ���C" << endl;
  }else if(score >= 60){
    cout << "�ȼ���D" << endl;
  }else{
    cout << "�ȼ���E" << endl;
  }
  return 0;
}