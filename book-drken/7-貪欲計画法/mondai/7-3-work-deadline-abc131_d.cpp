#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// (所要時間, 締め切り) のペア
using pll = pair<long long, long long>;

bool comp(Point a, Point b) {
    if (a.second != b.second) {
        return a.second < b.second;
    } else {
        return a.first > b.first;
    }
}

int main() {
    // 入力
    int N;
    cin >> N;
    vector<pll> v(N);
    for (int i = 0; i < N; ++i) cin >> v[i].first >> v[i].second;

    // 締め切りが早い順にソート
    sort(v.begin(), v.end(), [&](pll a, pll b) { return a.second < b.second; });

    // 締め切りが早い順に仕事をこなしていく
    bool ok = true;
    long long time = 0;
    for (int i = 0; i < N; ++i) {
        time += v[i].first;
        if (time > v[i].second) ok = false;
    }

    // 出力
    if (ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
