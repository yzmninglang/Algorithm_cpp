#include <iostream>
#include <string>
#include <vector>

/**
 * @brief 验证 std::string 的扩容机制
 * 
 * std::string 在添加字符时，如果当前容量 (capacity) 不足，会进行扩容。
 * 扩容通常涉及：
 * 1. 分配更大的内存块
 * 2. 将旧数据复制到新内存
 * 3. 释放旧内存
 * 
 * 不同的编译器/标准库实现（如 GCC 的 libstdc++, MSVC 的 STL, Clang 的 libc++）
 * 可能会有不同的扩容增长因子（通常是 1.5x 或 2x）。
 * 此外，许多实现还有 SSO (Small String Optimization) 优化。
 */

void test_string_expansion() {
    std::string s;
    size_t last_capacity = s.capacity();
    
    std::cout << "Initial capacity: " << last_capacity << std::endl;
    std::cout << "Initial address: " << (void*)s.data() << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    for (int i = 0; i < 200; ++i) {
        s.push_back('a');
        if (s.capacity() != last_capacity) {
            std::cout << "Size: " << s.size() 
                      << " | New Capacity: " << s.capacity() 
                      << " | Growth Factor: " << (double)s.capacity() / last_capacity
                      << " | Data Address: " << (void*)s.data() << std::endl;
            last_capacity = s.capacity();
        }
    }
}

int main() {
    test_string_expansion();
    return 0;
}
