#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 無限大を表す値
const long long INF = 1LL << 50;

/*
URL: http://poj.org/problem?id=2456

Point: Binary Search の応用例最適化問題の判定

 */

int main() {
    // 入力
    int N, M;
    cin >> N >> M;
    vector<long long> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    sort(a.begin(), a.end());

    // 「すべての間隔を x 以上にして M
    // 個の小屋を選べるか？」という判定問題を解く Yes であるような最大の x
    // を求める
    long long left = 0, right = INF;
    while (right - left > 1) {
        long long x = (left + right) / 2;

        int cnt = 1;  // 何個の小屋が取れたか (最初の小屋は選ぶ)
        int prev = 0;  // 前回の小屋の index
        for (int i = 0; i < N; ++i) {
            // x 以上の間隔が空いたら採用する
            if (a[i] - a[prev] >= x) {
                ++cnt;
                prev = i;
            }
        }

        // 判定問題が Yes か No か
        if (cnt >= M)
            left = x;
        else
            right = x;
    }
    cout << left << endl;
}
