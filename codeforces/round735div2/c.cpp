#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        long long n, m;
        vector<long long> v;

        // in
        cin >> n >> m;

        // logic
        bitset<2000> N(n);

        for (int i = 0; i <= m; i++) {
            bitset<2000> M(i);
            v.push_back((N ^ M).to_ulong());
        }

        sort(v.begin(), v.begin() + m + 1);

        for (long long i = 0; i <= m; i++) {
            if (i != v[i]) {
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}
