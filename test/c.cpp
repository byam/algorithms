#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()
#define PI 3.14159265358979323846264338327950288
typedef long long ll;
typedef vector<int> vi;

int isRapidlyIncreasing(int a[], int len) {
    long long preSum = a[0];
    for (int i = 1; i < len; i++) {
        if (preSum * 2 < a[i])
            preSum += a[i];
        else
            return 0;
    }

    return 1;
}

void solve() {
    int a[] = {1, 3, 8, 26};
    cout << isRapidlyIncreasing(a, sizeof(a) / sizeof(*a)) << endl;
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
