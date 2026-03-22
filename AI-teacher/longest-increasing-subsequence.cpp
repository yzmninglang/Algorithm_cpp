#include <iostream>
#include <vector>
#include <algorithm>

/**
 * 最长递增子序列 (Longest Increasing Subsequence, LIS) - LeetCode 300
 * 
 * 问题描述：
 * 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
 * 子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。
 * 
 * 1. 基础 DP 解法 (时间复杂度 O(n^2))
 * 状态定义：
 * dp[i] 表示以 nums[i] 结尾的最长递增子序列的长度。
 * 
 * 状态转移方程：
 * 对于每一个 i，遍历它之前的每一个 j (0 <= j < i)：
 * 如果 nums[i] > nums[j]，说明 nums[i] 可以接在以 nums[j] 结尾的子序列后面。
 * dp[i] = max(dp[i], dp[j] + 1)
 * 
 * 2. 贪心 + 二分查找解法 (时间复杂度 O(n log n))
 * 维护一个数组 tails，其中 tails[i] 是所有长度为 i+1 的递增子序列中最小的末尾元素。
 * 遍历 nums，对于每个元素 x：
 * - 如果 x 大于 tails 的所有元素，直接将 x 添加到 tails 末尾。
 * - 否则，在 tails 中找到第一个大于等于 x 的元素，并用 x 替换它（二分查找）。
 * 最终 tails 的长度就是 LIS 的长度。
 */

using namespace std;

// 基础 DP 实现 (O(n^2))
int lengthOfLIS_DP(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    
    vector<int> dp(n, 1); // 每个元素自身都是一个长度为 1 的子序列
    int maxLen = 1;
    
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxLen = max(maxLen, dp[i]);
    }
    
    return maxLen;
}

// 贪心 + 二分查找实现 (O(n log n))
int lengthOfLIS_BinarySearch(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    
    vector<int> tails;
    for (int x : nums) {
        auto it = lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) {
            tails.push_back(x);
        } else {
            *it = x;
        }
    }
    
    return tails.size();
}

int main() {
    vector<int> nums1 = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> nums2 = {0, 1, 0, 3, 2, 3};

    cout << "--- Longest Increasing Subsequence ---" << endl;
    
    cout << "Case 1: {10, 9, 2, 5, 3, 7, 101, 18}" << endl;
    cout << "Result (DP): " << lengthOfLIS_DP(nums1) << endl;
    cout << "Result (Binary Search): " << lengthOfLIS_BinarySearch(nums1) << endl; // Expected: 4

    cout << "\nCase 2: {0, 1, 0, 3, 2, 3}" << endl;
    cout << "Result (DP): " << lengthOfLIS_DP(nums2) << endl;
    cout << "Result (Binary Search): " << lengthOfLIS_BinarySearch(nums2) << endl; // Expected: 4

    return 0;
}
