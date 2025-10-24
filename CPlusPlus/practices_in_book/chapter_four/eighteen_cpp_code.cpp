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
  cout << "请输入学生人数：" << endl;
  cin >> n;

  Student students[n];  // ? 定义数组

  for(int i = 0; i < n; i++){
    cout << "请输入第 " << i+1 << " 个学生的语文成绩：" << endl;
    cin >> students[i].chinese;
    cout << "请输入数学成绩：" << endl;
    cin >> students[i].math;
    cout << "请输入英语成绩：" << endl;
    cin >> students[i].english;

    float average = cal_student_average(students[i]);
    cout << "该学生的平均成绩为：" << average << endl;
  }

  float class_average = cal_class_average(students, n);
  cout << "班级的平均成绩为：" << class_average << endl;

  return 0;
}
