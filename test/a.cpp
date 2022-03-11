#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()
#define PI 3.14159265358979323846264338327950288
typedef long long ll;
typedef vector<int> vi;

int is123Array(int a[], int len) {
    if (len < 3 or len % 3 != 0) {
        return 0;
    }

    for (int i = 0; i < len; i += 3) {
        if (a[i] == 1 and a[i + 1] == 2 and a[i + 2] == 3)
            continue;
        else
            return 0;
    }

    return 1;
}

void solve() {
    // in
    int a[] = {1, 2, 3, 3, 2, 1};
    cout << is123Array(a, sizeof(a) / sizeof(*a)) << endl;
}

int main() {
    // make input and output more efficient
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
