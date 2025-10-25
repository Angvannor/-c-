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
        name = "δ֪";
        gender = "δ֪";
        age = 0;
        address = "δ֪";
        totalScore = 0.0;
        cout << "Ĭ�Ϲ��캯�������á�" << endl;
    }

    // ��ȫ�������Ĺ��캯��
    Student(string n, string g, int a, string addr, double score) {
        name = n;
        gender = g;
        age = a;
        address = addr;
        totalScore = score;
        cout << "��ȫ�������Ĺ��캯�������á�" << endl;
    }

    // �����ֲ����Ĺ��캯��
    Student(string n, int a, double score) {
        name = n;
        gender = "δ֪";
        age = a;
        address = "δ֪";
        totalScore = score;
        cout << "�����ֲ����Ĺ��캯�������á�" << endl;
    }

    // ? �޸���Ĵ�Ĭ��ֵ���캯����ֻ����һ��������
    Student(string n) {
        name = n;
        gender = "Ů";
        age = 18;
        address = "����";
        totalScore = 80.0;
        cout << "��Ĭ�ϲ����Ĺ��캯�������á�" << endl;
    }

    ~Student() {
        cout << "�������������ã����ٶ���" << name << endl;
    }

    void show() {
        cout << "------------------" << endl;
        cout << "������" << name << endl;
        cout << "�Ա�" << gender << endl;
        cout << "���䣺" << age << endl;
        cout << "סַ��" << address << endl;
        cout << "�ܳɼ���" << totalScore << endl;
        cout << "------------------" << endl;
    }
};

int main() {
    Student s1;
    Student s2("����", "��", 20, "�Ϻ�", 90.5);
    Student s3("����", 21, 88.0);
    Student s4("����");

    s1.show();
    s2.show();
    s3.show();
    s4.show();

    return 0;
}
