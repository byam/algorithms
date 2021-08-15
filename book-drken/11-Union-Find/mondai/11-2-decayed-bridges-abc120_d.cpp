#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct UnionFind {
    vector<int> par;

    UnionFind(int n) : par(n, -1) {}
    void init(int n) { par.assign(n, -1); }

    int root(int x) {
        if (par[x] < 0)
            return x;
        else
            return par[x] = root(par[x]);
    }

    bool issame(int x, int y) { return root(x) == root(y); }

    bool merge(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y);  // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    int size(int x) { return -par[root(x)]; }
};

int main() {
    long long N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    for (int i = 0; i < M; ++i) {
        cin >> A[i] >> B[i], --A[i], --B[i];
    }

    UnionFind uf(N);
    long long cur = N * (N - 1) / 2;
    vector<long long> res;
    for (int i = 0; i < M; ++i) {
        res.push_back(cur);

        int a = A[M - 1 - i], b = B[M - 1 - i];
        if (uf.issame(a, b)) continue;

        long long sa = uf.size(a), sb = uf.size(b);
        cur -= sa * sb;
        uf.merge(a, b);
    }

    reverse(res.begin(), res.end());
    for (int i = 0; i < res.size(); ++i) cout << res[i] << endl;
}
