#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> Graph;

/*
    トポロジカルソート: 閉路の無い有向グラフ DAG について行うソート
        - ref: https://algo-logic.info/topological-sort/
        - 頂点を一列に並べる
        - 全ての辺の向きが左から右になるようにする (->)

    計算量
        - O(|V| + |E|)
        - BFS: 入ってくる辺の数が 0 となった頂点から作成する

    閉路を検出
        - グラフ G は閉路の無い有向グラフ DAG である
        - グラフ G はトポロジカルソートできる
        - 閉路なし：G.size() == DAG.size()
 */

vector<int> topologicalSort(const Graph &G) {
    vector<int> ans;

    // count edge for each node
    int n = G.size();
    vector<int> inedges(n);

    for (int i = 0; i < n; i++)
        for (auto to : G[i]) inedges[to]++;

    // 0 counted node to que
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (inedges[i] == 0) q.push(i);

    // simulation
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        // add to ans
        ans.push_back(cur);

        // decrease cur
        for (auto to : G[cur]) {
            inedges[to]--;
            if (inedges[to] == 0) q.push(to);
        }
    }

    return ans;
}

int main() {
    // in
    int n = 6;
    Graph G(n);
    G[0] = vector<int>({1, 3});
    G[1] = vector<int>({3});
    G[2] = vector<int>({3, 4});
    G[4] = vector<int>({5});

    // dag
    vector<int> dag = topologicalSort(G);
    cout << dag.size() << endl;

    // out
    for (int i = 0; i < dag.size(); i++) {
        cout << dag[i];
        if (i < dag.size() - 1) cout << " ";
    }
    cout << "\n";

    // 閉路検出
    if (G.size() == dag.size())
        cout << "Graph is a DAG" << endl;
    else
        cout << "Graph has a Cycle!" << endl;

    return 0;
}
