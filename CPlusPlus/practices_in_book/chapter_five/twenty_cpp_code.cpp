#include <iostream>
#include "worker.h"

using namespace std;

void Worker::setWorker(){
  cout << "������Ա��������" << endl;
  cin >> name;
  cout << "������Ա���Ա�" << endl;
  cin >> gender;  
  cout << "������Ա�����䣺" << endl;
  cin >> age;
  cout << "������Ա����ַ��" << endl;
  cin >> address;
  cout << "������Ա��нˮ��" << endl;
  cin >> salary;
}

void Worker::printWorker(){
  cout << "Ա��������" << name << endl;
  cout << "Ա���Ա�" << gender << endl;
  cout << "Ա�����䣺" << age << endl;
  cout << "Ա����ַ��" << address << endl;
  cout << "Ա��нˮ��" << salary << endl;
}

int main(){
  Worker worker;
  worker.setWorker();
  worker.printWorker();
  return 0;
}