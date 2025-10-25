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
        cout << year << "年" << month << "月" << day << "日"
             << hour << "时" << minute << "分" << second << "秒" << endl;
    }
};

int main(){
  Date date;
  int y, m, d, h, min, s;
  cout << "请输入日期信息（年 月 日 时 分 秒）: ";
  cin >> y >> m >> d >> h >> min >> s;
  date.setDate(y, m, d, h, min, s);
  date.showDate();
  return 0;
}