#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(nullptr));
    int target = rand() % 100 + 1;
    int guess = 0;
    int attempts = 0;

    cout << "这是一个猜数字小游戏。\n请输入一个 1 到 100 之间的整数。" << endl;

    do {
        cout << "请输入你的猜测：" << endl;
        cin >> guess;
        attempts++;

        if (guess > target) {
            cout << "大了，请再猜一遍。" << endl;
        } else if (guess < target) {
            cout << "小了，请再猜一遍。" << endl;
        } else {
            cout << "你猜对了！！！" << endl;
            cout << "你猜了 " << attempts << " 次。" << endl;
        }
    } while (guess != target);

    return 0;
}
