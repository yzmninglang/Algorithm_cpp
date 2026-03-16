#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/**
 * 最长公共子序列 (Longest Common Subsequence, LCS) - LeetCode 1143
 * 
 * 问题描述：
 * 给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列的长度。
 * 一个字符串的子序列是指这样一个新的字符串：它是由原字符串在不改变字符相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
 * 例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
 * 
 * 状态定义：
 * dp[i][j] 表示 text1[0...i-1] 和 text2[0...j-1] 的最长公共子序列的长度。
 * 
 * 状态转移方程：
 * 1. 如果 text1[i-1] == text2[j-1]：
 *    说明当前字符可以作为公共子序列的一部分，dp[i][j] = dp[i-1][j-1] + 1
 * 2. 如果 text1[i-1] != text2[j-1]：
 *    说明当前字符不能同时出现在公共子序列中，我们需要取 text1 少一个字符或 text2 少一个字符时的最大值：
 *    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
 * 
 * 边界条件：
 * 当 i=0 或 j=0 时，dp[i][j] = 0。
 */

using namespace std;

// 基础二维 DP 实现
int lcs_2D(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();
    
    // dp[i][j] 表示 text1 前 i 个字符和 text2 前 j 个字符的 LCS 长度
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    return dp[m][n];
}

/**
 * 空间优化：一维 DP
 * 
 * 观察状态转移方程：dp[i][j] 依赖于 dp[i-1][j-1], dp[i-1][j] 和 dp[i][j-1]。
 * 我们可以只用一行 dp[j] 来存储状态。
 * 但是 dp[i-1][j-1] 会被覆盖，所以需要一个变量 `prev` 来保存它。
 */
int lcs_optimized(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();
    if (m < n) return lcs_optimized(text2, text1); // 确保 n 是较小的那个，优化空间
    
    vector<int> dp(n + 1, 0);
    
    for (int i = 1; i <= m; ++i) {
        int prev = 0; // 相当于 dp[i-1][j-1]
        for (int j = 1; j <= n; ++j) {
            int temp = dp[j]; // 暂存当前的 dp[j]，它将成为下一个 j 的 dp[i-1][j-1]
            if (text1[i - 1] == text2[j - 1]) {
                dp[j] = prev + 1;
            } else {
                dp[j] = max(dp[j], dp[j - 1]);
            }
            prev = temp;
        }
    }
    
    return dp[n];
}

int main() {
    string s1 = "abcde";
    string s2 = "ace";

    cout << "--- Longest Common Subsequence ---" << endl;
    cout << "Text1: " << s1 << ", Text2: " << s2 << endl;
    
    cout << "Result (2D DP): " << lcs_2D(s1, s2) << endl;
    cout << "Result (Optimized): " << lcs_optimized(s1, s2) << endl; // Expected: 3

    string s3 = "abc";
    string s4 = "def";
    cout << "\nText1: " << s3 << ", Text2: " << s4 << endl;
    cout << "Result: " << lcs_optimized(s3, s4) << endl; // Expected: 0

    return 0;
}
