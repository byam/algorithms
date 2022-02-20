#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int n;
vector<int> c, ans;

void solve(int t) {
    cin >> n;

    // refresh
    c.resize(n), ans.resize(n);

    rep(i, n) cin >> c[i];

    // min heap
    priority_queue<int, vector<int>, greater<int>> q;
    int h = 0;
    rep(i, n) {
        ans[i] = h;
        if (c[i] > h) q.push(c[i]);
        if (q.size() > h) {
            h++;
            ans[i] = h;
            while (!q.empty()) {
                if (q.top() > h) break;
                q.pop();
            }
        }
    }

    printf("Case #%d: ", t);
    rep(i, n) { cout << ans[i] << " "; }
    cout << endl;
}

int main() {
    int t = 1;
    cin >> t;
    int i = 1;
    while (i <= t) {
        solve(i);
        i++;
    }
}
