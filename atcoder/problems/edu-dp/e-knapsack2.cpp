#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define fore(i, a) for (auto &i : a)
#define all(x) (x).begin(), (x).end()
//#pragma GCC optimize ("-O3")
using namespace std;
void _main();
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    _main();
}
typedef long long ll;
const int inf = INT_MAX / 2;
const ll infl = 1LL << 60;
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
//---------------------------------------------------------------------------------------------------
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/

int N, W, w[101], v[101];
int dp[101][201010];
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> W;
    rep(i, 0, N) cin >> w[i] >> v[i];

    rep(i, 0, N + 1) rep(val, 0, N * 1010 + 1) dp[i][val] = inf;
    dp[0][0] = 0;

    rep(i, 0, N) rep(val, 0, N * 1010 + 1) {
        chmin(dp[i + 1][val], dp[i][val]);
        chmin(dp[i + 1][val + v[i]], dp[i][val] + w[i]);
    }

    int ans = 0;
    rep(val, 0, N * 1010 + 1) if (dp[N][val] <= W) chmax(ans, val);
    cout << ans << endl;
}
