#include <iostream>
#include <vector>
using namespace std;

// ref: https://drken1215.hatenablog.com/entry/2019/12/14/171657

int main() {
    // 入力
    vector<char> a({'a', 'b', 'c'});
    int N = a.size();

    // bit 全探索
    bool exist = false;
    for (int bit = 0; bit < (1 << N); ++bit) {
        // どれを選ぶか
        vector<int> S;
        for (int i = 0; i < N; ++i) {
            if (bit & (1 << i)) {
                S.push_back(i);
            }
        }

        // 部分集合に対応する
        string s = "";
        for (int i : S) s += a[i];

        // 部分集合を表示
        printf("%d: %s\n", bit + 1, s.c_str());
    }
}
