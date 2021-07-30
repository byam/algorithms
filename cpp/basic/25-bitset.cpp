#include <bits/stdc++.h>
using namespace std;

// int 型を「どのアイテムを選ぶのか」を表す vector<int> 型に変換
// bit: 集合を表す整数
// N: 何個のものについて考えているか
vector<int> IntegerToVector(int bit, int N) {
    vector<int> S;
    for (int i = 0; i < N; ++i) {
        if (bit & (1 << i)) {
            S.push_back(i);
        }
    }
    return S;
}

int main() {
    for (auto i : IntegerToVector(13, 5)) std::cout << i << ' ';
    cout << endl;

    return 0;
}
