#include <bits/stdc++.h>
using namespace std;

const int MAX_LEN = 1000009;
long long N, A[MAX_LEN], B[MAX_LEN], C[MAX_LEN];

int main() {
    // in
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    for (int i = 0; i < N; i++) cin >> C[i];

    // sort increase
    sort(A, A + N);
    sort(B, B + N);
    sort(C, C + N);

    long long ans = 0;
    long long ubound_b[N];

    // find A[i]
    for (int j = 0; j < N; j++)
    {
        // corner case
        if ( A[N-1] < B[j]) {
            ubound_b[j] = N;
        }
        else {
            int ai = lower_bound(A, A + N, B[j]) - A;
            if (ai < N) {
                ubound_b[j] = ai;
            }
        }
    }

    // find C[k]
    for (int j = 0; j < N; j++)
    {
        int ck = upper_bound(C, C + N, B[j]) - C;
        if (ck < N) {
            ans += ubound_b[j] * (N - ck);
        }
    }

    // out
    cout << ans << endl;

    return 0;
}
