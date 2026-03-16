#include <iostream>
#include <vector>
#include <algorithm>

/**
 * 打家劫舍 (House Robber) - LeetCode 198
 * 
 * 问题描述：
 * 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，
 * 影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
 * 如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
 * 
 * 状态定义：
 * dp[i] 表示偷窃到第 i 间房屋（下标从 0 到 i）时能获得的最高金额。
 * 
 * 状态转移方程：
 * 对于第 i 间房屋，有两种选择：
 * 1. 偷第 i 间：那么就不能偷第 i-1 间，最大金额为 dp[i-2] + nums[i]
 * 2. 不偷第 i 间：最大金额为 dp[i-1]
 * 最终：dp[i] = max(dp[i-1], dp[i-2] + nums[i])
 * 
 * 边界条件：
 * dp[0] = nums[0]
 * dp[1] = max(nums[0], nums[1])
 */

using namespace std;

// 基础 DP 实现 (使用数组)
int rob_basic(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    
    vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    
    for (int i = 2; i < n; ++i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    
    return dp[n - 1];
}

/**
 * 空间优化：
 * 观察状态转移方程 dp[i] = max(dp[i-1], dp[i-2] + nums[i])
 * 发现 dp[i] 只依赖于前两个状态。
 * 我们可以使用两个变量来滚动更新，将空间复杂度从 O(n) 降低到 O(1)。
 */
int rob_optimized(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    
    int prev2 = nums[0];           // 相当于 dp[i-2]
    int prev1 = max(nums[0], nums[1]); // 相当于 dp[i-1]
    
    for (int i = 2; i < n; ++i) {
        int current = max(prev1, prev2 + nums[i]);
        prev2 = prev1;
        prev1 = current;
    }
    
    return prev1;
}

int main() {
    vector<int> nums1 = {1, 2, 3, 1};
    vector<int> nums2 = {2, 7, 9, 3, 1};

    cout << "--- House Robber Problem ---" << endl;
    
    cout << "Case 1: {1, 2, 3, 1}" << endl;
    cout << "Result (Basic): " << rob_basic(nums1) << endl;
    cout << "Result (Optimized): " << rob_optimized(nums1) << endl; // Expected: 4

    cout << "\nCase 2: {2, 7, 9, 3, 1}" << endl;
    cout << "Result (Basic): " << rob_basic(nums2) << endl;
    cout << "Result (Optimized): " << rob_optimized(nums2) << endl; // Expected: 12

    return 0;
}
