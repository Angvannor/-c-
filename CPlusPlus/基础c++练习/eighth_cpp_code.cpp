#include <iostream>

using namespace std;

int main(){
  int day;
  cout << "����һ���α��ѯϵͳ" << endl << "���������ڼ�(1-7): ";
  cin >> day;
  switch(day){
    case 1:cout << "1-2�ڣ��޿�" << endl << "3-4�ڣ�C���Գ������" << endl << "5-6�ڣ���˼Ӣ��" << endl << "7-8�ڣ��ߵ���ѧ" << endl;
    break;
    case 2:cout << "1-2�ڣ���˼Ӣ��" << endl << "3-4�ڣ�����" << endl << "5-6�ڣ�˼������뷨��" << endl << "7-8�ڣ��޿�" << endl;
    break;
    case 3:cout << "1-2�ڣ��ߵ���ѧ" << endl << "3-4�ڣ���˼Ӣ��" << endl << "5-6�ڣ��޿�" << endl << "7-8�ڣ��޿�" << endl;
    break;
    case 4:cout << "1-2�ڣ���˼Ӣ��" << endl << "3-4�ڣ�C���Գ������" << endl << "5-6�ڣ������������" << endl << "7-8�ڣ��޿�" << endl;
    break;
    case 5:cout << "1-2�ڣ��޿�" << endl << "3-4�ڣ��޿�" << endl << "5-6�ڣ�˼������뷨��" << endl << "7-8�ڣ��ߵ���ѧ" << endl;
    break;
    case 6:cout << "1-2�ڣ��޿�" << endl << "3-4�ڣ��޿�" << endl << "5-6�ڣ��޿�" << endl << "7-8�ڣ����Ұ�ȫ���������" << endl;
    break;
    case 7:cout << "1-2�ڣ��޿�" << endl << "3-4�ڣ��޿�" << endl << "5-6�ڣ��޿�" << endl << "7-8�ڣ����Ұ�ȫ���������" << endl;
    break;
    default:cout << "�������������1��7֮������֡�" << endl;
  }

  return 0;
}