# グラフに関するアルゴリズムライブラリ

ref: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all

- [グラフに関するアルゴリズムライブラリ](#グラフに関するアルゴリズムライブラリ)
  - [最短経路 / Shortest Path](#最短経路--shortest-path)
  - [全域木 / Spanning Tree](#全域木--spanning-tree)
  - [連結成分 / Connected Components](#連結成分--connected-components)
  - [サイクル / Path & Cycle](#サイクル--path--cycle)

## 最短経路 / Shortest Path
- [単一始点最短経路 / Single Shortest Path / (Dijkstra)](./1a-単一始点最短経路.cpp)
  - 計算量：O(|E|log|V|)
  - 欠点：負の辺があるときに使用できない
  - (有向)
- [単一始点最短経路負 / Single Shortest Path with Negative Edges / (BellmanFord)](./1b-単一始点最短経路-負の重みをもつ辺を含む.cpp)
  - 計算量：O(E * V)
  - 利点：負の辺があっても正しく動作し、負の閉路を検出することができる。
  - 欠点：計算量が log ではない
  - (有向)
- [全点対間最短経路 / All Pairs Shortest / Path / (WarshallFloyd)](./1c-全点対間最短経路.cpp)
  - 計算量：O(|V|^3)
  - 利点：
    - 負の有向路を含むかどうかを検出できる
    - s から t への最短路のパス
  - (有向)

## 全域木 / Spanning Tree
- [最小全域木 / Minimum Spanning Tree / (Kruskal)](./2a-最小全域木-Kruskal.cpp)
  - Kruskal :クラスカル法で minimum spanning tree を求める構造体
  - 計算量: O(|E|log|V|)
  - 入力: 辺のvector, 頂点数V
  - 最小全域木の重みの総和: sum
  - (無向)
- 最小全域有向木 / Minimum-Cost Arborescene / (Chu-Liu/Edmonds)

## 連結成分 / Connected Components

- [関節点 / Articulation Points / Lowlink](./3a-関節点.cpp)
  - グラフから取り除くと、グラフが非連結になってしまうような頂点
  - Lowlink:
    - 計算量: O(E+V)
    - グラフの関節点・橋を列挙する構造体
    - 関節点の集合: `vector<int> aps`
    - 橋の集合: `vector<P> bridges`
    - 無向グラフG G は連結である
- [橋 / Brides / Lowlink](./3b-橋.cpp)
  - 上記の Lowlink
- [強連結成分分解 / Strongly Connected Components]
  - 有向グラフG

## サイクル / Path & Cycle

- トポロジカルソート: 閉路の無い有向グラフ DAG について行うソート
  - ref: https://algo-logic.info/topological-sort/
  - 頂点を一列に並べる
  - 全ての辺の向きが左から右になるようにする (->)
- 計算量
  - O(|V| + |E|)
  - BFS: 入ってくる辺の数が 0 となった頂点から作成する
  - 有向グラフG
- 閉路を検出
  - グラフ G は閉路の無い有向グラフ DAG である
  - グラフ G はトポロジカルソートできる
  - 閉路なし：G.size() == DAG.size()
- 練習:
  - [有向グラフの閉路検査](https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_A)
  - [トポロジカルソート](https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B)
