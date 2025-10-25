#include <iostream>
#include "worker.h"

using namespace std;

void Worker::setWorker(){
  cout << "请输入员工姓名：" << endl;
  cin >> name;
  cout << "请输入员工性别：" << endl;
  cin >> gender;  
  cout << "请输入员工年龄：" << endl;
  cin >> age;
  cout << "请输入员工地址：" << endl;
  cin >> address;
  cout << "请输入员工薪水：" << endl;
  cin >> salary;
}

void Worker::printWorker(){
  cout << "员工姓名：" << name << endl;
  cout << "员工性别：" << gender << endl;
  cout << "员工年龄：" << age << endl;
  cout << "员工地址：" << address << endl;
  cout << "员工薪水：" << salary << endl;
}

int main(){
  Worker worker;
  worker.setWorker();
  worker.printWorker();
  return 0;
}