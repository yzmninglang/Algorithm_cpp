#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 练习：0/1 背包问题
 * 
 * 题目描述：
 * 有 N 件物品和一个容量为 W 的背包。第 i 件物品的重量是 weight[i]，价值是 value[i]。
 * 每件物品只能用一次，求解将哪些物品装入背包可使这些物品的价值总和最大。
 * 
 * 请分别实现二维 DP 和一维 DP (空间优化) 的解法。
 */

// 1. 二维 DP 实现
int knapsack01_2D(int W, const vector<int>& weights, const vector<int>& values) {
    int n = weights.size();
    // TODO: 初始化 dp 数组

    // 已经全部为0了
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
  
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < W+1; j++)   //j代表当前节点的重量
        {
            if(j>= weights[i-1])
            {
                dp[i][j]=max(dp[i-1][j-weights[i-1]]+values[i-1],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            };
            // cout<<dp[i][j]<<std::endl;
        }    
    }
    return dp[n][W]; // 返回 dp[n][W]
}

// 2. 一维 DP 实现 (空间优化)
int knapsack01_1D(int W, const vector<int>& weights, const vector<int>& values) {
    int n = weights.size();
    // TODO: 初始化 dp 数组
    // vector<int> dp(W + 1, 0);

    // TODO: 填充 dp 数组
    // 注意：j 的遍历顺序！
    // for (int i = 0; i < n; ++i) {
    //     for (int j = W; j >= weights[i]; --j) {
    //         ...
    //     }
    // }

    return 0; // 返回 dp[W]
}

int main() {
    // 测试用例
    int W = 10;
    vector<int> weights = {2, 3, 4, 5};
    vector<int> values = {3, 4, 5, 6};

    cout << "--- 0/1 Knapsack Problem Practice ---" << endl;
    cout << "Weights: {2, 3, 4, 5}, Values: {3, 4, 5, 6}, Capacity: 10" << endl;
    
    cout << "Result (2D DP): " << knapsack01_2D(W, weights, values) << " (Expected: 12)" << endl;
    cout << "Result (1D DP): " << knapsack01_1D(W, weights, values) << " (Expected: 12)" << endl;

    return 0;
}
