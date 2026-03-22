#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 练习：买卖股票的最佳时机 (Best Time to Buy and Sell Stock)
 * 
 * 题目描述：
 * 给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
 * 
 * 请分别实现：
 * 1. 只能买卖一次 (LeetCode 121)
 * 2. 可以买卖多次 (LeetCode 122)
 */

// 1. 只能买卖一次
int maxProfit_I(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;
    
    int dp = 0;
    int dp1 = 0;
    for (int i = 0; i < prices.size(); i++)
    {
            
    }
    
    
    return 0; // 返回 dp0
}

// 2. 可以买卖多次
int maxProfit_II(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;
    
    // TODO: 初始化状态
    // int dp0 = 0;
    // int dp1 = -prices[0];
    
    // TODO: 循环更新状态
    // 注意：买入时要考虑之前的利润！
    // for (int i = 1; i < n; ++i) {
    //     ...
    // }
    
    return 0; // 返回 dp0
}

int main() {
    // 测试用例
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << "--- Stock Practice ---" << endl;
    cout << "Prices: {7, 1, 5, 3, 6, 4}" << endl;
    
    cout << "Max Profit (Only once): " << maxProfit_I(prices) << " (Expected: 5)" << endl;
    cout << "Max Profit (Multiple times): " << maxProfit_II(prices) << " (Expected: 7)" << endl;

    return 0;
}
