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

    cout << "��������εĳ���: ";
    cin >> len;
    rect.setLength(len);

    cout << "��������εĿ��: ";
    cin >> wid;
    rect.setWidth(wid);

    cout << "���ε��ܳ�Ϊ: " << rect.getCircumference() << endl;
    cout << "���ε����Ϊ: " << rect.getArea() << endl;

    return 0;
}