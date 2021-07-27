## basics

ref:
- [厳選！C++ アルゴリズム実装に使える 25 の STL 機能【前編】](https://qiita.com/e869120/items/518297c6816adb67f9a5#3-1-%E7%B5%B6%E5%AF%BE%E5%80%A4-abs)
- [厳選！C++ アルゴリズム実装に使える 25 の STL 機能【後編】](https://qiita.com/e869120/items/702ca1c1ed6ff6770257)

2. 高速なソート (sort)
    - pros:
      - `O(logN)` でソードする
    - examples:
      - [ABC067 B - Snake Toy](https://atcoder.jp/contests/abc067/tasks/abc067_b): [b.cpp](../../atcoder/abc067/b.cpp)
      - [ABC088 B - Card Game for Two](https://atcoder.jp/contests/abc088/tasks/abc088_b): [b.cpp](../../atcoder/abc088/b.cpp)
      - [ABC132 C - Divide the Problems](https://atcoder.jp/contests/abc132/tasks/abc132_c): [c.cpp](../../atcoder/abc132/c.cpp)
      - [AGR012 A - AtCoder Group Contest](https://atcoder.jp/contests/agc012/tasks/agc012_a): [a.cpp](../../atcoder/agc012/a.cpp)
3. [バグらない二分探索 (lower_bound)](https://qiita.com/e869120/items/702ca1c1ed6ff6770257#5-3-%E3%83%90%E3%82%B0%E3%82%89%E3%81%AA%E3%81%84%E4%BA%8C%E5%88%86%E6%8E%A2%E7%B4%A2-lower_bound)
    - pros:
      - `O(logN)` でインデックスを探索する
    - examples:
      - [ABC077 C - Snuke Festival](https://atcoder.jp/contests/abc077/tasks/arc084_a): [c.cpp](../../atcoder/abc077/c.cpp)
4. [グラフを隣接リストで持つ (vector)](https://qiita.com/e869120/items/702ca1c1ed6ff6770257#5-3-%E3%83%90%E3%82%B0%E3%82%89%E3%81%AA%E3%81%84%E4%BA%8C%E5%88%86%E6%8E%A2%E7%B4%A2-lower_bound)
    - pros:
      - メモリ使用量 `O(M)`、データがある程度大きくてもメモリ制限超過 (MLE) を引き起こしません
    - examples:
      - [グラフ表現](./usage/4-vector-graph.cpp)
5. [幅優先探索 (queue, pair)](https://qiita.com/e869120/items/702ca1c1ed6ff6770257#5-3-%E3%83%90%E3%82%B0%E3%82%89%E3%81%AA%E3%81%84%E4%BA%8C%E5%88%86%E6%8E%A2%E7%B4%A2-lower_bound)
    - pros:
      - 迷路の最小移動回数を計算量 `O(H + W)` で解く
    - examples:
      - [BFS](./usage/5-bfs.cpp)
      - [ABC007 C - 幅優先探索](https://atcoder.jp/contests/abc007/tasks/abc007_3): [c.cpp](../../atcoder/abc007/c.cpp)
6. [最短経路問題・ダイクストラ法 (priority_queue)](https://qiita.com/e869120/items/702ca1c1ed6ff6770257#5-6-%E6%9C%80%E7%9F%AD%E7%B5%8C%E8%B7%AF%E5%95%8F%E9%A1%8C%E3%83%80%E3%82%A4%E3%82%AF%E3%82%B9%E3%83%88%E3%83%A9%E6%B3%95-priority_queue)
   - pros:
     - グラフの頂点Sから各頂点への最短距離を求める
     - 計算量 O(M * logN) で解ける
   - examples: