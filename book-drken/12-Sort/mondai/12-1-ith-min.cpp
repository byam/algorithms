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

    // ソート
    auto b = a;
    sort(b.begin(), b.end());

    // 各要素について二分探索
    for (int i = 0; i < N; ++i) {
        cout << lower_bound(b.begin(), b.end(), a[i]) - b.begin() << endl;
    }
}
