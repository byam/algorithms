
#include <bits/stdc++.h>
using namespace std;

// gcd of array
int findGCD(vector<int> &a) {
    int n = a.size();
    int result = a[0];
    for (int i = 0; i < n; i++) {
        result = gcd(a[i], result);

        if (result == 1) {
            return 1;
        }
    }
    return result;
}

// divisors of n
vector<int> findDivisors(int n) {
    vector<int> divs;

    int i;
    for (i = 1; i * i < n; i++) {
        if (n % i == 0) divs.push_back(i);
    }
    if (i - (n / i) == 1) {
        i--;
    }
    for (; i >= 1; i--) {
        if (n % i == 0) divs.push_back(n / i);
    }
    return divs;
}

// Driver code
int main() {
    // GCD
    vector<int> a = {2, 4, 6, 8, 16};
    cout << findGCD(a) << endl;

    // Divisors
    vector<int> divisors = findDivisors(100);
    for (auto d : divisors) cout << d << " ";
    cout << endl;
    return 0;
}
