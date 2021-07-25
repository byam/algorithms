#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    pair<int, string> a[100009];

    // 例 1: N 人の成績と名前を入力して、成績の大きい順にソートする
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i].second; // 名前を入力する
        cin >> a[i].first; // 成績を入力する
    }
    sort(a, a + N, greater<pair<int, string>>());
    for (int i = 0; i < N; i++) {
        cout << "Name = " << a[i].second << ", Score = " << a[i].first << endl;
    }

    return 0;
}
