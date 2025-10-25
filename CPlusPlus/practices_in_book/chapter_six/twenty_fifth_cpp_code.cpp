#include <iostream>

using namespace std;

class Date {
  private:
    int month;
    int day;
    int year;

  public:
    Date(int m, int d, int y) : month(m), day(d), year(y) {
        cout << "�������Ĺ��캯�������ã�����Date����" << endl;
    }

    void defaultDate(){
        month = 1;
        day = 1;
        year = 2000;
    }  

    void setDate(int m, int d, int y) {
        month = m;
        day = d;
        year = y;
    }

    void displayDate() {
        cout << year << "/" << month << "/" << day << endl;
    }

    ~Date() {
        cout << "�������������ã�����Date����" << endl;
    }
};

int main(){
  Date dates[3] = {
    Date(3, 15, 2024),
    Date(7, 4, 2024),
    Date(12, 25, 2024)
  };
  for (int i = 0; i < 3; ++i) {
      dates[i].displayDate();
  }
  return 0;
}