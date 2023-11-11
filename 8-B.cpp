#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> tree[100005]; // 树的邻接表表示
int n, x, y;

// 使用BFS找到从起点到终点的最短路径长度
int bfs(int start, int end) {
    vector<bool> visited(n + 1, false);
    queue<pair<int, int>> q; // pair中first是当前节点，second是到达该节点的距离

    q.push({start, 0});
    visited[start] = true;

    while (!q.empty()) {
        pair<int, int> p = q.front(); q.pop();
        int current = p.first;
        int distance = p.second;

        if (current == end) {
            return distance;
        }

        for (int adj : tree[current]) {
            if (!visited[adj]) {
                visited[adj] = true;
                q.push({adj, distance + 1});
            }
        }
    }
    return -1; // 如果找不到路径，返回-1
}

int main() {
    cin >> n >> x >> y;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    cout << bfs(x, y)<< endl; // 输出小蓝鲸A追上小蓝鲸B所需的时间
    return 0;
}