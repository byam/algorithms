#include <bits/stdc++.h>
using namespace std;

int main() {
    srand((unsigned)time(NULL));

    // 例 1: 1 以上 6 以下のランダムな整数を出力する
    cout << rand() % 6 + 1 << endl;

    // 例 2: 90% の確率で "Yay!"、10% の確率で ":(" と出力する
    for (int i = 0; i < 10; i++)
    {
        if ( rand() % 10 <= 8) cout << "Yay!" << endl;
        else cout << ":(" << endl;
    }

    return 0;
}
