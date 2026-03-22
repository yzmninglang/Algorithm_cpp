#include <iostream>
#include <vector>

/**
 * 爬楼梯 (Climbing Stairs) - LeetCode 70
 * 
 * 问题描述：
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 * 
 * 状态定义：
 * dp[i] 表示到达第 i 阶楼梯的方法总数。
 * 
 * 状态转移方程：
 * 到达第 i 阶楼梯，只有两种可能：
 * 1. 从第 i-1 阶爬 1 个台阶上来。
 * 2. 从第 i-2 阶爬 2 个台阶上来。
 * 因此：dp[i] = dp[i-1] + dp[i-2]
 * 
 * 边界条件：
 * dp[1] = 1 (1 阶只有 1 种方法)
 * dp[2] = 2 (2 阶有 1+1 或 2 两种方法)
 * 
 * 备注：这本质上是一个斐波那契数列问题。
 */

using namespace std;

// 基础 DP 实现 (使用数组)
int climbStairs_basic(int n) {
    if (n <= 2) return n;
    
    vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;
    
    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    
    return dp[n];
}

/**
 * 空间优化：
 * 观察状态转移方程 dp[i] = dp[i-1] + dp[i-2]
 * 发现 dp[i] 只依赖于前两个状态。
 * 我们可以使用两个变量来滚动更新，将空间复杂度从 O(n) 降低到 O(1)。
 */
int climbStairs_optimized(int n) {
    if (n <= 2) return n;
    
    int prev2 = 1; // 相当于 dp[i-2]
    int prev1 = 2; // 相当于 dp[i-1]
    
    for (int i = 3; i <= n; ++i) {
        int current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    
    return prev1;
}

int main() {
    int n1 = 3;
    int n2 = 5;

    cout << "--- Climbing Stairs Problem ---" << endl;
    
    cout << "n = 3" << endl;
    cout << "Result (Basic): " << climbStairs_basic(n1) << endl;
    cout << "Result (Optimized): " << climbStairs_optimized(n1) << endl; // Expected: 3

    cout << "\nn = 5" << endl;
    cout << "Result (Basic): " << climbStairs_basic(n2) << endl;
    cout << "Result (Optimized): " << climbStairs_optimized(n2) << endl; // Expected: 8

    return 0;
}
