#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 入力
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    // a をコピーした配列を作ってソートする
    auto b = a;
    sort(b.begin(), b.end());

    // 各 a について b の中で何番目か
    vector<int> res(N);
    for (int i = 0; i < N; ++i) {
        res[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    }

    // 出力
    for (int i = 0; i < N; ++i) cout << res[i] << endl;
}
