#include <bits/stdc++.h>
using namespace std;

bool solve(string s) {
    sort(s.begin(), s.end());
    for (int i = 0; i < s.size() - 1; i++)
        if (tolower(s[i]) == tolower(s[i + 1])) return false;

    return true;
}

int main() {
    assert(solve("abc") == true);
    assert(solve("Aabc") == false);
    assert(solve("bcdeb") == false);
    return 0;
}
