#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int MAXSIZE = 100;
const int INF = 1e9;

// 邻接矩阵图
struct MGraph {
    int n;                       // 顶点个数
    int edge[MAXSIZE][MAXSIZE];  // 邻接矩阵
};

/**
 * Dijkstra（邻接矩阵版）
 *
 * 参数说明：
 * g      : 图
 * start  : 起点
 * dist[] : start 到各点最短距离
 * path[] : 最短路前驱结点
 * vis[]  : 是否已确定最短路（集合 S）
 */
void dijkstra(const MGraph& g, int start, int dist[], int path[], bool vis[]) {
    // 1) 初始化
    for (int i = 0; i < g.n; ++i) {
        dist[i] = g.edge[start][i];
        vis[i] = false;

        if (g.edge[start][i] < INF && i != start) {
            path[i] = start;  //path记录的对应指标的上一个节点的值
        } else {
            path[i] = -1; // 不可达
        }
    }

    dist[start] = 0;
    vis[start] = true;
    path[start] = -1;

    // 2) 进行 n-1 轮：每轮选一个未访问且 dist 最小的点 u
    for (int k = 0; k < g.n - 1; ++k) {
        int minDist = INF;
        int u = -1;

        // 选点
        for (int j = 0; j < g.n; ++j) {
            if (!vis[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }

        // 剩余点均不可达
        if (u == -1) break;

        vis[u] = true;

        // 3) 用 u 松弛其它未访问结点
        for (int j = 0; j < g.n; ++j) {
            if (!vis[j] && g.edge[u][j] < INF && dist[u] + g.edge[u][j] < dist[j]) {
                dist[j] = dist[u] + g.edge[u][j];
                path[j] = u;
            }
        }
    }
}

// 递归打印 start -> v 的路径
void printPath(const int path[], int v) {
    if (v == -1) return;
    printPath(path, path[v]);
    cout << v;
    if (path[v] != -1) cout << " <- ";
}

int main() {
    MGraph g;
    g.n = 6; // 顶点编号 0~5

    // 先全部设为 INF，对角线为 0
    for (int i = 0; i < g.n; ++i) {
        for (int j = 0; j < g.n; ++j) {
            g.edge[i][j] = (i == j ? 0 : INF);
        }
    }

    // 构造一个有向带权图（边权非负）
    g.edge[0][1] = 7;
    g.edge[0][2] = 9;
    g.edge[0][5] = 14;
    g.edge[1][2] = 10;
    g.edge[1][3] = 15;
    g.edge[2][3] = 11;
    g.edge[2][5] = 2;
    g.edge[3][4] = 6;
    g.edge[4][5] = 9;

    int start = 0;
    int dist[MAXSIZE];
    int path[MAXSIZE];
    bool vis[MAXSIZE];

    dijkstra(g, start, dist, path, vis);

    cout << "===== Dijkstra 邻接矩阵可运行版 =====\n";
    cout << "起点: " << start << "\n\n";

    cout << left << setw(8) << "顶点"
         << setw(12) << "最短距离"
         << "路径(逆向显示)" << '\n';

    for (int v = 0; v < g.n; ++v) {
        cout << left << setw(8) << v;

        if (dist[v] >= INF) {
            cout << setw(12) << "INF" << "不可达" << '\n';
            continue;
        }

        cout << setw(12) << dist[v];

        // 显示从 v 回溯到 start 的链路（便于观察 path）
        int cur = v;
        while (cur != -1) {
            cout << cur;
            cur = path[cur];
            if (cur != -1) cout << " -> ";
        }
        cout << '\n';
    }

    return 0;
}
