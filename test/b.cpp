#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()
#define PI 3.14159265358979323846264338327950288
typedef long long ll;
typedef vector<int> vi;

int isMartian(int a[], int len) {
    if (len < 1) return 0;

    // is same
    for (int i = 0; i < len - 1; i++) {
        if (a[i] == a[i + 1]) return 0;
    }

    // cnt 1s, 2s
    int one = 0;
    int two = 0;
    for (int i = 0; i < len; i++) {
        if (a[i] == 1) one++;
        if (a[i] == 2) two++;
    }

    return one > two;
}

void solve() {
    int a[] = {3};
    cout << isMartian(a, sizeof(a) / sizeof(*a)) << endl;
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
