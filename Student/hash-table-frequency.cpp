#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

/**
 * 练习：哈希表频率统计
 * 
 * 任务：统计一个整数数组中每个数字出现的次数。
 * 
 * 提示：
 * 1. 使用 std::unordered_map<int, int>
 * 2. 遍历数组，将数字作为 key，次数作为 value
 * 3. 打印出每个数字及其出现的频率
 */

void countIntFrequency(const std::vector<int>& nums) {
    // TODO: 在这里实现频率统计逻辑
    // 1. 定义哈希表
    // 2. 遍历 nums 数组并更新哈希表
    // 3. 遍历哈希表并输出结果
    std::unordered_map<int,int> result;
    for(int i =0;i<nums.size()-1;i++)
    {
        if(result.count(nums[i]))
        {
            result[nums[i]]++;
        }
        else
        {
            result[nums[i]]=1;
        }
    }

    for(const auto&kv : result)
    {
        std::cout<<kv.first<<":"<<kv.second<<std::endl;
    }
    
}

int main() {
    std::vector<int> nums = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    
    std::cout << "输入数据: ";
    for (int n : nums) std::cout << n << " ";
    std::cout << "\n" << std::endl;

    countIntFrequency(nums);

    return 0;
}
