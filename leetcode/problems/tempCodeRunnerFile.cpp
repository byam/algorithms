int minOperations(vector<vector<int>>& grid, int x) {
    vector<int> a, s;

    for (auto g : grid) {
        for (auto k : g) {
            a.push_back(k);
        }
    }

    sort(a.begin(), a.end());
    // out(a);

    int n = a.size();

    // sub min
    int mi = a[0];
    for (int i = 0; i < n; i++) {
        a[i] -= mi;
    }
    // out(a);

    // check it is possible
    for (int i = 1; i < n; i++) {
        if (a[i] % x != 0) return -1;
        a[i] /= x;
    };
    // out(a);

    // accum
    s.resize(n);
    for (int i = 1; i < n; i++) s[i] = s[i - 1] + a[i];
    // out(s);

    // find min ans
    int ans = s[n - 1];
    for (int i = 1; i < n; i++) {
        int lsum = s[i - 1];
        int rsum = s[n - 1] - s[i];
        int op = (a[i] * i - lsum) + (rsum - a[i] * (n - i - 1));

        // cout << lsum << " " << rsum << " " << op << endl;

        if (op < ans) ans = op;
    }
    return ans;
}
