#include <iostream>

using namespace std;

class Date{
private:
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
public:
    void setDate(int y, int m, int d, int h, int min, int s){
        year = y;
        month = m;
        day = d;
        hour = h;
        minute = min;
        second = s;
    }

    void showDate() const{
        cout << year << "��" << month << "��" << day << "��"
             << hour << "ʱ" << minute << "��" << second << "��" << endl;
    }
};

int main(){
  Date date;
  int y, m, d, h, min, s;
  cout << "������������Ϣ���� �� �� ʱ �� �룩: ";
  cin >> y >> m >> d >> h >> min >> s;
  date.setDate(y, m, d, h, min, s);
  date.showDate();
  return 0;
}