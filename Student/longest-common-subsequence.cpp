#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**
 * 练习：最长公共子序列 (Longest Common Subsequence, LCS)
 * 
 * 题目描述：
 * 给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列的长度。
 * 
 * 请分别实现基础二维 DP 和空间优化的解法。
 */

// 1. 基础二维 DP 实现
int lcs_2D(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();
    string one;
    std::vector<std::vector<int>> dp(m+1,std::vector<int>(n+1,0));
    for (int i = 1; i < m+1; i++)
    {
       for (int j = 1; j < n+1; j++)
       {
            if (text1[i-1]==text2[j-1])
            {
                dp[i][j]= max(dp[i-1][j-1]+1, max(dp[i-1][j],dp[i][j-1]));
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
       }
    }
    int i =m;
    int j=n;
    while (i!=0 && j!=0)
    {
        if(dp[i-1][j]==dp[i][j])
        {
            i--;
            continue;
        }
        if(dp[i][j-1]==dp[i][j])
        {
            j--;
            continue;
        }

        one.push_back(text1[i-1]);
        i--;
        j--;

    }
    std::reverse(one.begin(),one.end());
    std::cout<<"final:"<<one<<endl;
    

    return dp[m][n]; // 返回 dp[m][n]
}

// 2. 空间优化实现 (使用一维数组)
int lcs_optimized(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();
    
    // TODO: 初始化一维 dp 数组 (n+1)
    // vector<int> dp(n + 1, 0);
    
    // TODO: 循环更新
    // 提示：需要一个变量 prev 来保存 dp[i-1][j-1]
    // for (int i = 1; i <= m; ++i) {
    //     int prev = 0;
    //     for (int j = 1; j <= n; ++j) {
    //         int temp = dp[j];
    //         ...
    //         prev = temp;
    //     }
    // }
    
    return 0; // 返回最终结果
}

int main() {
    // 测试用例
    string s1 = "abcdef";
    string s2 = "acedgf";

    cout << "--- LCS Practice ---" << endl;
    cout << "Text1: " << s1 << ", Text2: " << s2 << endl;
    
    cout << "Result (2D DP): " << lcs_2D(s1, s2) << " (Expected: 3)" << endl;
    cout << "Result (Optimized): " << lcs_optimized(s1, s2) << " (Expected: 3)" << endl;

    string s3 = "abc";
    string s4 = "def";
    cout << "\nText1: " << s3 << ", Text2: " << s4 << endl;
    cout << "Result: " << lcs_optimized(s3, s4) << " (Expected: 0)" << endl;

    return 0;
}
