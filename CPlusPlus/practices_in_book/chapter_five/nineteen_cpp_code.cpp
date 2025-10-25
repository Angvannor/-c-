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
      cout << "��������Ʒ���ƣ�" << endl;
      cin >> name;
      cout << "��������Ʒ�۸�" << endl;
      cin >> price;
      cout << "��������Ʒ�������ڣ��� �� �գ���" << endl;
      cin >> release_date[0] >> release_date[1] >> release_date[2];
      cout << "��������Ʒ�����ڣ��£���" << endl;
      cin >> expiry_date;
  }

  void showGoods();
};

void Good::showGoods(){
  cout << "��Ʒ���ƣ�" << name << endl;
  cout << "��Ʒ�۸�" << price << endl;
  cout << "��Ʒ�������ڣ�" 
       << release_date[0] << "��"
       << release_date[1] << "��"
       << release_date[2] << "������" << endl;
  cout << "��Ʒ�����ڣ�" << expiry_date << "����" << endl;
}


int main(){
  Good good;
  good.setGoods();
  good.showGoods();
  return 0;
}