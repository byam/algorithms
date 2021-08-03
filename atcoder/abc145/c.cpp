#include <bits/stdc++.h>
using namespace std;

int N;
int x[10], y[10];

double dist(int i, int j) {
    double dx = x[i] - x[j];
    double dy = y[i] - y[j];
    return pow(dx * dx + dy * dy, 0.5);
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> x[i] >> y[i];

    double sum = 0.0;

    vector<int> v(N);
    for (int i = 0; i < N; i++) v[i] = i + 1;

    do {
        for (int i = 0; i < N - 1; i++) sum += dist(v[i], v[i + 1]);
    } while (next_permutation(v.begin(), v.end()));

    int Factorial = 1;
    for (int i = 2; i <= N; i++) Factorial *= i;

    cout << fixed << setprecision(10) << sum / Factorial << endl;
    return;
}

int main() {
    solve();
    return 0;
}
