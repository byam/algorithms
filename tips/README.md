
- [bit 全探索](#bit-全探索)
  - [bit 全探索の考え方](#bit-全探索の考え方)
  - [整数値から、「いくつか選ぶ方法」への復元](#整数値からいくつか選ぶ方法への復元)
  - [例題 1： 部分和問題](#例題-1-部分和問題)

## bit 全探索

ref: https://drken1215.hatenablog.com/entry/2019/12/14/171657

### bit 全探索の考え方

- N 個のものから作れる部分集合
- 計算量：2^n


```cpp
// 1 << n : 10..0 (2^n)
int n = 3;

for (int i = 0; i < (1 << n); i++) {

    cout << i << " = " << bitset<3>(i) << endl;
}
```
out:
```
0:000
1:001
2:010
3:011
4:100
5:101
6:110
7:111
```

### 整数値から、「いくつか選ぶ方法」への復元

- 数値の bit 列のどの `1` となっている添字を探す

```cpp
// int 型を「どのアイテムを選ぶのか」を表す vector<int> 型に変換
// bit: 集合を表す整数
// N: 何個のものについて考えているか
vector<int> IntegerToVector(int bit, int N) {
    vector<int> S;
    for (int i = 0; i < N; ++i) {
        if (bit & (1 << i)) {
            S.push_back(i);
        }
    }
    return S;
}

// 13 = 01101
for (auto i : IntegerToVector(13, 5)) std::cout << i << ' ';
cout << endl;
```
out:
```
0 2 3
```

### 例題 1： 部分和問題

N 個の正の整数 a0,a1,…,aN−1 と、正の整数 W とが与えられます。

a0,a1,…,aN−1 の中から何個か選んで総和を W とすることができるかどうかを判定してください。

計算量：O(2^N * N)
```cpp
#include <iostream>
#include <vector>
using namespace std;

// int 型を vector 型に変換
// bit: 集合を表す整数
// N: 何個のものについて考えているか
vector<int> IntegerToVector(int bit, int N) {
    vector<int> S;
    for (int i = 0; i < N; ++i) {
        if (bit & (1 << i)) {
            S.push_back(i);
        }
    }
    return S;
}

int main() {
    // 入力
    int N, W;
    cin >> N >> W;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    // bit 全探索
    bool exist = false;
    for (int bit = 0; bit < (1 << N); ++bit) {
        // どれを選ぶか
        vector<int> S = IntegerToVector(bit, N);

        // 部分集合に対応する総和
        int sum = 0;
        for (int i : S) sum += a[i];

        // 判定
        if (sum == W) exist = true;
    }

    if (exist) cout << "Yes" << endl;
    else cout << "No" << endl;
}
```

簡潔にすると
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 入力
    int N, W;
    cin >> N >> W;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    // bit 全探索
    bool exist = false;
    for (int bit = 0; bit < (1 << N); ++bit) {
        int sum = 0;
        for (int i = 0; i < N; ++i) {
            if (bit & (1 << i)) sum += a[i];
        }

        // 判定
        if (sum == W) exist = true;
    }

    if (exist) cout << "Yes" << endl;
    else cout << "No" << endl;
}
```
