#include <bits/stdc++.h>
using namespace std;

int main() {

    // 例 1: x を 2 進数表記したときに、1 であるビットの個数を出力する。
    long long x;
    cin >> x;
    cout << __builtin_popcountll(x) << endl;
    return 0;
}
