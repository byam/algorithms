#include <bits/stdc++.h>
using namespace std;
#define rep(n) for (int i = 0; i < (n); i++)
#define printv(v)                          \
    for (int i = 0; i < (v.size()); i++) { \
        cout << v[i] << " ";               \
    }                                      \
    cout << endl;

int main() {
    vector<int> v(4);
    rep(4) v[i] = i;
    cout << accumulate(v.begin(), v.end(), v.size()) << endl;
    printv(v);
    return 0;
}
