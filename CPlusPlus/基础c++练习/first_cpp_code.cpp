#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(nullptr));
    int target = rand() % 100 + 1;
    int guess = 0;
    int attempts = 0;

    cout << "����һ��������С��Ϸ��\n������һ�� 1 �� 100 ֮���������" << endl;

    do {
        cout << "��������Ĳ²⣺" << endl;
        cin >> guess;
        attempts++;

        if (guess > target) {
            cout << "���ˣ����ٲ�һ�顣" << endl;
        } else if (guess < target) {
            cout << "С�ˣ����ٲ�һ�顣" << endl;
        } else {
            cout << "��¶��ˣ�����" << endl;
            cout << "����� " << attempts << " �Ρ�" << endl;
        }
    } while (guess != target);

    return 0;
}
