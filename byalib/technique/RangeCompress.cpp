#include <bits/stdc++.h>
using namespace std;

map<long long, int> zip;
map<int, long long> unzip;
/*
    座標圧縮
    [zip] 6, 9, 9, 2, 100 -> [unzip] 1, 2, 2, 0, 3
 */
int compress(vector<long long>& x) {
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    for (int i = 0; i < x.size(); i++) {
        zip[x[i]] = i;
        unzip[i] = x[i];
    }
    return x.size();
}

int main() {
    vector<long long> a({10, 100, 2, 1, 100000});

    // 座標圧縮
    compress(a);

    // print
    cout << "ZIP:" << endl;
    for (auto [k, v] : zip) {
        cout << k << ":" << v << endl;
    }

    cout << "UNZIP:" << endl;
    for (auto [k, v] : unzip) {
        cout << k << ":" << v << endl;
    }

    return 0;
}
