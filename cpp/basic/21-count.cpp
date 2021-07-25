#include <bits/stdc++.h>
using namespace std;

int main() {
    // 例 1: 配列 a に含まれる 1 の個数、2 の個数を出力する（それぞれ　4, 3 と出力されます）
    int a[10] = {1, 2, 3, 4, 1, 2, 3, 1, 2, 1};
    cout << count(a, a + 10, 1) << endl;
    cout << count(a, a + 10, 2) << endl;

    // 例 2: b[1], b[2], ..., b[N] を受け取り、その後 Q 個の質問を受け取る。
    // 各質問に対し、b[l], b[l+1], ..., b[r] の中で x が何個あるかを出力する。
    int b[1009], N, Q;
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> b[i];
    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        cout << count(b + l, b + r + 1, x) << endl;
    }

    return 0;
}
