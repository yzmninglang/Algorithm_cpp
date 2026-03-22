#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

/**
 * @brief 回溯算法专题：组合与排列问题 (AI-Teacher 版)
 * 
 * 回溯算法的核心思想：
 * 1. 路径：已经做出的选择。
 * 2. 选择列表：当前可以做的选择。
 * 3. 结束条件：到达决策树底层，无法再做选择。
 * 
 * 框架：
 * result = []
 * def backtrack(路径, 选择列表):
 *     if 满足结束条件:
 *         result.add(路径)
 *         return
 *     
 *     for 选择 in 选择列表:
 *         做选择
 *         backtrack(路径, 选择列表)
 *         撤销选择
 */

class BacktrackingSolutions {
public:
    /**
     * @brief 组合问题 (Combinations)
     * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
     * 
     * 优化点：剪枝 (Pruning)
     * 如果剩余的元素个数不足以凑齐 k 个，则不需要继续递归。
     */
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> result;
        std::vector<int> path;
        combineBacktrack(n, k, 1, path, result);
        return result;
    }

    /**
     * @brief 全排列 (Permutations)
     * 给定一个不含重复数字的数组 nums，返回其所有可能的全排列。
     * 
     * 关键点：使用 used 数组记录已使用的元素。
     */
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> path;
        std::vector<bool> used(nums.size(), false);
        permuteBacktrack(nums, used, path, result);
        return result;
    }

    /**
     * @brief 组合总和 (Combination Sum) - 变体
     * 给定一个无重复元素的数组 candidates 和一个目标数 target，
     * 找出 candidates 中所有可以使数字和为 target 的组合。
     * candidates 中的数字可以无限制重复被选取。
     */
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> path;
        std::sort(candidates.begin(), candidates.end()); // 排序便于剪枝
        combinationSumBacktrack(candidates, target, 0, 0, path, result);
        return result;
    }

private:
    void combineBacktrack(int n, int k, int startIndex, std::vector<int>& path, std::vector<std::vector<int>>& result) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }

        // 剪枝优化：i <= n - (k - path.size()) + 1
        // 解释：如果剩余可选元素少于需要的元素，直接停止循环
        for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) {
            path.push_back(i);
            combineBacktrack(n, k, i + 1, path, result);
            path.pop_back();
        }
    }

    void permuteBacktrack(std::vector<int>& nums, std::vector<bool>& used, std::vector<int>& path, std::vector<std::vector<int>>& result) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            
            used[i] = true;
            path.push_back(nums[i]);
            permuteBacktrack(nums, used, path, result);
            path.pop_back();
            used[i] = false;
        }
    }

    void combinationSumBacktrack(std::vector<int>& candidates, int target, int sum, int startIndex, std::vector<int>& path, std::vector<std::vector<int>>& result) {
        if (sum == target) {
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i < candidates.size(); i++) {
            // 剪枝：如果当前和加上当前数已经超过 target，由于数组已排序，后面的数更不可能
            if (sum + candidates[i] > target) break;

            path.push_back(candidates[i]);
            // 注意：这里传 i 而不是 i + 1，因为元素可以重复使用
            combinationSumBacktrack(candidates, target, sum + candidates[i], i, path, result);
            path.pop_back();
        }
    }
};

void printMatrix(const std::string& title, const std::vector<std::vector<int>>& matrix) {
    std::cout << "--- " << title << " ---" << std::endl;
    for (const auto& row : matrix) {
        std::cout << "[";
        for (size_t i = 0; i < row.size(); ++i) {
            std::cout << row[i] << (i == row.size() - 1 ? "" : ", ");
        }
        std::cout << "] ";
    }
    std::cout << "\nTotal: " << matrix.size() << "\n" << std::endl;
}

int main() {
    BacktrackingSolutions sol;

    // 1. 组合
    auto res1 = sol.combine(4, 2);
    printMatrix("Combinations (n=4, k=2)", res1);

    // 2. 排列
    std::vector<int> nums = {1, 2, 3};
    auto res2 = sol.permute(nums);
    printMatrix("Permutations ([1, 2, 3])", res2);

    // 3. 组合总和 (变体)
    std::vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    auto res3 = sol.combinationSum(candidates, target);
    printMatrix("Combination Sum (candidates=[2,3,6,7], target=7)", res3);

    return 0;
}
