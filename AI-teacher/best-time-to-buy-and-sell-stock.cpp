#include <iostream>
#include <vector>
#include <algorithm>

/**
 * 买卖股票的最佳时机 (Best Time to Buy and Sell Stock)
 * 
 * 这里涵盖两个最经典的版本：
 * 1. 买卖股票的最佳时机 I (只能买卖一次) - LeetCode 121
 * 2. 买卖股票的最佳时机 II (可以买卖多次) - LeetCode 122
 * 
 * --- 版本 I (只能买卖一次) ---
 * 状态定义：
 * dp[i][0] 表示第 i 天结束时，不持有股票的最大利润。
 * dp[i][1] 表示第 i 天结束时，持有股票的最大利润。
 * 
 * 状态转移：
 * dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]) // 保持不持有，或今天卖出
 * dp[i][1] = max(dp[i-1][1], -prices[i])             // 保持持有，或今天买入 (因为只能买一次，买入前利润为0)
 * 
 * --- 版本 II (可以买卖多次) ---
 * 状态转移：
 * dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
 * dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]) // 区别：买入时要减去之前的利润
 */

using namespace std;

// 版本 I: 只能买卖一次 (空间优化版)
int maxProfit_I(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;
    
    int dp0 = 0;           // 不持有
    int dp1 = -prices[0];  // 持有
    
    for (int i = 1; i < n; ++i) {
        dp0 = max(dp0, dp1 + prices[i]);
        dp1 = max(dp1, -prices[i]);
    }
    
    return dp0;
}

// 版本 II: 可以买卖多次 (空间优化版)
int maxProfit_II(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;
    
    int dp0 = 0;           // 不持有
    int dp1 = -prices[0];  // 持有
    
    for (int i = 1; i < n; ++i) {
        int new_dp0 = max(dp0, dp1 + prices[i]);
        int new_dp1 = max(dp1, dp0 - prices[i]);
        dp0 = new_dp0;
        dp1 = new_dp1;
    }
    
    return dp0;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << "--- Best Time to Buy and Sell Stock ---" << endl;
    cout << "Prices: {7, 1, 5, 3, 6, 4}" << endl;
    
    cout << "Max Profit (Only once): " << maxProfit_I(prices) << " (Expected: 5)" << endl;
    cout << "Max Profit (Multiple times): " << maxProfit_II(prices) << " (Expected: 7)" << endl;

    return 0;
}
