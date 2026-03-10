#include <iostream>
#include <vector>
#include <string>

template <typename T>
void observeExpansion(const std::string& label) {
    T container;
    size_t lastCapacity = container.capacity();

    std::cout << "--- Testing " << label << " ---" << std::endl;
    std::cout << "Initial Capacity: " << lastCapacity << std::endl;

    for (int i = 0; i < 50; ++i) {
        container.push_back('A' + (i % 26)); // 添加元素

        // 当容量发生变化时，打印记录
        if (container.capacity() != lastCapacity) {
            std::cout << "Size: " << container.size() 
                      << " => New Capacity: " << container.capacity() 
                      << " (Growth Factor: " << (float)container.capacity() / lastCapacity << ")" 
                      << std::endl;
            lastCapacity = container.capacity();
        }
    }
    std::cout << std::endl;
}

int main() {
    // 观察 vector<char> 的扩容
    observeExpansion<std::vector<char>>("std::vector<char>");

    // 观察 std::string 的扩容
    observeExpansion<std::string>("std::string");

    return 0;
}