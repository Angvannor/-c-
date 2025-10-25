#include <iostream>

using namespace std;

class rectangle {
  private:
    double length;
    double width;
  public:
    void setLength(double len) {
        length = len;
    }

    void setWidth(double wid) {
        width = wid;
    }

    double getCircumference() {
        return 2 * (length + width);
    }

    double getArea() {
        return length * width;
    }
};

int main(){
    rectangle rect;
    double len, wid;

    cout << "请输入矩形的长度: ";
    cin >> len;
    rect.setLength(len);

    cout << "请输入矩形的宽度: ";
    cin >> wid;
    rect.setWidth(wid);

    cout << "矩形的周长为: " << rect.getCircumference() << endl;
    cout << "矩形的面积为: " << rect.getArea() << endl;

    return 0;
}