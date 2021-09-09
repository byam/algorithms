#include <bits/stdc++.h>
using namespace std;

string shiftingLetters(string s, vector<int>& shifts) {
    // [3,5,9] -> [17,14,9]
    int n = s.length();
    for (int i = n - 1; i >= 0; i--) {
        if (i < n - 1) shifts[i] += shifts[i + 1];
        shifts[i] %= 26;
    }

    for (int i = 0; i < n; i++) {
        s[i] = (char)(((s[i] - 'a') + shifts[i]) % 26 + 97);
    }
    return s;
}

int main() {
    vector<int> shifts({1, 2, 3});
    cout << shiftingLetters("aaa", shifts) << endl;

    vector<int> shifts2({3, 5, 9});
    cout << shiftingLetters("abc", shifts2) << endl;

    vector<int> shifts3({26, 9, 17});
    cout << shiftingLetters("ruu", shifts3) << endl;

    return 0;
}
