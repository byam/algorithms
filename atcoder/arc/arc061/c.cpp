#include <bits/stdc++.h>
using namespace std;

int64_t sum = 0;

void dfs(int64_t x, int64_t add) {
    sum += x + add;
    for (int64_t i = 10; i < x; i *= 10) {
        dfs(x / i, add + x % i);
    }
}

int main() {
    int64_t n;
    cin >> n;

    dfs(n, 0);

    cout << sum << endl;
    return 0;
}
