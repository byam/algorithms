#include <bits/stdc++.h>
using namespace std;

template <class T>
int binarySearchSqrt(T x) {
    if (x <= 1) return x;

    int l = 0, r = x / 2;

    while (r >= l) {
        int mid = l + (r - l) / 2;
        long tmp = (long)mid * (long)mid;
        if (tmp == x) return mid;
        if (tmp < x)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return l - 1;
}

void solve() {
    cout << binarySearchSqrt(4) << endl;
    cout << binarySearchSqrt(8) << endl;
    cout << binarySearchSqrt(9) << endl;
}

int main() {
    solve();
    return 0;
}
