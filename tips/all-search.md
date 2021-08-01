# 全探索

- [全探索](#全探索)
  - [ポイント](#ポイント)
  - [4 種類の全探索](#4-種類の全探索)
  - [ref](#ref)
  - [練習問題](#練習問題)


## ポイント

- あり得る状態をすべて列挙して、それぞれ調べ上げる。
- つまり、「全パターンを調べ上げる」ということ。

## 4 種類の全探索

1. 本当に全通り調べ上げる「全探索」
   - 大体の場合、多重ループで解ける
2. 工夫して探索の通り数を減らす「全探索」
   - M = (a,b,c,d)の組を全通り調べ上げるときは
     - d = M - (a,b,c) とする
   - 大体の場合、多重ループで上手くいきます。
3. ビット全探索
   - 多重ループではうまくいかない全探索の 1 つ
   - O(n * 2^n)
4. 順列全探索
   - 多重ループではうまくいかない全探索の 1 つ
   - O(n * n!)

## ref
- [1-6-4. 全探索に慣れる！](https://qiita.com/e869120/items/f1c6f98364d1443148b3#1-6-4-%E5%85%A8%E6%8E%A2%E7%B4%A2%E3%81%AB%E6%85%A3%E3%82%8C%E3%82%8B)

## 練習問題

- [(ABC 144) B 81](https://atcoder.jp/contests/abc144/tasks/abc144_b)　
  - 基礎の基礎です。
- [(ABC 150) B - Count ABC](https://atcoder.jp/contests/abc150/tasks/abc150_b)
  - 全探索というか、「全通り調べ上げます」
- [(ABC 122) B - ATCoder](https://atcoder.jp/contests/abc122/tasks/abc122_b)
  - これも基本です。
- [(ABC 136) B - Uneven Numbers](https://atcoder.jp/contests/abc136/tasks/abc136_b)
  - これも基本です。
- [(ABC 106) B - 105](https://atcoder.jp/contests/abc106/tasks/abc106_b)
  - これも基本です。
- [(ABC 120) B - K-th Common Divisors](https://atcoder.jp/contests/abc120/tasks/abc120_b)
  - 単純な考察が必要ですが、基本です。
- [(ABC 057) C - Digits in Multiplication](https://atcoder.jp/contests/abc057/tasks/abc057_c)
  - 探索通り数を頑張って減らします。
- [(ABC 095) C - Half and Half](https://atcoder.jp/contests/abc095/tasks/arc096_a)
  - 探索通り数を頑張って減らします。
- [三井住友信託銀行プログラミングコンテスト2019 D - Lucky PIN](https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_d)
  - 探索通り数を頑張って減らします。
- [(ABC 128) C - Switches](https://atcoder.jp/contests/abc128/tasks/abc128_c)
  - ビット全探索の基本です。
-