#include <iostream>
#include <vector>

using namespace std;

/**
 * 图的 DFS 遍历（教师版）
 *
 * 题目描述：
 * 给定一个 n 个节点（编号 0 ~ n-1）的无向图和起点 start，
 * 使用深度优先搜索（Depth First Search, DFS）遍历图，输出访问顺序。
 *
 * 本文件展示：
 * 1) 递归版 DFS（最经典）
 * 2) visited 数组防止重复访问
 *
 * 思路：
 * - 从 start 出发，标记当前节点已访问并记录到结果
 * - 依次访问它的邻居，如果邻居未访问，则递归深入
 *
 * 时间复杂度：O(V + E)
 * 空间复杂度：O(V)（visited + 递归栈）
 */

// 递归辅助函数
void dfsHelper(int u,
               const vector<vector<int>>& graph,
               vector<bool>& visited,
               vector<int>& order) {
    visited[u] = true;
    order.push_back(u);

    for (int v : graph[u]) {
        if (!visited[v]) {
            dfsHelper(v, graph, visited, order);
        }
    }
}

// 对外 DFS 接口：返回从 start 出发的访问顺序
vector<int> dfsTraversal(const vector<vector<int>>& graph, int start) {
    int n = static_cast<int>(graph.size());
    vector<int> order;

    if (n == 0 || start < 0 || start >= n) {
        return order;
    }

    vector<bool> visited(n, false);
    dfsHelper(start, graph, visited, order);
    return order;
}

void printOrder(const vector<int>& order) {
    cout << "DFS order: ";
    for (int i = 0; i < static_cast<int>(order.size()); ++i) {
        cout << order[i];
        if (i + 1 < static_cast<int>(order.size())) {
            cout << " -> ";
        }
    }
    cout << '\n';
}

int main() {
    // 示例无向图：0~6
    // 0: 1,2
    // 1: 0,3,4
    // 2: 0,5
    // 3: 1
    // 4: 1,6
    // 5: 2
    // 6: 4
    int n = 7;
    vector<vector<int>> graph(n);

    auto addUndirectedEdge = [&](int a, int b) {
        graph[a].push_back(b);
        graph[b].push_back(a);
    };

    addUndirectedEdge(0, 1);
    addUndirectedEdge(0, 2);
    addUndirectedEdge(1, 3);
    addUndirectedEdge(1, 4);
    addUndirectedEdge(2, 5);
    addUndirectedEdge(4, 6);

    int start = 0;
    vector<int> order = dfsTraversal(graph, start);

    cout << "--- Graph DFS (Teacher Version) ---\n";
    cout << "Start node: " << start << '\n';
    printOrder(order);

    // 一种可能输出：0 -> 1 -> 3 -> 4 -> 6 -> 2 -> 5
    // 具体顺序与邻接表中邻居存储顺序有关。
    return 0;
}
