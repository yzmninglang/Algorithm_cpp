#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 练习：最长递增子序列 (Longest Increasing Subsequence, LIS)
 * 
 * 题目描述：
 * 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
 * 
 * 请分别实现基础 DP (O(n^2)) 和 贪心+二分查找 (O(n log n)) 的解法。
 */

// 1. 基础 DP 实现 (O(n^2))
int lengthOfLIS_DP(vector<int>& nums) {
    // int n = nums.size();
    // if (n == 0) return 0;
    // int tmp ;
    // std::vector<int> dp(n+1,1);
    // int maxnum=0;
    // for (int i = 1; i < n+1; i++)
    // {
    //     tmp=1;
    //     for (int j = 1; j < i+1; j++)
    //     {
    //         if(nums[j]<nums[i-1] && tmp < dp[j]+1)
    //         {
    //             tmp=dp[j]+1;
    //         }
    //     }
    //     dp[i]= tmp;
    //     if (tmp>maxnum)
    //     {
    //         maxnum=tmp;
    //     }
    // } 
    // return maxnum; // 返回 dp 数组中的最大值
    int tmp;
    int maxtmp =0;
    int n =nums.size();
    std::vector<int>dp(n,1);
    for(int i=1;i<n;i++)
    {
        tmp=1;
        for(int j =0;j<i;j++)
        {
            if(nums[i]>nums[j] && dp[j]+1>tmp)
            {
                tmp = dp[j]+1;
            }
        }
        dp[i]= tmp;
        if(tmp> maxtmp)
        {
            maxtmp = tmp;
        }
    }
    return maxtmp;

}

// 2. 贪心 + 二分查找实现 (O(n log n))
int lengthOfLIS_BinarySearch(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    
    // TODO: 维护一个 tails 数组
    // vector<int> tails;
    
    // TODO: 遍历 nums，使用 lower_bound 进行二分查找并更新 tails
    // for (int x : nums) {
    //     ...
    // }
    
    return 0; // 返回 tails 的长度
}

int main() {
    // 测试用例
    vector<int> nums1 = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> nums2 = {0, 1, 0, 3, 2, 3};

    cout << "--- LIS Practice ---" << endl;
    
    cout << "Case 1: {10, 9, 2, 5, 3, 7, 101, 18}" << endl;
    cout << "Result (DP): " << lengthOfLIS_DP(nums1) << " (Expected: 4)" << endl;
    cout << "Result (Binary Search): " << lengthOfLIS_BinarySearch(nums1) << " (Expected: 4)" << endl;

    cout << "\nCase 2: {0, 1, 0, 3, 2, 3}" << endl;
    cout << "Result (DP): " << lengthOfLIS_DP(nums2) << " (Expected: 4)" << endl;
    cout << "Result (Binary Search): " << lengthOfLIS_BinarySearch(nums2) << " (Expected: 4)" << endl;

    return 0;
}
