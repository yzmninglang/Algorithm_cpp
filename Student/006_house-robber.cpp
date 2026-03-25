#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 练习：打家劫舍 (House Robber)
 * 
 * 题目描述：
 * 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，
 * 影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
 * 如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
 * 
 * 请分别实现基础 DP 和空间优化的解法。
 */

// 1. 基础 DP 实现 (使用数组)
int rob_basic(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    std::vector<int> dp(n+1,0);
    dp[1] = nums[0];
    for (int i = 2; i < n+1; i++)
    {
        dp[i]= max(dp[i-1],dp[i-2]+nums[i-1]);
    }

    return dp[n]; // 返回 dp[n-1]
}

// 2. 空间优化实现 (使用两个变量)
int rob_optimized(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    
    // TODO: 使用两个变量 prev2 和 prev1 来滚动更新
    int pre2 =0;
    int pre1 = nums[0];
    int tmp;
    for (int i = 1; i < n+1; i++)
    {
        tmp = max(pre1,pre2+nums[i-1]);
        pre2=pre1;
        pre1 = tmp;
    }
    
    
    return pre1; // 返回最终结果
}

int main() {
    // 测试用例
    vector<int> nums1 = {1, 2, 3, 1};
    vector<int> nums2 = {2, 7, 9, 3, 1};

    cout << "--- House Robber Practice ---" << endl;
    
    cout << "Case 1: {1, 2, 3, 1}" << endl;
    cout << "Result (Basic): " << rob_basic(nums1) << " (Expected: 4)" << endl;
    cout << "Result (Optimized): " << rob_optimized(nums1) << " (Expected: 4)" << endl;

    cout << "\nCase 2: {2, 7, 9, 3, 1}" << endl;
    cout << "Result (Basic): " << rob_basic(nums2) << " (Expected: 12)" << endl;
    cout << "Result (Optimized): " << rob_optimized(nums2) << " (Expected: 12)" << endl;

    return 0;
}
