#include <bits/stdc++.h>
using namespace std;

int dfs(int v, vector<vector<bool>> graph, vector<bool>& visited) {
    bool all_visited = true;
    for (int i = 0; i < visited.size(); i++) {
        if (visited.at(i) == false) {
            all_visited = false;
        }
    }

    if (all_visited == true) {
        return 1;
    }

    int ret = 0;
    for (int i = 0; i < visited.size(); i++) {
        if (graph.at(v).at(i) == true) {
            if (visited.at(i) == false) {
                visited.at(i) = true;
                ret += dfs(i, graph, visited);
                visited.at(i) = false;
            }
        }
    }

    return ret;
}

int main() {
    int N, M;

    cin >> N >> M;

    vector<vector<bool>> graph(N, vector<bool>(N));
    int A, B;
    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        graph.at(A - 1).at(B - 1) = true;
        graph.at(B - 1).at(A - 1) = true;
    }

    vector<bool> visited(N, false);
    visited.at(0) = true;

    int ans = dfs(0, graph, visited);

    cout << ans << endl;

    return 0;
}
