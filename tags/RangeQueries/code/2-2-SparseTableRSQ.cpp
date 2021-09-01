#include <bits/stdc++.h>

using namespace std;

template <class T>
struct SparseTableRSQ {
    vector<vector<T>> st;
    int N;
    int K;

    // construct: O(n log n)
    SparseTableRSQ(vector<T> v) {
        N = v.size();
        K = floor(log2(N));

        st.resize(N, vector<T>(K + 1));
        for (int i = 0; i < N; i++) st[i][0] = v[i];
        for (int j = 1; j <= K; j++)
            for (int i = 0; i + (1 << j) <= N; i++)
                // sum
                st[i][j] = st[i][j - 1] + st[i + (1 << (j - 1))][j - 1];
    }

    // query: O(log n)
    T query(int L, int R) {
        T sum = 0;
        for (int j = K; j >= 0; j--) {
            if ((1 << j) <= R - L + 1) {
                sum += st[L][j];
                L += 1 << j;
            }
        }
        return sum;
    }
};

int main() {
    vector<int> a = {7, 2, 3, 0, 5, 10, 3, 12, 18};
    SparseTableRSQ<int> rsq(a);
    cout << rsq.query(0, 4) << endl;
    cout << rsq.query(4, 7) << endl;
    cout << rsq.query(7, 8) << endl;

    return 0;
}
