#include <iostream>
#include <vector>
#include <algorithm>

/**
 * 完全背包问题 (Complete Knapsack Problem)
 * 
 * 问题描述：
 * 有 N 种物品和一个容量为 W 的背包。第 i 种物品的重量是 weight[i]，价值是 value[i]。
 * 每种物品都有无限件可用，求解将哪些物品装入背包可使这些物品的价值总和最大。
 * 
 * 状态定义：
 * dp[j] 表示容量为 j 的背包所能获得的最大价值。
 * 
 * 状态转移方程：
 * dp[j] = max(dp[j], dp[j - weight[i]] + value[i])
 * 
 * 与 0/1 背包的区别：
 * 0/1 背包：每件物品只能选一次，j 必须逆序遍历，以确保 dp[j-w] 是“上一层”的状态。
 * 完全背包：每件物品可以选无限次，j 必须正序遍历，以确保 dp[j-w] 包含了“当前层”已经选过该物品的状态。
 */

using namespace std;

int knapsackComplete(int W, const vector<int>& weights, const vector<int>& values) {
    int n = weights.size();
    vector<int> dp(W + 1, 0);

    for (int i = 0; i < n; ++i) {
        int w = weights[i];
        int v = values[i];
        // 正序遍历，允许重复选取同一件物品
        for (int j = w; j <= W; ++j) {
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }
    return dp[W];
}

int main() {
    int W = 5;
    vector<int> weights = {1, 2, 3};
    vector<int> values = {6, 10, 12};

    cout << "--- Complete Knapsack Problem ---" << endl;
    cout << "Weights: {1, 2, 3}, Values: {6, 10, 12}, Capacity: 5" << endl;
    
    // 0/1 背包结果应该是 22 (1+2+3=6 > 5, 选 2+3=5, 价值 10+12=22)
    // 完全背包结果应该是 30 (选 5 个重量为 1 的物品，价值 5*6=30)
    cout << "Result (Complete Knapsack): " << knapsackComplete(W, weights, values) << endl;

    return 0;
}
