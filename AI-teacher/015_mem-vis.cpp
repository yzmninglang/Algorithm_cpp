#include <iostream>
#include <string>
#include <vector>

void printAddressInfo(const std::string& s, const std::string& name) {
    // 强制转换为 void* 以打印原始地址
    const void* dataAddr = static_cast<const void*>(s.data());
    const void* objectAddr = static_cast<const void*>(&s);

    std::cout << name << " | 对象在栈上的地址: " << objectAddr 
              << " | 数据实际存储地址: " << dataAddr;
    
    // 简单判断：如果数据地址离对象地址很近，通常就在栈上（SSO）
    // 如果离得非常远，通常就在堆上
    std::cout << " -> " << (dataAddr == (void*)(&s + 1) || (size_t)objectAddr - (size_t)dataAddr < 100 ? "[栈/SSO]" : "[堆/Heap]") 
              << " | 容量: " << s.capacity() << std::endl;
}

int main() {
    std::string myStr = "Hi"; // 初始短字符串
    
    std::cout << "--- 阶段 1: 初始状态 (SSO 开启) ---" << std::endl;
    printAddressInfo(myStr, "myStr");

    std::cout << "\n--- 阶段 2: 逐渐增加长度 (触发从栈转移到堆) ---" << std::endl;
    // 增加长度直到超过典型的 SSO 阈值（通常 15-22 字节）
    while (myStr.size() < 30) {
        myStr += "12345";
        printAddressInfo(myStr, "myStr");
    }

    std::cout << "\n--- 阶段 3: 持续扩容 (堆内搬家) ---" << std::endl;
    size_t lastCap = myStr.capacity();
    for (int i = 0; i < 5; ++i) {
        while (myStr.capacity() == lastCap) {
            myStr += "Adding more text to force reallocation...";
        }
        printAddressInfo(myStr, "myStr");
        lastCap = myStr.capacity();
    }

    return 0;
}