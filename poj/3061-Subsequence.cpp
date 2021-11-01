#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;
typedef long long ll;

/*-----------------------------------
        Coding Starts Here
------------------------------------*/

void solve() {
    // in
    int n;
    ll x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = n + 1;

    int right = 0;
    ll sum = 0;
    for (int left = 0; left < n; left++) {
        // move right
        while (right < n and sum < x) {
            sum += a[right];
            right++;
        }

        if (sum < x) break;

        // update answer
        ans = min(ans, right - left);

        // corner
        if (left == right) right++;
        // move left
        else
            sum -= a[left];
    }

    if (ans == n + 1)
        cout << 0 << endl;
    else
        cout << ans << endl;
}

int main() {
    // make input and output more efficient
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
