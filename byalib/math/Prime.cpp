
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

// A function to print all prime factors of a given number n
vector<int> primeFactors(int n) {
    vector<int> f;

    // Print the number of 2s that divide n
    while (n % 2 == 0) {
        f.push_back(2);
        n = n / 2;
    }

    // n must be odd at this point.  So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        // While i divides n, print i and divide n
        while (n % i == 0) {
            f.push_back(i);
            n = n / i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2) f.push_back(n);

    return f;
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
