#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

/**
 * @brief Two Sum 问题及其变体
 */

class TwoSum {
public:
    /**
     * @brief 基础版 Two Sum: 返回两个数的下标
     * 时间复杂度: O(n)
     * 空间复杂度: O(n)
     */
    std::vector<int> twoSumIndices(const std::vector<int>& nums, int target) {
        std::unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (hash.count(complement)) {
                return {hash[complement], i};
            }
            hash[nums[i]] = i;
        }
        return {};
    }

    /**
     * @brief 变体 1: 返回所有不重复的数对 (值对)
     * 输入数组可能包含重复元素，且需要处理重复结果。
     * 
     * 策略：先排序，使用双指针（虽然题目要求哈希表，但排序双指针处理重复更直观，
     * 这里也提供哈希表版本）。
     */
    std::vector<std::pair<int, int>> allUniquePairs(std::vector<int> nums, int target) {
        std::vector<std::pair<int, int>> result;
        std::sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) {
                result.push_back({nums[left], nums[right]});
                // 跳过重复元素
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;
                left++;
                right--;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return result;
    }

    /**
     * @brief 变体 2: 使用哈希表返回所有不重复的数对
     */
    std::vector<std::pair<int, int>> allUniquePairsHash(const std::vector<int>& nums, int target) {
        std::unordered_map<int, int> counts;
        std::vector<std::pair<int, int>> result;
        std::unordered_map<int, bool> used; // 记录已经作为较小数使用的值

        for (int x : nums) counts[x]++;

        for (auto const& [val, count] : counts) {
            int complement = target - val;
            if (counts.count(complement)) {
                int v1 = std::min(val, complement);
                int v2 = std::max(val, complement);
                
                if (used.count(v1)) continue;

                if (v1 == v2) {
                    if (counts[v1] >= 2) {
                        result.push_back({v1, v2});
                    }
                } else {
                    result.push_back({v1, v2});
                }
                used[v1] = true;
            }
        }
        return result;
    }
};

void printPairs(const std::string& label, const std::vector<std::pair<int, int>>& pairs) {
    std::cout << label << ": ";
    for (const auto& p : pairs) {
        std::cout << "[" << p.first << ", " << p.second << "] ";
    }
    std::cout << std::endl;
}

int main() {
    TwoSum ts;
    std::vector<int> nums = {2, 7, 11, 15, 2, 7};
    int target = 9;

    // 1. 基础版
    std::vector<int> indices = ts.twoSumIndices(nums, target);
    if (!indices.empty()) {
        std::cout << "Indices: [" << indices[0] << ", " << indices[1] << "]" << std::endl;
    }

    // 2. 变体：所有不重复对
    std::vector<int> nums2 = {1, 1, 2, 4, 5, 5, 3, 3};
    int target2 = 6;
    
    auto pairs1 = ts.allUniquePairs(nums2, target2);
    printPairs("Unique Pairs (Two Pointers)", pairs1);

    auto pairs2 = ts.allUniquePairsHash(nums2, target2);
    printPairs("Unique Pairs (Hash Map)", pairs2);

    return 0;
}
