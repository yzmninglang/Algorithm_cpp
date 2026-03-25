#include <iostream>
#include <vector>
#include <queue>
#include <limits>

/**
 * Dijkstra 最短路径算法（教师讲解版）
 *
 * 适用场景：
 * - 单源最短路径（一个起点到所有点）
 * - 图中边权必须非负
 *
 * 核心思想：
 * - 每次从“当前未确定最短路”的点里，取出距离起点最近的点 u
 * - 用 u 去尝试更新它的邻居 v（松弛操作）
 * - 当一个点 u 第一次从小根堆弹出时，可视为最短路已确定
 */

using namespace std;

// 邻接表边结构：u -> to，边权 weight
struct Edge {
    int to;
    int weight;
};

// 小根堆中的状态：点编号 + 当前最短估计距离
struct State {
    int node;
    int dist;

    // priority_queue 默认是大根堆，重载后实现“小根堆效果”
    bool operator<(const State& other) const {
        return dist > other.dist;
    }
};

/**
 * @brief Dijkstra 算法
 * @param graph 邻接表，graph[u] 存放从 u 出发的所有边
 * @param start 起点
 * @return dist，dist[i] 表示 start 到 i 的最短距离；不可达则为 INF
 */
vector<int> dijkstra(const vector<vector<Edge>>& graph, int start) {
    const int INF = numeric_limits<int>::max();
    int n = static_cast<int>(graph.size());

    // dist[i]：start 到 i 的当前最短距离估计
    vector<int> dist(n, INF);
    // visited[i]：i 的最短路是否已“最终确定”
    vector<bool> visited(n, false);

    priority_queue<State> pq;

    // 1) 初始化
    dist[start] = 0;
    pq.push({start, 0});

    // 2) 主循环：每次取出当前距离最小的点
    while (!pq.empty()) {
        State cur = pq.top();
        pq.pop();

        int u = cur.node;

        // 若该点已确定最短路，跳过（处理堆中过期状态）
        if (visited[u]) {
            continue;
        }

        visited[u] = true;

        // 3) 用 u 松弛所有出边 u -> v
        for (const Edge& e : graph[u]) {
            int v = e.to;
            int w = e.weight;

            // 若还未确定 v，且通过 u 到 v 更短，则更新
            if (!visited[v] && dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({v, dist[v]});
            }
        }
    }

    return dist;
}

/**
 * @brief 打印最短路结果
 */
void printDistances(const vector<int>& dist, int start) {
    const int INF = numeric_limits<int>::max();

    cout << "Start node = " << start << '\n';
    for (int i = 0; i < static_cast<int>(dist.size()); ++i) {
        cout << "dist[" << i << "] = ";
        if (dist[i] == INF) {
            cout << "INF";
        } else {
            cout << dist[i];
        }
        cout << '\n';
    }
}

int main() {
    // 示例图（有向图，点编号 0~4）
    // 0 -> 1 (10), 0 -> 2 (3)
    // 1 -> 2 (1),  1 -> 3 (2)
    // 2 -> 1 (4),  2 -> 3 (8), 2 -> 4 (2)
    // 3 -> 4 (7)
    // 4 -> 3 (9)
    int n = 5;
    vector<vector<Edge>> graph(n);

    graph[0].push_back({1, 10});
    graph[0].push_back({2, 3});
    graph[1].push_back({2, 1});
    graph[1].push_back({3, 2});
    graph[2].push_back({1, 4});
    graph[2].push_back({3, 8});
    graph[2].push_back({4, 2});
    graph[3].push_back({4, 7});
    graph[4].push_back({3, 9});

    int start = 0;
    vector<int> dist = dijkstra(graph, start);

    cout << "--- Dijkstra (Teacher Version) ---" << '\n';
    printDistances(dist, start);

    // 期望：
    // dist[0] = 0
    // dist[1] = 7
    // dist[2] = 3
    // dist[3] = 9
    // dist[4] = 5

    return 0;
}
