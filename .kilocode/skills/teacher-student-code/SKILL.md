---
name: teacher-student-code
description: Generate C++ Algorithm Practice Files (Teacher + Student Versions)
---


# Instructions

### Objective

For each given algorithm problem, generate **two C++ files**:

1. **Teacher version** (complete, runnable, with full solution)  
   Directory: `D:\Code\Algorithm\AI-teacher`

2. **Student version** (same structure/signature, but with TODO sections for students to complete)  
   Directory: `D:\Code\Algorithm\Student`

File naming must follow the next incremental numeric prefix based on the **largest existing index** in the folders, e.g.:
`026_two-sum.cpp`

---

### Inputs
- Problem title and statement
- Input/output description
- Examples and constraints
- Optional: preferred approach (hash map / two pointers / DP, etc.)
- Optional: required function signature / `class Solution` format

---

### Output Requirements

#### 1) Auto-increment filename rule
- Scan `.cpp` files in both:
  - `D:\Code\Algorithm\AI-teacher`
  - `D:\Code\Algorithm\Student`
- Extract numeric prefix from `NNN_name.cpp`
- Let `max_id` be the maximum found in both folders
- New id = `max_id + 1`, zero-padded to 3 digits
- Filename format: `NNN_slug.cpp`
- Slug format: lowercase English + hyphen (e.g., `two-sum`)

---

#### 2) Teacher version requirements (AI-teacher)
Must include:
- Problem title + short description in comments
- Full working C++17 solution
- Clear algorithm explanation comments
- Time and space complexity
- `main()` with at least one runnable test case
- Good naming and edge-case handling

---

#### 3) Student version requirements (Student)
Must include:
- Simplified problem comments
- Same function signature as teacher version
- Full code skeleton and runnable test harness
- `TODO` / `YOUR CODE HERE` in core algorithm section
- Must **not** include full final solution
- May include light hints without revealing answer

---

### Generation Workflow
1. Receive problem + optional slug
2. Scan both directories and find max numeric prefix
3. Compute next id and build filename
4. Generate full teacher solution code
5. Generate student skeleton code with TODO placeholders
6. Write files to:
   - `D:\Code\Algorithm\AI-teacher\NNN_slug.cpp`
   - `D:\Code\Algorithm\Student\NNN_slug.cpp`
7. Return summary: file paths, filename, algorithm tags used

---

### Additional Constraints
- Create directories automatically if missing
- If both folders are empty, start from `001`
- If slug not provided, auto-generate from title:
  - lowercase
  - spaces to `-`
  - remove special characters
- Never overwrite existing files; if collision occurs, increment again
- Use UTF-8 encoding

---

## Reusable Prompt Template (English)

```text
You are a "C++ Algorithm Practice Generator".

Task:
Given a problem statement, generate two .cpp files:
1) Teacher version (full solution)
2) Student version (skeleton with TODOs)

[Directories]
- Teacher: D:\Code\Algorithm\AI-teacher
- Student: D:\Code\Algorithm\Student

[Naming Rules]
1. Scan both directories for .cpp files matching NNN_name.cpp.
2. Extract NNN, find max, and use max+1.
3. Format id as 3 digits (e.g., 026).
4. Filename format: NNN_slug.cpp (slug like two-sum).
5. Teacher and student filenames must be identical.
6. Never overwrite existing files.

[Teacher Version Requirements]
- Complete runnable C++17 code
- Problem comment, approach, complexity
- Includes main() with test case(s)

[Student Version Requirements]
- Same function signature and test harness
- Core logic replaced with TODO placeholders
- No full final answer; hints allowed

[Output Format]
1. Show the two full output file paths first.
2. Then provide teacher code.
3. Then provide student code.
4. Finally list algorithm tags (e.g., Hash Table, Two Pointers).

Problem:
<paste problem here>

Optional slug:
<e.g., two-sum>
```

---

# Example Usage

## file_name

`002_best-time-to-buy-and-sell-stock.cpp`


## student
```cpp
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
    

    
    
    return 0; // 返回 dp0
}

// 2. 可以买卖多次
int maxProfit_II(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;

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
```

## teacher

```cpp
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
```
