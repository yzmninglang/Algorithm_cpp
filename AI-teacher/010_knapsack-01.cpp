#include <iostream>
#include <vector>
#include <algorithm>

/**
 * 0/1 背包问题 (0/1 Knapsack Problem)
 * 
 * 问题描述：
 * 有 N 件物品和一个容量为 W 的背包。第 i 件物品的重量是 weight[i]，价值是 value[i]。
 * 每件物品只能用一次，求解将哪些物品装入背包可使这些物品的价值总和最大。
 * 
 * 状态定义：
 * dp[i][j] 表示从前 i 个物品中挑选，放入容量为 j 的背包中所能获得的最大价值。
 * 
 * 状态转移方程：
 * 1. 不选第 i 个物品：dp[i][j] = dp[i-1][j]
 * 2. 选第 i 个物品（前提是 j >= weight[i]）：dp[i][j] = dp[i-1][j - weight[i]] + value[i]
 * 最终：dp[i][j] = max(dp[i-1][j], dp[i-1][j - weight[i]] + value[i])
 */

using namespace std;

// 基础二维 DP 实现
int knapsack01_2D(int W, const vector<int>& weights, const vector<int>& values) {
    int n = weights.size();
    // dp[i][j] 表示前 i 个物品在容量为 j 时的最大价值
    // 为了方便处理，i 从 1 开始，dp 数组大小为 (n+1) x (W+1)
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        int w = weights[i - 1]; // 当前物品重量
        int v = values[i - 1];  // 当前物品价值
        for (int j = 0; j <= W; ++j) {
            if (j < w) {
                // 容量不够，只能不选
                dp[i][j] = dp[i - 1][j];
            } else {
                // 选或不选，取最大值
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + v);
            }
        }
    }
    return dp[n][W];
}

/**
 * 空间优化：一维 DP (滚动数组)
 * 
 * 观察状态转移方程：dp[i][j] 只依赖于 dp[i-1][...]。
 * 我们可以只用一行 dp[j] 来存储状态。
 * 注意：为了保证计算 dp[j] 时使用的是“上一层”的值，j 必须从大到小遍历。
 */
int knapsack01_1D(int W, const vector<int>& weights, const vector<int>& values) {
    int n = weights.size();
    vector<int> dp(W + 1, 0);

    for (int i = 0; i < n; ++i) {
        int w = weights[i];
        int v = values[i];
        // 逆序遍历，确保 dp[j-w] 是上一轮（即前 i-1 个物品）的结果
        for (int j = W; j >= w; --j) {
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }
    return dp[W];
}

int main() {
    int W = 5; // 背包容量
    vector<int> weights = {1, 2, 3};
    vector<int> values = {6, 10, 12};

    cout << "--- 0/1 Knapsack Problem ---" << endl;
    cout << "Weights: {1, 2, 3}, Values: {6, 10, 12}, Capacity: 5" << endl;
    
    cout << "Result (2D DP): " << knapsack01_2D(W, weights, values) << endl;
    cout << "Result (1D DP): " << knapsack01_1D(W, weights, values) << endl;

    return 0;
}
