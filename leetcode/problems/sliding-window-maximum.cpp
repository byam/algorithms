#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

//#include <atcoder/all>
// using namespace atcoder;
using namespace std;

// func
#define rep(i, first, last) for (int i = (first); i < (last); i++)
#define rrep(i, last, first) for (int i = (last); i >= (first); i--)
#define srtv(v) sort((v).begin(), (v).end())
#define all(v) (v).begin(), (v).end()

// template
template <class T>
void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}
template <class T>
void chmax(T& a, T b) {
    if (a < b) {
        a = b;
    }
}

// out -> print
template <class T>
void out(T x) {
    cout << x << "\n";
}

template <class T>
void out(vector<T> x) {
    int sz = x.size();
    for (int i = 0; i < sz; i++) {
        cout << x[i];
        if (i < sz - 1) cout << " ";
    }

    cout << "\n";
}

template <class T>
void out(vector<pair<T, T>> p) {
    for (auto [f, s] : p) {
        cout << f << " " << s << endl;
    }
}

template <class T>
void out(map<T, T> m) {
    for (auto [k, v] : m) {
        cout << k << ": " << v << endl;
    }
}

template <class T>
void out(set<T> s) {
    for (auto x : s) {
        cout << x << " ";
    }
    cout << endl;
}

// パラメータパックが空になったら終了
void outt() { cout << endl; }

// ひとつ以上のパラメータを受け取るようにし、
// 可変引数を先頭とそれ以外に分割する
template <class Head, class... Tail>
void outt(Head&& head, Tail&&... tail) {
    std::cout << head << " ";

    // パラメータパックtailをさらにheadとtailに分割する
    outt(std::forward<Tail>(tail)...);
}

// in
#define rd(...)  \
    __VA_ARGS__; \
    read(__VA_ARGS__)
#define rdv(value, ...) \
    value(__VA_ARGS__); \
    cin >> value
template <class T>
auto& operator>>(istream& is, vector<T>& xs) {
    for (auto& x : xs) is >> x;
    return is;
}
template <class T>
auto& operator<<(ostream& os, vector<T>& xs) {
    int sz = xs.size();
    rep(i, 0, sz) os << xs[i] << " \n"[i + 1 == sz];
    return os;
}
template <class T, class Y>
auto& operator<<(ostream& os, pair<T, Y>& xs) {
    os << "{" << xs.first << ", " << xs.second << "}";
    return os;
}
template <class T, class Y>
auto& operator>>(istream& is, vector<pair<T, Y>>& xs) {
    for (auto& [x1, x2] : xs) is >> x1 >> x2;
    return is;
}
template <class... Args>
auto& read(Args&... args) {
    return (cin >> ... >> args);
}

// type
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef priority_queue<int> pqi;                              // greater
typedef priority_queue<int, vector<int>, greater<int>> pqli;  // less
typedef priority_queue<long long, vector<long long>, greater<long long>> pqlll;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
typedef vector<vector<int>> Graph;

// const
const ll MOD = 1000000007;
const ll INF = 1e18;

/*-----------------------------------
        Coding Starts Here
------------------------------------*/

vector<int> maxSlidingWindowNlogN(vector<int>& nums, int k) {
    int n = nums.size();

    vector<int> ans;
    int imax = -1e5;
    map<int, int> m;
    for (int i = 0; i < k; i++) {
        imax = max(imax, nums[i]);
        m[nums[i]]++;
    }
    ans.push_back(imax);

    for (int i = k; i < n; i++) {
        imax = max(imax, nums[i]);

        int left = i - k;
        m[nums[i]]++;

        if (m[nums[left]] > 1)
            m[nums[left]]--;
        else {
            m.erase(nums[left]);
            imax = m.rbegin()->first;
        }

        ans.push_back(imax);
    }

    return ans;
}

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();

    vector<int> ans;
    deque<int> q;

    for (int i = 0; i < n; i++) {
        // 卒業させる
        if (i - q.front() == k) q.pop_front();

        // 番長が強い後輩が入ってくると去る
        while (!q.empty() and nums[q.back()] <= nums[i]) {
            q.pop_back();
        }

        // 番長例に参加
        q.push_back(i);

        // 番長更新
        if (i >= k - 1) {
            // for (auto x : q) cout << nums[x] << " ";
            // out("");

            ans.push_back(nums[q.front()]);
        }
    }

    return ans;
}

int main() {
    vi nums = {1, 3, 1, 2, 0, 5};
    out(maxSlidingWindow(nums, 3));

    vi nums2 = {1, -1};
    out(maxSlidingWindow(nums2, 1));

    return 0;
}
