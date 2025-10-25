#include <iostream>
#include <string>

using namespace std;

class Student {
  private:
    string name;
    string gender;
    int age;
    string address;
    double totalScore;

  public:
    Student() {
        name = "未知";
        gender = "未知";
        age = 0;
        address = "未知";
        totalScore = 0.0;
        cout << "默认构造函数被调用。" << endl;
    }

    // 带全部参数的构造函数
    Student(string n, string g, int a, string addr, double score) {
        name = n;
        gender = g;
        age = a;
        address = addr;
        totalScore = score;
        cout << "带全部参数的构造函数被调用。" << endl;
    }

    // 带部分参数的构造函数
    Student(string n, int a, double score) {
        name = n;
        gender = "未知";
        age = a;
        address = "未知";
        totalScore = score;
        cout << "带部分参数的构造函数被调用。" << endl;
    }

    // ? 修复后的带默认值构造函数（只接收一个参数）
    Student(string n) {
        name = n;
        gender = "女";
        age = 18;
        address = "北京";
        totalScore = 80.0;
        cout << "带默认参数的构造函数被调用。" << endl;
    }

    ~Student() {
        cout << "析构函数被调用，销毁对象：" << name << endl;
    }

    void show() {
        cout << "------------------" << endl;
        cout << "姓名：" << name << endl;
        cout << "性别：" << gender << endl;
        cout << "年龄：" << age << endl;
        cout << "住址：" << address << endl;
        cout << "总成绩：" << totalScore << endl;
        cout << "------------------" << endl;
    }
};

int main() {
    Student s1;
    Student s2("张三", "男", 20, "上海", 90.5);
    Student s3("李四", 21, 88.0);
    Student s4("王五");

    s1.show();
    s2.show();
    s3.show();
    s4.show();

    return 0;
}
