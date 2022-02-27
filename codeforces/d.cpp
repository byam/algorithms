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

template <class T>
T maxi(vector<T>& nums) {
    // return max value index left
    return max_element(nums.begin(), nums.end()) - nums.begin();
}
template <class T>
T mini(vector<T>& nums) {
    // return min value index left
    return min_element(nums.begin(), nums.end()) - nums.begin();
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
typedef long double ld;
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

// get divisors: 10 => 1, 2, 5, 10
set<ll> all_factors(ll n) {
    // Vector to store half of the divisors
    set<ll> v;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            v.insert(i);
            v.insert(n / i);
        }
    }
    return v;
}

// get prime divisors: 12 => 2(2), 3(1)
map<ll, ll> prime_factors_map(ll n) {
    map<ll, ll> m;
    ll k = sqrt(n);
    for (int i = 2; i <= k; i++) {
        while (n % i == 0) {
            m[i]++;
            n /= i;
        }
    }
    if (n > 1) m[n]++;
    return m;
}

vector<long long> prime_factors(long long N) {
    long long rem = N;
    vector<long long> p;
    for (long long i = 2; i * i <= N; i++) {
        while (rem % i == 0) {
            rem /= i;
            p.push_back(i);
        }
    }
    if (rem != 1LL) p.push_back(rem);
    return p;
}

bool is_prime(long long N) {
    bool res = true;
    for (long long i = 2; i * i <= N; i++) {
        if (N % i == 0) res = false;
    }
    return res;
}

// geometry
#define PI 3.14159265358979323846264338327950288
template <class T>
T to_rad(T angle) {
    return angle * PI / 180.;
}

// 二乗法
long long binpower(long long a, long long b, long long mod) {
    long long ans = 1;
    while (b != 0) {
        if (b % 2 == 1) {
            ans = (long long)(ans)*a % mod;
        }
        a = (long long)(a)*a % mod;
        b /= 2;
    }
    return ans;
}

// const
const ll MOD = 1000000007;
const ll INF = 1e18;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

/*-----------------------------------
        Coding Starts Here
------------------------------------*/
class BST {
    struct node {
        int data;
        node* left;
        node* right;
    };

    node* root;

    node* makeEmpty(node* t) {
        if (t == NULL) return NULL;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }

    node* insert(int x, node* t) {
        if (t == NULL) {
            t = new node;
            t->data = x;
            t->left = t->right = NULL;
        } else if (x < t->data)
            t->left = insert(x, t->left);
        else if (x > t->data)
            t->right = insert(x, t->right);
        return t;
    }

    node* findMin(node* t) {
        if (t == NULL)
            return NULL;
        else if (t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    node* findMax(node* t) {
        if (t == NULL)
            return NULL;
        else if (t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }

    node* remove(int x, node* t) {
        node* temp;
        if (t == NULL)
            return NULL;
        else if (x < t->data)
            t->left = remove(x, t->left);
        else if (x > t->data)
            t->right = remove(x, t->right);
        else if (t->left && t->right) {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        } else {
            temp = t;
            if (t->left == NULL)
                t = t->right;
            else if (t->right == NULL)
                t = t->left;
            delete temp;
        }

        return t;
    }

    void inorder(node* t) {
        if (t == NULL) return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }

    node* find(node* t, int x) {
        if (t == NULL)
            return NULL;
        else if (x < t->data)
            return find(t->left, x);
        else if (x > t->data)
            return find(t->right, x);
        else
            return t;
    }

   public:
    BST() { root = NULL; }

    ~BST() { root = makeEmpty(root); }

    void insert(int x) { root = insert(x, root); }

    void remove(int x) { root = remove(x, root); }

    void display() {
        inorder(root);
        cout << endl;
    }

    void search(int x) { root = find(root, x); }
};

void solve() {
    // in
    BST t;
    t.insert(20);
    t.insert(10);
    t.insert(30);
    t.insert(20);
    t.display();
    t.find(t, 15);
    t.display();
    // t.remove(20);
    // t.display();
    // t.remove(25);
    // t.display();
    // t.remove(30);
    // t.display();
}

int main() {
    // make input and output more efficient
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
