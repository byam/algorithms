# 競プロ典型 90 問

ref:
- Atcoder: https://atcoder.jp/contests/typical90
- 解説：https://atcoder.jp/contests/typical90/editorial/2572
- コード：https://github.com/E869120/kyopro_educational_90
- 問題：https://twitter.com/e869120/status/1379927227739987972
- Other
  - https://github.com/Reputeless/tenkei_90
  - https://kenkoooo.com/atcoder/#/contest/show/6b06f113-bcc4-451e-97d6-93062f77d26a


- [競プロ典型 90 問](#競プロ典型-90-問)
- [問題：🌟 2](#問題-2)
  - [004. 扱いやすい形にして前計算しよう](#004-扱いやすい形にして前計算しよう)
  - [010. 区間の総和は累積和](#010-区間の総和は累積和)
  - [022. 最大公約数(gcd)はユークリッドの互除法](#022-最大公約数gcdはユークリッドの互除法)
  - [024. パリティを考える](#024-パリティを考える)
  - [027. map を使いこなそう](#027-map-を使いこなそう)
  - [033. コーナーケースに気を付けよう](#033-コーナーケースに気を付けよう)
  - [055. 定数倍を見積もる](#055-定数倍を見積もる)
  - [061. deque を知っていますか？](#061-deque-を知っていますか)
  - [067. N 進法展開を理解しよう](#067-n-進法展開を理解しよう)
  - [078. グラフの基本を知ろう](#078-グラフの基本を知ろう)
- [問題：🌟 3](#問題-3)
  - [002. 小さい制約は全探索を考えよう](#002-小さい制約は全探索を考えよう)
  - [007. 要素の検索はソートして二分探索](#007-要素の検索はソートして二分探索)
  - [014. ソートして貪欲法](#014-ソートして貪欲法)
  - [016. 工夫した全探索](#016-工夫した全探索)
  - [018. 三角関数を使いこなそう](#018-三角関数を使いこなそう)
  - [020. 整数で処理して誤差をなくそう](#020-整数で処理して誤差をなくそう)
  - [032. 小さい制約は順列全探索](#032-小さい制約は順列全探索)
  - [038. オーバーロードに注意](#038-オーバーロードに注意)
  - [044. 見かけ上の変化をメモ](#044-見かけ上の変化をメモ)
  - [046. 同じ意味のものをまとめて考える](#046-同じ意味のものをまとめて考える)
  - [048. 上界と下界を見積もる](#048-上界と下界を見積もる)
  - [050. 漸化式を立てて DP をしよう](#050-漸化式を立てて-dp-をしよう)
  - [052. 因数分解をしよう](#052-因数分解をしよう)
  - [064. 段差を考えよう](#064-段差を考えよう)
  - [069. `a^b mod m` は繰り返し二乗法](#069-ab-mod-m-は繰り返し二乗法)
  - [075. `O(sqrt(N))` での素因数分解](#075-osqrtn-での素因数分解)
  - [076. 円環を列にして２倍にする](#076-円環を列にして２倍にする)
  - [079. 操作順序によらない](#079-操作順序によらない)
  - [082. 部分問題に分解する/数列の和の公式](#082-部分問題に分解する数列の和の公式)
  - [084. ランレングス圧縮 or 累積的に計算しよう](#084-ランレングス圧縮-or-累積的に計算しよう)
- [問題：🌟 4](#問題-4)
  - [001. 答えで二分探索](#001-答えで二分探索)
  - [012. 連結判定は Union-Find](#012-連結判定は-union-find)
  - [026. 二部グラフ(bipartite graph)の性質を使おう](#026-二部グラフbipartite-graphの性質を使おう)
  - [028. 領域加算は二次元いもす法](#028-領域加算は二次元いもす法)
  - [034. 単調性を利用した尺取り法](#034-単調性を利用した尺取り法)
  - [042. 9 の倍数の性質](#042-9-の倍数の性質)
  - [043. 拡張 BFS・ダイクストラ](#043-拡張-bfsダイクストラ)
  - [058. 周期性を考える](#058-周期性を考える)

# 問題：🌟 2

## 004. 扱いやすい形にして前計算しよう

- Problem
  - [004 - Cross Sum](https://atcoder.jp/contests/typical90/tasks/typical90_d)
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/problem/004.jpg)
- Solution
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/editorial/004.jpg)

## 010. 区間の総和は累積和

- Problem
  - [010 - Score Sum Queries](https://atcoder.jp/contests/typical90/tasks/typical90_j)
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/problem/010.jpg)
- Solution
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/editorial/010.jpg)

## 022. 最大公約数(gcd)はユークリッドの互除法

- Problem
  - [022 - Cubic Cake](https://atcoder.jp/contests/typical90/tasks/typical90_v)
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/problem/022.jpg)
- Sub Problems
  - [ABC162 C - Sum of gcd of Tuples (Easy)](https://atcoder.jp/contests/abc162/tasks/abc162_c)
  - [ABC118 C - Monsters Battle Royale](https://atcoder.jp/contests/abc118/tasks/abc118_c)
- Solution
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/editorial/022.jpg)

## 024. パリティを考える

- Problem
  - [024 - Select +／- One](https://atcoder.jp/contests/typical90/tasks/typical90_x)
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/problem/024.jpg)
- Sub Problems
  - [ABC189 C - Traveling](https://atcoder.jp/contests/abc086/tasks/arc089_a)
  - [AGC002 A- Range Product](https://atcoder.jp/contests/agc002/tasks/agc002_a)
  - [AGC020 A - Move and Win](https://atcoder.jp/contests/agc020/tasks/agc020_a)
- Solution
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/editorial/024.jpg)

## 027. map を使いこなそう

- Problem
  - [027 - Sign Up Requests](https://atcoder.jp/contests/typical90/tasks/typical90_aa)
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/problem/027.jpg)
- Sub Problems
  - [ABC155 C - Poll](https://atcoder.jp/contests/abc155/tasks/abc155_c)
- Solution
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/editorial/027.jpg)

## 033. コーナーケースに気を付けよう

- Problem
  - [033 - Not Too Bright](https://atcoder.jp/contests/typical90/tasks/typical90_ag)
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/problem/033.jpg)
- Sub Problems
  - [ABC184 C - Super Ryuma](https://atcoder.jp/contests/abc184/tasks/abc184_c)
- Solution
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/editorial/033.jpg)

## 055. 定数倍を見積もる

- Problem
  - [055 - Select 5](https://atcoder.jp/contests/typical90/tasks/typical90_bc)
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/problem/055.jpg)
- Sub Problems
  - [C - Coins](https://atcoder.jp/contests/cpsco2019-s1/tasks/cpsco2019_s1_c)
- Solution
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/editorial/055.jpg)

## 061. deque を知っていますか？

- Problem
  - [061 - Deck](https://atcoder.jp/contests/typical90/tasks/typical90_bi)
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/problem/061.jpg)
- Sub Problems
  - [ABC158 D - String Formation](https://atcoder.jp/contests/abc158/tasks/abc158_d)
- Solution
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/editorial/061.jpg)

## 067. N 進法展開を理解しよう

- Problem
  - [067 - Base 8 to 9](https://atcoder.jp/contests/typical90/tasks/typical90_bo)
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/problem/067.jpg)
- Sub Problems
  - [ABC186 C - Unlucky 7](https://atcoder.jp/contests/abc186/tasks/abc186_c)
- Solution
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/editorial/067.jpg)

## 078. グラフの基本を知ろう

- Problem
  - [078 - Easy Graph Problem](https://atcoder.jp/contests/typical90/tasks/typical90_bz)
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/problem/078.jpg)
- Sub Problems
  - [ABC166 C - Peaks](https://atcoder.jp/contests/abc166/tasks/abc166_c)
- Solution
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/editorial/078.jpg)

# 問題：🌟 3

## 002. 小さい制約は全探索を考えよう

- Problem
  - [002 - Encyclopedia of Parentheses](https://atcoder.jp/contests/typical90/tasks/typical90_b)
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/problem/002.jpg)
- Solution
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/editorial/002.jpg)

<details>
<summary> Code </summary>

```cpp
    // 全探索
    for (int bitmask = 0; bitmask < (1 << n); bitmask++) {
        string s = "";
        for (int j = 0; j < n; j++) {
            if (bitmask & (1 << j))
                s += "(";
            else
                s += ")";
        }
        if (isValid(s)) ans.push_back(s);
    }
```

</details>

## 007. 要素の検索はソートして二分探索

- Problem
  - [007 - CP Classes](https://atcoder.jp/contests/typical90/tasks/typical90_g)
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/problem/007.jpg)
- Solution
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/editorial/007.jpg)

<details>
  <summary> Code </summary>

```cpp
    int rd(n);
    vi rdv(a, n);
    sort(all(a));
    int rd(q);
    for (int i = 0; i < q; i++) {
        int rd(b);

        // binary search
        auto it = lower_bound(all(a), b);
        int ans = 0;
        // not found
        if (it == a.end()) {
            ans = abs(b - a[n - 1]);
        } else {
            // get index
            int idx = it - a.begin();
            ans = abs(b - a[idx]);
            if (idx > 0) chmin(ans, abs(b - a[idx - 1]));
        }
        out(ans);
    }

```

</details>

## 014. ソートして貪欲法

- Problem
  - [014 - We Used to Sing a Song Together](https://atcoder.jp/contests/typical90/tasks/typical90_n)
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/problem/014.jpg)
- Sub Problem
  - [ABC131 D - Megalomania](https://atcoder.jp/contests/abc131/tasks/abc131_d)
- Solution
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/editorial/014.jpg)

<details>
  <summary> Code </summary>

```cpp
    int rd(n);
    vi rdv(a, n);
    vi rdv(b, n);
    sort(all(a));
    sort(all(b));
    ll e = 0;
    for (int i = 0; i < n; i++) {
        e += abs(a[i] - b[i]);
    }
    out(e);
```

</details>

## 016. 工夫した全探索

- Problem
  - [016 -  Minimum Coins](https://atcoder.jp/contests/typical90/tasks/typical90_p)
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/problem/016.jpg)
- Sub Problem
  - [ABC051 B - Sum of Three Integers](https://atcoder.jp/contests/abc051/tasks/abc051_b)
- Solution
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/editorial/016.jpg)

<details>
  <summary> Code </summary>

```cpp
    // in
    ll rd(n);
    ll rd(a, b, c);

    ll ans = INT_MAX;
    ll ma = 10000;

    for (ll i = 0; i < ma; i++) {
        for (ll j = 0; j < ma - i; j++) {
            // 工夫する
            ll d = n - i * a - j * b;
            if (d >= 0 and d % c == 0) {
                ll k = d / c;
                chmin(ans, i + j + k);
            }
        }
    }
    out(ans);
```

</details>

## 018. 三角関数を使いこなそう

- Problem
  - [018 -  Statue of Chokudai](https://atcoder.jp/contests/typical90/tasks/typical90_r)
- Sub Problem
  - [ABC168 C - Colon](https://atcoder.jp/contests/abc168/tasks/abc168_c)
- Solution
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/editorial/018.jpg)

<details>
  <summary> Code </summary>

```cpp
    long double rd(T, L, X, Y);
    int rd(Q);
    for (int i = 0; i < Q; i++) {
        int rd(E);

        // E 分後の座標
        long double r = L / 2.;
        long double x = 0.;
        long double y = -r * sin(E / T * 2. * M_PI);
        long double z = r - r * cos(E / T * 2. * M_PI);

        // 俯角をまとめる
        long double d1 = sqrt((X - x) * (X - x) + (Y - y) * (Y - y));
        long double d2 = z;
        long double ans = atan2(d2, d1) * 180. / M_PI;
        printf("%.8Lf\n", ans);
    }


    // geometry
    template <class T>
    T to_rad(T angle) {
        return angle * M_PI / 180.;
    }
```

</details>

## 020. 整数で処理して誤差をなくそう

- Problem
  - [020 -  Log Inequality](https://atcoder.jp/contests/typical90/tasks/typical90_t)
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/problem/020.jpg)
- Sub Problem
  - [ABC169 B - Multiplication 2](https://atcoder.jp/contests/abc169/tasks/abc169_b)
  - [ABC169 C - Multiplication 3](https://atcoder.jp/contests/abc169/tasks/abc169_c)
- Solution
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/editorial/020.jpg)

<details>
  <summary> Code </summary>

```cpp
    // in
    ll rd(a, b, c);

    // check: a < c^b
    // note: use powl instead of pow
    if (a < powl(c, b))
        out("Yes");
    else
        out("No");
```

</details>

## 032. 小さい制約は順列全探索

- Problem
  - [032 -  Atcoder Ekiden](https://atcoder.jp/contests/typical90/tasks/typical90_af)
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/problem/032.jpg)
- Solution
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/editorial/032.jpg)

<details>
  <summary> Code </summary>

```cpp
    // 全探索 by 順列
    vi p(n);
    for (int i = 0; i < n; i++) p[i] = i + 1;
    int ans = INT_MAX;
    do {
        // check
        bool ok = true;
        for (int i = 0; i < n - 1; i++) {
            int cur = p[i];
            int next = p[i + 1];
            if (cur > next) swap(cur, next);
            if (e.find({cur, next}) != e.end()) ok = false;
        }

        // calculate time
        if (ok) {
            int time = 0;
            for (int i = 0; i < n; i++) {
                time += g[p[i] - 1][i];
            }
            chmin(ans, time);
        }

    } while (next_permutation(all(p)));

```

</details>

## 038. オーバーロードに注意

- Problem
  - [038 -  Large LCM](https://atcoder.jp/contests/typical90/tasks/typical90_al)
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/problem/038.jpg)
- Solution
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/editorial/038.jpg)

<details>
  <summary> Code </summary>

```cpp
    ll rd(a, b);
    ll g = gcd(a, b);
    ll b1 = b / g;

    ll large = 1e18;
    if (large / a < b1) {
        out("Large");
    } else {
        out(b1 * a);
    }
```

</details>

## 044. 見かけ上の変化をメモ

- Problem
  - [044 -  Shift and Swapping](https://atcoder.jp/contests/typical90/tasks/typical90_ar)
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/problem/044.jpg)
- Sub Problem
  - [ABC199 C - IPFL](https://atcoder.jp/contests/abc199/tasks/abc199_c)
- Solution
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/editorial/044.jpg)
  - [cpp](https://github.com/E869120/kyopro_educational_90/blob/main/sol/044.cpp)

<details>
  <summary> Code </summary>

```cpp
    // in
    int rd(n, q);
    vi rdv(a, n);

    int cur = 0;
    for (int i = 0; i < q; i++) {
        int rd(t, x, y);
        x--;
        y--;
        cur = (cur + n) % n;

        if (t == 1) {
            x = (x + cur) % n;
            y = (y + cur) % n;
            // swap
            swap(a[x], a[y]);
        }
        if (t == 2) {
            // shift
            cur--;
        }
        if (t == 3) {
            x = (x + cur) % n;
            // print
            out(a[x]);
        }
    }
```

</details>

## 046. 同じ意味のものをまとめて考える

- Problem
  - [046 -  I Love 46](https://atcoder.jp/contests/typical90/tasks/typical90_at)
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/problem/046.jpg)
- Sub Problem
  - [ABC164 D - Multiple of 2019](https://atcoder.jp/contests/abc199/tasks/abc199_c)
- Solution
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/editorial/046.jpg)
  - [cpp](https://github.com/E869120/kyopro_educational_90/blob/main/sol/046.cpp)

<details>
  <summary> Code </summary>

```cpp
    // in
    int rd(n);
    vi rdv(a, n);
    vi rdv(b, n);
    vi rdv(c, n);

    // count remainders
    map<int, int> ma, mb, mc;

    for (auto x : a) ma[x % 46]++;
    for (auto x : b) mb[x % 46]++;
    for (auto x : c) mc[x % 46]++;

    // check
    ll ans = 0;
    for (auto [ka, va] : ma)
        for (auto [kb, vb] : mb)
            for (auto [kc, vc] : mc)
                if ((ka + kb + kc) % 46 == 0) ans += 1LL * va * vb * vc;

    out(ans);
```

</details>

## 048. 上界と下界を見積もる

- Problem
  - [048 -  I will not drop out](https://atcoder.jp/contests/typical90/tasks/typical90_av)
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/problem/048.jpg)
- Sub Problem
  - [ABC141 D - Powerful Discount Tickets](https://atcoder.jp/contests/abc141/tasks/abc141_d)
- Solution
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/editorial/048.jpg)
  - [cpp](https://github.com/E869120/kyopro_educational_90/blob/main/sol/048.cpp)

<details>
  <summary> Code </summary>

```cpp
    // in
    int rd(n, k);
    vi p;
    for (int i = 0; i < n; i++) {
        int rd(a, b);
        p.push_back(b);
        p.push_back(a - b);
    }
    sort(all(p));
    reverse(all(p));
    ll ans = 0;
    for (int i = 0; i < k; i++) {
        ans += p[i];
    }
    out(ans);
```

</details>

## 050. 漸化式を立てて DP をしよう

- Problem
  - [050 - Stair Jump](https://atcoder.jp/contests/typical90/tasks/typical90_ax)
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/problem/050.jpg)
- Solution
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/editorial/050.jpg)
  - [cpp](https://github.com/E869120/kyopro_educational_90/blob/main/sol/050.cpp)

<details>
  <summary> Code </summary>

```cpp
    // in
    int rd(n, l);

    vll a(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1];
        if (i >= l) a[i] = (a[i] + a[i - l]) % MOD;
    }
    out(a[n]);
```

</details>

## 052. 因数分解をしよう

- Problem
  - [052 - Dice Product](https://atcoder.jp/contests/typical90/tasks/typical90_az)
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/problem/052.jpg)
- Sub Problem
  - [ABC190 D - Staircase Sequences](https://atcoder.jp/contests/abc190/tasks/abc190_d)
- Solution
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/editorial/052.jpg)
  - [cpp](https://github.com/E869120/kyopro_educational_90/blob/main/sol/052.cpp)

<details>
  <summary> Code </summary>

```cpp
    // in
    int rd(n);

    ll ans = 1;

    // update
    for (int i = 0; i < n; i++) {
        vi rdv(b, 6);
        ll p = 0;
        for (auto x : b) p += x;

        // A * B = sum(A) * sum(B);
        ans = (ans * p) % MOD;
    }

    out(ans);
```

</details>

## 064. 段差を考えよう

- Problem
  - [064 - Uplift](https://atcoder.jp/contests/typical90/tasks/typical90_bl)
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/problem/064.jpg)
- Solution
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/editorial/064.jpg)
  - [cpp](https://github.com/E869120/kyopro_educational_90/blob/main/sol/064.cpp)

<details>
  <summary> Code </summary>

```cpp
    // in
    int rd(n, q);
    vll rdv(a, n);

    // each diffs
    vll b(n);
    ll sum = 0;
    for (int i = 0; i < n - 1; i++) {
        b[i] = a[i + 1] - a[i];
        sum += abs(b[i]);
    }

    // queries
    for (int i = 0; i < q; i++) {
        ll rd(l, r, v);
        l--;
        r--;

        ll mae = abs(b[l - 1]) + abs(b[r]);

        // b(l - 1) + v
        if (l >= 1) {
            b[l - 1] += v;
        }

        // b(r) - v
        if (r <= n - 2) {
            b[r] -= v;
        }

        // sum
        ll ato = abs(b[l - 1]) + abs(b[r]);
        sum += ato - mae;
        out(sum);
    }
```

</details>

## 069. `a^b mod m` は繰り返し二乗法

- Problem
  - [069 - Colorful Blocks 2](https://atcoder.jp/contests/typical90/tasks/typical90_bq)
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/problem/069.jpg)
- Sub Problem
  - [ABC178 C - Ubiquity](https://atcoder.jp/contests/abc178/tasks/abc178_c)
- Solution
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/editorial/069.jpg)
  - [cpp](https://github.com/E869120/kyopro_educational_90/blob/main/sol/069.cpp)

<details>
  <summary> Code </summary>

```cpp
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

void solve() {
    // in
    ll rd(n, k);
    ll ans = 1LL;

    for (int i = 0; i < 3; i++) {
        if (n - i > 0) {
            ans = 1LL * ans * (k - i) % MOD;
        }
    }

    if (k - 2 > 1 and n - 3 > 0)
        ans = (ans * binpower(k - 2, n - 3, MOD)) % MOD;

    out(ans);
}
```

</details>

## 075. `O(sqrt(N))` での素因数分解

- Problem
  - [075 - Magic For Balls](https://atcoder.jp/contests/typical90/tasks/typical90_bw)
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/problem/075.jpg)
- Sub Problem
  - [ABC084 D - 2017 Like Number](https://atcoder.jp/contests/abc084/tasks/abc084_d)
- Solution
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/editorial/075.jpg)
  - [cpp](https://github.com/E869120/kyopro_educational_90/blob/main/sol/075.cpp)

<details>
  <summary> Code </summary>

```cpp
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

void solve() {
    // in
    ll rd(n);

    // get prime divs
    vll p = prime_factors(n);

    ll cnt = p.size();

    ll ans = 0;
    while (cnt > 1) {
        ans++;
        cnt = (cnt + 1) / 2;
    }

    out(ans);
}
```

</details>

## 076. 円環を列にして２倍にする

- Problem
  - [076 - Cake Cut](https://atcoder.jp/contests/typical90/tasks/typical90_bx)
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/problem/076.jpg)
- Solution
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/editorial/076.jpg)
  - [cpp](https://github.com/E869120/kyopro_educational_90/blob/main/sol/076.cpp)

<details>
  <summary> Code </summary>

```cpp
    // in
    int rd(n);
    vll rdv(a, n);
    ll all = 0;
    for (auto x : a) all += x;
    if (all % 10) {
        out("No");
        return;
    }

    ll goal = all / 10;
    int right = 0;
    ll sum = 0;
    for (int left = 0; left < 2 * n; ++left) {
        while (right < 2 * n && right - left < n - 1 && sum < goal) {
            /* 実際に right を 1 進める */
            sum += a[right % n];
            ++right;
        }

        /* break した状態で right は条件を満たす最大なので、何かする */
        if (sum == goal) {
            out("Yes");
            return;
        }

        /* left をインクリメントする準備 */
        if (right == left)
            ++right;
        else
            sum -= a[left];
    }
    out("No");
```

</details>

## 079. 操作順序によらない

- Problem
  - [079 - Two by Two](https://atcoder.jp/contests/typical90/tasks/typical90_ca)
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/problem/079.jpg)
- Sub Problem
  - [ABC125 D - Flipping Signs](https://atcoder.jp/contests/abc125/tasks/abc125_d)
- Solution
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/editorial/079.jpg)
  - [cpp](https://github.com/E869120/kyopro_educational_90/blob/main/sol/079.cpp)

<details>
  <summary> Code </summary>

```cpp
    // in
    int rd(h, w);
    vvi a(h + 2, vi(w + 2));
    vvi b(h + 2, vi(w + 2));
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> b[i][j];
        }
    }

    // change
    ll ans = 0;
    for (int i = 1; i < h; i++) {
        for (int j = 1; j < w; j++) {
            if (a[i][j] == b[i][j]) continue;

            int d = b[i][j] - a[i][j];
            a[i][j] += d;
            a[i + 1][j] += d;
            a[i][j + 1] += d;
            a[i + 1][j + 1] += d;

            ans += abs(d);
        }
    }

    // check
    bool ok = true;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (i == h or j == w) {
                if (a[i][j] != b[i][j]) ok = false;
            }
        }
    }

    if (ok) {
        out("Yes");
        out(ans);
    } else
        out("No");
```

</details>

## 082. 部分問題に分解する/数列の和の公式

- Problem
  - [082 - Counting Numbers](https://atcoder.jp/contests/typical90/tasks/typical90_cd)
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/problem/082.jpg)
- Solution
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/editorial/082.jpg)
  - [cpp](https://github.com/E869120/kyopro_educational_90/blob/main/sol/082.cpp)

<details>
  <summary> Code </summary>

```cpp
```

</details>

## 084. ランレングス圧縮 or 累積的に計算しよう

- Problem
  - [084 - There are two types of characters](https://atcoder.jp/contests/typical90/tasks/typical90_cf)
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/problem/084.jpg)
- Sub Problem
  - [ABC182 D - Wandering](https://atcoder.jp/contests/abc182/tasks/abc182_d)
- Solution
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/editorial/084-01.jpg)
  - [cpp](https://github.com/E869120/kyopro_educational_90/blob/main/sol/084-01.cpp)
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/editorial/084-02.jpg)
  - [cpp](https://github.com/E869120/kyopro_educational_90/blob/main/sol/084-02.cpp)

<details>
  <summary> Code: ランレングス圧縮 </summary>

```cpp
    // in
    ll rd(n);
    string rd(s);

    ll ret = 0;
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt++;
        // ランレングス圧縮
        if (i == n - 1 or s[i] != s[i + 1]) {
            // 余事情
            ret += 1LL * cnt * (cnt + 1) / 2LL;
            cnt = 0;
        }
    }

    ll ans = n * (n + 1) / 2LL - ret;
    out(ans);
```

</details>

# 問題：🌟 4

## 001. 答えで二分探索

- Problem
  - [001 - Yokan Party](https://atcoder.jp/contests/typical90/tasks/typical90_a)
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/problem/001.jpg)
- Solution
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/editorial/001.jpg)
  - [cpp](https://github.com/E869120/kyopro_educational_90/blob/main/sol/001.cpp)

<details>
  <summary> Code </summary>

```cpp
bool cut(vi& A, int L, int K, int m) {
    int cnt = 0;
    int pre = 0;
    for (auto x : A) {
        if (x - pre >= m and L - x >= m) {
            cnt++;
            pre = x;
        }
    }
    return K <= cnt;
}

void solve() {
    // in
    int N, L, K;
    read(N, L, K);
    vi A(N);
    read(A);

    // binary search for ans
    int l = 0;
    int r = L;

    while (l < r - 1) {
        int m = (l + r) / 2;
        if (cut(A, L, K, m))
            l = m;
        else
            r = m;
    }
    out(l);
}
```

</details>

## 012. 連結判定は Union-Find

- Problem
  - [012 - Red Painting](https://atcoder.jp/contests/typical90/tasks/typical90_l)
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/problem/012.jpg)
- Solution
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/editorial/012.jpg)
  - [cpp](https://github.com/E869120/kyopro_educational_90/blob/main/sol/012.cpp)

<details>
  <summary> Union-Find (DSU) </summary>

```cpp
// Implement (union by size) + (path compression)
// Reference:
// Zvi Galil and Giuseppe F. Italiano,
// Data structures and algorithms for disjoint set union problems
struct dsu {
   public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(std::remove_if(
                         result.begin(), result.end(),
                         [&](const std::vector<int>& v) { return v.empty(); }),
                     result.end());
        return result;
    }

   private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

```

</details>

<details>
  <summary> Code </summary>

```cpp
    // in
    int rd(h, w, q);

    vector g(h + 2, vb(w + 2));
    dsu d(h * w);

    for (int i = 0; i < q; i++) {
        int rd(t);
        if (t == 1) {
            int rd(x, y);
            g[x][y] = true;

            // merge
            int dx[4] = {-1, 0, 1, 0};
            int dy[4] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (!g[nx][ny]) continue;
                d.merge((x - 1) * w + (y - 1), (nx - 1) * w + (ny - 1));
            }
        }
        if (t == 2) {
            int rd(sx, sy, gx, gy);
            if (g[sx][sy] and g[gx][gy] and
                d.same((sx - 1) * w + (sy - 1), (gx - 1) * w + (gy - 1)))
                out("Yes");
            else
                out("No");
        }
    }
```

</details>

## 026. 二部グラフ(bipartite graph)の性質を使おう

- Problem
  - [026 - Independent Set on a Tree](https://atcoder.jp/contests/typical90/tasks/typical90_z)
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/problem/026.jpg)
- Solution
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/editorial/026.jpg)
  - [cpp](https://github.com/E869120/kyopro_educational_90/blob/main/sol/026.cpp)
- Sub Problem
  - [ABC126 D - Even Relation](https://atcoder.jp/contests/abc126/tasks/abc126_d)

<details>
  <summary> SUMMARY </summary>

```cpp
void dfs(vvi& G, vi& col, int e, int v, vi& red, vi& green) {
    col[e] = v;

    if (v == 1)
        red.push_back(e + 1);
    else
        green.push_back(e + 1);

    for (auto ne : G[e]) {
        if (!col[ne]) dfs(G, col, ne, 3 - v, red, green);
    }
}

void solve() {
    // in
    int rd(n);
    vvi G(n);
    for (int i = 0; i < n - 1; i++) {
        int rd(a, b);
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // coloring
    vi col(n);
    vi red, green;
    dfs(G, col, 0, 1, red, green);

    // print first n/2
    vi ans;
    if (red.size() >= n / 2) {
        ans = red;
    } else {
        ans = green;
    }
    ans.resize(n / 2);
    out(ans);
}

```

</details>

## 028. 領域加算は二次元いもす法

- Problem
  - [028 - Cluttered Paper](https://atcoder.jp/contests/typical90/tasks/typical90_ab)
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/problem/028.jpg)
- Solution
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/editorial/028.jpg)
  - [cpp](https://github.com/E869120/kyopro_educational_90/blob/main/sol/028.cpp)
- Sub Problem
  - [ABC014 C - AtColor](https://atcoder.jp/contests/abc014/tasks/abc014_3)

<details>
  <summary> imos 1d </summary>

```cpp
void imos1d(vi& G, vpii& a) {
    // +/-
    for (auto [l, r] : a) {
        G[l]++;
        G[r + 1]--;
    }
    // simulation
    for (int i = 1; i < G.size(); i++) {
        G[i] += G[i - 1];
    }
}
```

</details>

<details>
  <summary> imos 2d </summary>

```cpp
void imos2d(vvi& G, vvi& a) {
    // add +/- 1
    for (auto b : a) {
        int lx = b[0];
        int ly = b[1];
        int rx = b[2];
        int ry = b[3];

        G[lx][ly]++;
        G[rx][ry]++;
        G[lx][ry]--;
        G[rx][ly]--;
    }

    // simulation
    int h = G.size();
    int w = G[0].size();
    // 横
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w - 1; j++) G[i][j + 1] += G[i][j];
    // 縦
    for (int i = 0; i < h - 1; i++)
        for (int j = 0; j < w; j++) G[i + 1][j] += G[i][j];
}
```

</details>

<details>
  <summary> Code </summary>

```cpp
    // in
    int rd(n);
    vector a(n, vi(4));
    int h = 0, w = 0;
    for (int i = 0; i < n; i++) {
        vi rdv(b, 4);
        a[i] = b;
        chmax(h, b[0]);
        chmax(h, b[2]);
        chmax(w, b[1]);
        chmax(w, b[3]);
    }

    // imos 2D
    vvi G(h + 1, vi(w + 1));
    imos2d(G, a);

    // ans
    vi ans(n + 1);
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) ans[G[i][j]]++;
    for (int i = 1; i <= n; i++) out(ans[i]);
```

</details>

## 034. 単調性を利用した尺取り法

- Problem
  - [034 - There are few types of elements](https://atcoder.jp/contests/typical90/tasks/typical90_ah)
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/problem/034.jpg)
- Solution
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/editorial/034.jpg)
  - [cpp](https://github.com/E869120/kyopro_educational_90/blob/main/sol/034.cpp)
- Sub Problem
  - [ABC130 D - Enough Array](https://atcoder.jp/contests/abc130/tasks/abc130_d)

<details>
  <summary> 尺取り法 </summary>

```cpp
    // in
    int rd(n, k);
    vi rdv(a, n);

    /* 区間の左端 left で場合分け */
    int right = 0;  // 毎回 right を使い回すようにする
    map<int, int> m;
    int ans = 0;
    int sz = 0;
    for (int left = 0; left < n; ++left) {
        /* map に a[right] を加えても大丈夫なら right を動かす */
        while (right < n && m.size() <= k) {
            if (m.find(a[right]) == m.end() and m.size() == k) break;
            m[a[right]]++;
            ++right;
            sz++;
        }

        /* break した状態で right は条件を満たす最大 */
        chmax(ans, sz);

        /* left をインクリメントする準備 */
        if (right == left)
            ++right;  // right が left に重なったら right も動かす
        else {
            // left のみがインクリメントされるので map から
            // a[left] を引く
            if (m[a[left]] == 1)
                m.erase(a[left]);
            else
                m[a[left]]--;
            sz--;
        }
    }
    out(ans);
```

</details>

## 042. 9 の倍数の性質

- Problem
  - [042 - Multiple of 9](https://atcoder.jp/contests/typical90/tasks/typical90_ap)
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/problem/042.jpg)
- Solution
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/editorial/042.jpg)
  - [cpp](https://github.com/E869120/kyopro_educational_90/blob/main/sol/042.cpp)
- Sub Problem
  - [ABC181 D - hachi](https://atcoder.jp/contests/abc181/tasks/abc181_d)

<details>
  <summary> code </summary>

```cpp
    // in
    int rd(k);
    if (k % 9) {
        out(0);
        return;
    }

    // dp[桁総和] = 通り数
    vll dp(k + 1);
    dp[0] = 1;
    for (int i = 1; i <= k; i++) {
        int R = min(i, 9);
        for (int j = 1; j <= R; j++) {
            // add j to each dp[i-j]
            dp[i] += dp[i - j];
            dp[i] %= MOD;
        }
    }

    out(dp[k]);
```

</details>

## 043. 拡張 BFS・ダイクストラ

- Problem
  - [043 - Maze Challenge with Lack of Sleep](https://atcoder.jp/contests/typical90/tasks/typical90_aq)
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/problem/043.jpg)
- Solution
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/editorial/043.jpg)
  - [cpp](https://github.com/E869120/kyopro_educational_90/blob/main/sol/043.cpp)

<details>
  <summary> Code </summary>

```cpp
struct state {
    int x, y, dir;
};

void solve() {
    // in
    int rd(h, w, sx, sy, gx, gy);
    sx--;
    sy--;
    gx--;
    gy--;
    vector<string> rdv(S, h);

    // 拡張 BFS
    vector dist(h, vector(w, vi(4)));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            for (int k = 0; k < 4; k++) dist[i][j][k] = 1e9;

    deque<state> dque;
    for (int i = 0; i < 4; i++) {
        dist[sx][sy][i] = 0;
        dque.push_back({sx, sy, i});
    }

    while (!dque.empty()) {
        state u = dque.front();
        dque.pop_front();

        // update 4 dir costs
        for (int i = 0; i < 4; i++) {
            int tx = u.x + dx[i];
            int ty = u.y + dy[i];
            int cost = dist[u.x][u.y][u.dir] + (u.dir == i ? 0 : 1);
            if (0 <= tx and tx < h and 0 <= ty and ty < w and
                S[tx][ty] != '#' and cost < dist[tx][ty][i]) {
                dist[tx][ty][i] = cost;
                if (u.dir == i)
                    dque.push_front({tx, ty, i});
                else
                    dque.push_back({tx, ty, i});
            }
        }
    }

    // ans
    int ans = 1e9;
    for (int i = 0; i < 4; i++) {
        chmin(ans, dist[gx][gy][i]);
    }
    out(ans);
}
```

</details>


## 058. 周期性を考える

- Problem
  - [058 - Original Calculator](https://atcoder.jp/contests/typical90/tasks/typical90_bf)
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/problem/058.jpg)
- Solution
  - ![image](https://raw.githubusercontent.com/E869120/kyopro_educational_90/main/editorial/058.jpg)
  - [cpp](https://github.com/E869120/kyopro_educational_90/blob/main/sol/058.cpp)
- Sub Problem
  - [ABC167 D - Teleporter](https://atcoder.jp/contests/abc167/tasks/abc167_d)

<details>
  <summary> Code </summary>

```cpp
#include <iostream>
#include <vector>
using namespace std;
int digit_sum(int x) {
    int ans = 0;
    while (x > 0) {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}
int main() {
    const int mod = 100000;
    int N;
    long long K;
    cin >> N >> K;
    vector<int> nxt(mod);
    for (int i = 0; i < mod; ++i) {
        nxt[i] = (i + digit_sum(i)) % mod;
    }
    vector<int> time_stamp(mod, -1);
    int pos = N, cnt = 0;
    while (time_stamp[pos] == -1) {
        time_stamp[pos] = cnt;
        pos = nxt[pos];
        ++cnt;
    }
    int cycle = cnt - time_stamp[pos];
    if (K >= time_stamp[pos]) {
        K = (K - time_stamp[pos]) % cycle + time_stamp[pos];
    }
    int answer = -1;
    for (int i = 0; i < mod; ++i) {
        if (time_stamp[i] == K) {
            answer = i;
        }
    }
    cout << answer << endl;
    return 0;
}
```

</details>
