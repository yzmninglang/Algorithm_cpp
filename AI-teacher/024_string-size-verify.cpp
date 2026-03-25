#include <iostream>
#include <string>

/**
 * @brief 验证 sizeof(std::string) 与 s.size() 的区别
 * 
 * 1. sizeof(s): 返回 std::string 类对象本身的大小。
 *    它包含：指向堆内存的指针、当前长度、当前容量等。
 *    这个值在编译期确定，不会随字符串内容增长而改变。
 * 
 * 2. s.size(): 返回当前字符串中字符的个数。
 *    这个值在运行期动态变化。
 */

void test_string_size_vs_sizeof() {
    std::string s = "";
    
    std::cout << "--- Initial ---" << std::endl;
    std::cout << "sizeof(s): " << sizeof(s) << " bytes" << std::endl;
    std::cout << "s.size() : " << s.size() << std::endl;
    std::cout << "s.capacity(): " << s.capacity() << std::endl;

    s = "Hello, World!";
    std::cout << "\n--- After adding 13 chars ---" << std::endl;
    std::cout << "sizeof(s): " << sizeof(s) << " bytes" << std::endl;
    std::cout << "s.size() : " << s.size() << std::endl;

    s = "This is a very long string that will definitely exceed the Small String Optimization (SSO) buffer if it exists.";
    std::cout << "\n--- After adding a very long string ---" << std::endl;
    std::cout << "sizeof(s): " << sizeof(s) << " bytes" << std::endl;
    std::cout << "s.size() : " << s.size() << std::endl;
    std::cout << "s.capacity(): " << s.capacity() << std::endl;

// ... existing code ...

    s = "This is a very long string that will definitely exceed the Small String Optimization (SSO) buffer if it exists.";

    std::cout << "\n--- Experiments with push_back (Incremental Growth) ---" << std::endl;
    std::string s_dynamic = "";
    size_t last_capacity = 0;

    for (int i = 0; i < 200; ++i) {
        s_dynamic.push_back('!'); // 模拟一个字符一个字符地增加内容
        
        // 只有当 capacity 发生变化时才打印，方便观察规律
        if (s_dynamic.capacity() != last_capacity) {
            std::cout << "Step " << i + 1 
                      << ": Size = " << s_dynamic.size() 
                      << ", Capacity = " << s_dynamic.capacity() 
                      << " (Jumped!)" << std::endl;
            last_capacity = s_dynamic.capacity();
        }
    }

    std::cout << "\nConclusion (Updated):" << std::endl;
    // ... existing conclusions ...
    std::cout << "- Incremental growth (push_back) triggers EXPONENTIAL reallocations to save time." << std::endl;
// ... rest of code ...

    std::cout << "\nConclusion:" << std::endl;
    std::cout << "- sizeof(std::string) is CONSTANT (it's just the manager object)." << std::endl;
    std::cout << "- s.size() is DYNAMIC (it's the count of characters stored)." << std::endl;
}

int main() {
    test_string_size_vs_sizeof();
    return 0;
}
