#include<iostream>

using namespace std;

class Cylinder{
  private:
    float radius;
    float height;

  public:
    void setData(){
      cout << "������Բ���İ뾶��" << endl;
      cin >> radius;
      cout << "������Բ���ĸ߶ȣ�" << endl;
      cin >> height;
    }

    void calSurfaceArea(){
      float surface_area = 2 * radius * height + 2 * 3.14 * radius * radius;
      cout << "Բ���ı����Ϊ��" << surface_area << endl;
    }

    void calVolume(){
      float volume = 3.14 * radius * radius * height;
      cout << "Բ�������Ϊ��" << volume << endl;
    }
};

int main(){
  Cylinder cylinder;
  cylinder.setData();
  cylinder.calSurfaceArea();
  cylinder.calVolume();
  return 0;
}