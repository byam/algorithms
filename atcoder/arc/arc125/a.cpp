#include <bits/stdc++.h>
using namespace std;
int main() {
    // IN
    int N, M;
    cin >> N >> M;
    vector<int> S(N), T(M);
    for (auto& s : S) cin >> s;
    for (auto& t : T) cin >> t;

    // diff 0 and 1 in S
    int mdf = N;
    for (int i = 0; i < N; i++)
        if (S[i] != S[0]) mdf = min(mdf, min(i, N - i));

    // first letter
    int chs = 0;
    if (T[0] != S[0]) chs++;

    // all
    for (int i = 0; i < M - 1; i++)
        if (T[i] != T[i + 1]) chs++;

    // OUT
    if (!chs)
        cout << M << endl;
    else if (mdf >= N)
        puts("-1");
    else
        cout << mdf + chs + M - 1 << endl;
    return 0;
}
