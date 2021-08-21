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
    int N, M;
    cin >> N >> M;
    vi S(M), C(M), A(N, 0);
    for (int i = 0; i < M; i++) {
        int s, c;
        cin >> s >> c;
        --s;
        S[i] = s;
        C[i] = c;
    }

    int left = pow(10, N - 1);
    int right = pow(10, N) - 1;

    if (N == 1) {
        left = 0;
        right = 9;
    }

    for (int i = left; i <= right; i++) {
        string str = to_string(i);

        bool ok = true;
        for (int j = 0; j < M; j++) {
            if (str[S[j]] != C[j] + '0') {
                ok = false;
            }
        }

        if (ok) {
            cout << i << endl;
            return;
        }
    }

    cout << -1 << endl;
    return;
}

int main() {
    solve();
    return 0;
}
