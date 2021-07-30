// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int l, n;
        cin >> l >> n;

        int mi = 0, ma = 0;

        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        for (int i = 0; i < n; i++) {
            mi = max(mi, min(v[i], l - v[i]));
            ma = max(ma, max(v[i], l - v[i]));
        }

        cout << mi << " " << ma << endl;
    }

    return 0;
}
