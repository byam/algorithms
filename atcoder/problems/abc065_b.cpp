#include <bits/stdc++.h>

using namespace std;

// type
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef priority_queue<int> pqi;                              // greater
typedef priority_queue<int, vector<int>, greater<int>> pqli;  // less
typedef priority_queue<long long, vector<long long>, greater<long long>> pqlll;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

/*-----------------------------------
        Coding Starts Here
------------------------------------*/

void solve() {
    // in
    int N;
    cin >> N;

    vi A(N);
    vb seen(N);

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        --a;
        A[i] = a;
    }

    int ans = 0;

    int x = 0;
    while (true) {
        if (seen[x]) {
            ans = -1;
            break;
        }
        if (x == 1) {
            break;
        }

        seen[x] = true;
        ans++;
        x = A[x];
    }

    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
