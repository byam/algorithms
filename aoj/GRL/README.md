# グラフに関するアルゴリズムライブラリ

ref: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all

- [単一始点最短経路(Dijkstra)](./1a-単一始点最短経路.cpp)
  - 計算量：O(|E|log|V|)
  - 欠点：負の辺があるときに使用できない
  - (有向)
- [単一始点最短経路（負の重みをもつ辺を含む）(BellmanFord)](./1b-単一始点最短経路-負の重みをもつ辺を含む.cpp)
  - 計算量：O(E * V)
  - 利点：負の辺があっても正しく動作し、負の閉路を検出することができる。
  - 欠点：計算量が log ではない
  - (有向)
- [全点対間最短経路(WarshallFloyd)](./1c-全点対間最短経路.cpp)
  - 計算量：O(|V|^3)
  - 利点：
    - 負の有向路を含むかどうかを検出できる
    - s から t への最短路のパス
  - (有向)
- [最小全域木/Minimum Spanning Tree(Kruskal)](2a-最小全域木-Kruskal.cpp)
  - Kruskal :クラスカル法で minimum spanning tree を求める構造体
  - 計算量: O(|E|log|V|)
  - 入力: 辺のvector, 頂点数V
  - 最小全域木の重みの総和: sum
  - (無向)
