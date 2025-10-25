#include<iostream>

using namespace std;

class Cylinder{
  private:
    float radius;
    float height;

  public:
    void setData(){
      cout << "请输入圆柱的半径：" << endl;
      cin >> radius;
      cout << "请输入圆柱的高度：" << endl;
      cin >> height;
    }

    void calSurfaceArea(){
      float surface_area = 2 * radius * height + 2 * 3.14 * radius * radius;
      cout << "圆柱的表面积为：" << surface_area << endl;
    }

    void calVolume(){
      float volume = 3.14 * radius * radius * height;
      cout << "圆柱的体积为：" << volume << endl;
    }
};

int main(){
  Cylinder cylinder;
  cylinder.setData();
  cylinder.calSurfaceArea();
  cylinder.calVolume();
  return 0;
}