#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// グラフの隣接リスト表現
vector< vector<int> > graph;

// 幅優先探索関数
void bfs(int start) {
    vector<bool> visited(graph.size(), false); // ノードの訪問状態を管理する配列
    queue<int> q; // キューを使用して探索順序を管理

    visited[start] = true; // スタートノードを訪問済みにする
    q.push(start); // スタートノードをキューに追加

    while (!q.empty()) {
        int current = q.front(); // キューの先頭からノードを取り出す
        q.pop(); // 取り出したノードをキューから削除
        cout << current << " "; // ノードを出力

        // 取り出したノードの隣接ノードを順番に処理
        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) { // 隣接ノードが未訪問の場合
                visited[neighbor] = true; // 隣接ノードを訪問済みにする
                q.push(neighbor); // 隣接ノードをキューに追加
            }
        }
    }
}

int main() {
    // グラフの初期化（例として、5つのノードを持つグラフを作成）
    int n = 5;
    graph.resize(n);

    // グラフの辺を追加（例として、ノード0からノード1, 2を結ぶ辺を追加）
    graph[0].push_back(1);
    graph[0].push_back(2);

    // グラフの辺を追加（例として、ノード1からノード3を結ぶ辺を追加）
    graph[1].push_back(3);

    // グラフの辺を追加（例として、ノード2からノード4を結ぶ辺を追加）
    graph[2].push_back(4);

    cout << "BFS traversal starting from node 0: ";
    bfs(0); // 幅優先探索の実行

    return 0;
}
