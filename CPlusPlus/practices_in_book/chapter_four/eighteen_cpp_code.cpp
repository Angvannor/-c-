#include<iostream>
using namespace std;

class Student{
  public:
    int chinese;
    int math;
    int english;
};

float cal_student_average(Student student){
  return (student.chinese + student.math + student.english) / 3.0;
}

float cal_class_average(Student students[], int n){
  int total = 0;
  for(int i = 0; i < n; i++){
    total += (students[i].chinese + students[i].math + students[i].english);
  }
  return total / (n * 3.0);
}

int main(){
  int n;
  cout << "������ѧ��������" << endl;
  cin >> n;

  Student students[n];  // ? ��������

  for(int i = 0; i < n; i++){
    cout << "������� " << i+1 << " ��ѧ�������ĳɼ���" << endl;
    cin >> students[i].chinese;
    cout << "��������ѧ�ɼ���" << endl;
    cin >> students[i].math;
    cout << "������Ӣ��ɼ���" << endl;
    cin >> students[i].english;

    float average = cal_student_average(students[i]);
    cout << "��ѧ����ƽ���ɼ�Ϊ��" << average << endl;
  }

  float class_average = cal_class_average(students, n);
  cout << "�༶��ƽ���ɼ�Ϊ��" << class_average << endl;

  return 0;
}
