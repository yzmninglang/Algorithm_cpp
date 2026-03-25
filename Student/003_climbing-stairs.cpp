#include <iostream>
#include <vector>

using namespace std;

/**
 * 练习：爬楼梯 (Climbing Stairs)
 * 
 * 题目描述：
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 * 
 * 请分别实现基础 DP 和空间优化的解法。
 */

// 1. 基础 DP 实现 (使用数组)
int climbStairs_basic(int n) {
    if (n <= 2) return n;
    
    int result = climbStairs_basic(n-2)+climbStairs_basic(n-1);
    return result; // 返回 dp[n]
}

// 2. 空间优化实现 (使用两个变量)
int climbStairs_optimized(int n) {
    if (n <= 2) return n;
    
    // TODO: 使用两个变量 prev2 和 prev1 来滚动更新
    // int prev2 = ...
    // int prev1 = ...
    
    // TODO: 循环更新
    // for (int i = 3; i <= n; ++i) {
    //     int current = ...
    //     ...
    // }
    
    return 0; // 返回最终结果
}

int main() {
    // 测试用例
    int n1 = 3;
    int n2 = 5;

    cout << "--- Climbing Stairs Practice ---" << endl;
    
    cout << "n = 3" << endl;
    cout << "Result (Basic): " << climbStairs_basic(n1) << " (Expected: 3)" << endl;
    cout << "Result (Optimized): " << climbStairs_optimized(n1) << " (Expected: 3)" << endl;

    cout << "\nn = 5" << endl;
    cout << "Result (Basic): " << climbStairs_basic(n2) << " (Expected: 8)" << endl;
    cout << "Result (Optimized): " << climbStairs_optimized(n2) << " (Expected: 8)" << endl;

    return 0;
}
