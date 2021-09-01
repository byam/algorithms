#include <bits/stdc++.h>

using namespace std;

template <class T>
struct SparseTableRMQ {
    vector<vector<T>> st;
    vector<int> l2;
    int N;
    int K;

    // construct: O(n log n)
    SparseTableRMQ(vector<T> v) {
        N = v.size();
        K = floor(log2(N));

        st.resize(N, vector<T>(K + 1));
        for (int i = 0; i < N; i++) st[i][0] = v[i];
        for (int j = 1; j <= K; j++)
            for (int i = 0; i + (1 << j) <= N; i++)
                // min
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);

        l2.resize(N + 1);
        l2[1] = 0;
        for (int i = 2; i <= N; i++) l2[i] = l2[i / 2] + 1;
    }

    // query: O(1)
    T query(int L, int R) {
        int j = l2[R - L + 1];
        return min(st[L][j], st[R - (1 << j) + 1][j]);
    }
};

int main() {
    vector<int> a = {7, 2, 3, 0, 5, 10, 3, 12, 18};
    SparseTableRMQ<int> rmq(a);
    cout << rmq.query(0, 4) << endl;
    cout << rmq.query(4, 7) << endl;
    cout << rmq.query(7, 8) << endl;

    return 0;
}
