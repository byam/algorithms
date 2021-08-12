#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 二次元座標を定義
using Point = pair<int, int>;

int main() {
    // 入力
    int N;
    cin >> N;
    vector<Point> red(N), blue(N);
    for (int i = 0; i < N; ++i) cin >> red[i].first >> red[i].second;
    for (int i = 0; i < N; ++i) cin >> blue[i].first >> blue[i].second;

    // 青い点を x 座標が小さい順にソートする (デフォルトで第一引数の辞書順比較)
    sort(blue.begin(), blue.end());

    // 各赤い点が使用済みかどうか
    vector<bool> used(N, false);

    // 青い点を順番に見ていく
    int res = 0;
    for (int i = 0; i < N; ++i) {
        // 使用済みでなく、y 座標最大の赤い点を探す
        int maxy = -1, maxid = -1;
        for (int j = 0; j < N; ++j) {
            // 使用済みの赤い点は不可
            if (used[j]) continue;

            // x 座標, y 座標がより大きい赤い点は不可
            if (red[j].first >= blue[i].first) continue;
            if (red[j].second >= blue[i].second) continue;

            // 最大値を更新
            if (maxy < red[j].second) {
                maxy = red[j].second;
                maxid = j;
            }
        }

        // 存在しない場合はスキップ
        if (maxid == -1) continue;

        // ペアリングする
        ++res;
        used[maxid] = true;
    }
    cout << res << endl;
}