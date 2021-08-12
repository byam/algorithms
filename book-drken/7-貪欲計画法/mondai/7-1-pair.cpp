#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// (所要時間, 締め切り) のペア
using pll = pair<long long, long long>;

int main() {
    // 入力
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];

    // それぞれソートする
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // B を順に見ていく
    int i = 0;
    for (int j = 0; j < N; ++j) {
        if (A[i] < B[j]) ++i;
    }

    // i が答え
    cout << i << endl;
}
