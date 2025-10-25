#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Good{
private:
    char name[20];
    float price;
    int release_date[3];
    int expiry_date;
public:
  Good(){
    name[0] = '\0';
    price = 0.0f;
    release_date[0] = 0;
    release_date[1] = 0;
    release_date[2] = 0;
    expiry_date = 0;
  }

  Good(string n, float p, int r_date[3], int e_date){
    strncpy(name, n.c_str(), 19);
    name[19] = '\0';
    price = p;
    release_date[0] = r_date[0];
    release_date[1] = r_date[1];
    release_date[2] = r_date[2];
    expiry_date = e_date;
  }  

    void setGoods(){
      cout << "请输入商品名称：" << endl;
      cin >> name;
      cout << "请输入商品价格：" << endl;
      cin >> price;
      cout << "请输入商品生产日期（年 月 日）：" << endl;
      cin >> release_date[0] >> release_date[1] >> release_date[2];
      cout << "请输入商品保质期（月）：" << endl;
      cin >> expiry_date;
  }

  void showGoods();
};

void Good::showGoods(){
  cout << "商品名称：" << name << endl;
  cout << "商品价格：" << price << endl;
  cout << "商品生产日期：" 
       << release_date[0] << "年"
       << release_date[1] << "月"
       << release_date[2] << "日生产" << endl;
  cout << "商品保质期：" << expiry_date << "个月" << endl;
}


int main(){
  Good good;
  good.setGoods();
  good.showGoods();
  return 0;
}