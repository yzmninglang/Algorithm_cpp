#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

/**
 * 哈希表频率统计示例
 * 
 * 任务：统计一个字符串数组中每个单词出现的次数。
 * 
 * 核心知识点：
 * 1. std::unordered_map<Key, Value> 的基本用法
 * 2. operator[] 的特性：如果 key 不存在，会自动创建一个默认值（对于 int 是 0）
 * 3. 迭代器遍历哈希表
 */

void countFrequency(const std::vector<std::string>& words) {
    // 定义哈希表：Key 是单词 (string)，Value 是频率 (int)
    std::unordered_map<std::string, int> freqMap;

    // 遍历数组进行统计
    for (const std::string& word : words) {
        // 方式 1：利用 operator[] 的自动初始化特性
        freqMap[word]++;
        
        /* 
        方式 2：显式检查是否存在（更严谨，但在统计频率时方式 1 更简洁）
        if (freqMap.find(word) == freqMap.end()) {
            freqMap[word] = 1;
        } else {
            freqMap[word]++;
        }
        */
    }

    // 输出结果
    std::cout << "单词频率统计结果：" << std::endl;
    for (const auto& pair : freqMap) {
        // pair.first 是 Key，pair.second 是 Value
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}

int main() {
    std::vector<std::string> words = {"apple", "banana", "apple", "orange", "banana", "apple"};
    
    std::cout << "输入数据: ";
    for (const auto& w : words) std::cout << w << " ";
    std::cout << "\n" << std::endl;

    countFrequency(words);

    return 0;
}
