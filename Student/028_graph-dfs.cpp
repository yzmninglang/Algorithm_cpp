#include <iostream>
#include <vector>

using namespace std;

/**
 * 练习：图的 DFS 遍历（学生版）
 *
 * 题目描述：
 * 给定一个 n 个节点（编号 0 ~ n-1）的无向图和起点 start，
 * 请使用深度优先搜索（DFS）输出访问顺序。
 *
 * 要求：
 * - 使用 visited 防止重复访问
 * - 使用递归实现 dfsHelper
 * - 函数签名与测试框架保持不变
 */

// TODO: 完成递归 DFS 辅助函数
void dfsHelper(int u,
               const vector<vector<int>>& graph,
               vector<bool>& visited,
               vector<int>& order) {
    // 1) 标记当前节点已访问
    // 2) 记录访问顺序
    // 3) 遍历邻居，若未访问则递归

    // YOUR CODE HERE
}

// 对外 DFS 接口：返回从 start 出发的访问顺序
vector<int> dfsTraversal(const vector<vector<int>>& graph, int start) {
    int n = static_cast<int>(graph.size());
    vector<int> order;

    if (n == 0 || start < 0 || start >= n) {
        return order;
    }

    vector<bool> visited(n, false);

    // TODO: 调用 dfsHelper
    // YOUR CODE HERE

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

    cout << "--- Graph DFS (Student Version) ---\n";
    cout << "Start node: " << start << '\n';
    printOrder(order);

    // 期望：访问所有与 start 连通的节点
    // 一种可能顺序：0 -> 1 -> 3 -> 4 -> 6 -> 2 -> 5
    return 0;
}
