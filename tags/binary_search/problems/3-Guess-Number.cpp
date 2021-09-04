#include <bits/stdc++.h>
using namespace std;

int pick;

int guess(int num) {
    if (pick == num) return 0;
    if (num > pick)
        return -1;
    else
        return 1;
}

template <class T>
int binarySearchGuess(T n) {
    int l = 1, r = n;

    while (r >= l) {
        // prevent overflow
        int mid = l + (r - l) / 2;
        int res = guess(mid);
        if (res == 0) return mid;
        if (res == 1)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return l;
}

void solve() {
    // in
    pick = 6;
    cout << binarySearchGuess(10) << endl;
}

// https://leetcode.com/problems/guess-number-higher-or-lower/
// binary search
int main() {
    solve();
    return 0;
}
