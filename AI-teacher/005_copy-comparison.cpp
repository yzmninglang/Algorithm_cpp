#include <iostream>
#include <cstring>

/**
 * @brief 演示深拷贝 (Deep Copy) 与 浅拷贝 (Shallow Copy) 的区别
 * 
 * 1. 浅拷贝 (Shallow Copy): 
 *    - 只是简单地复制指针的值。
 *    - 结果：两个对象的指针指向【同一个】内存地址。
 *    - 风险：修改一个对象会影响另一个；析构时会发生 double free 崩溃。
 * 
 * 2. 深拷贝 (Deep Copy):
 *    - 为新对象分配独立的内存，并复制内容。
 *    - 结果：两个对象的指针指向【不同】的内存地址。
 *    - 优点：对象之间互不干扰，安全。
 */

class ShallowCopy {
public:
    int* data;
    ShallowCopy(int val) {
        data = new int(val);
    }
    // 默认拷贝构造函数就是浅拷贝
    ShallowCopy(const ShallowCopy& other) : data(other.data) {
        std::cout << "Shallow Copy Constructor called." << std::endl;
    }
    ~ShallowCopy() {
        // 注意：在实际代码中，浅拷贝类析构时 delete 会导致崩溃
        // 这里为了演示地址，我们不在这里 delete，或者只 delete 一次
    }
};

class DeepCopy {
public:
    int* data;
    DeepCopy(int val) {
        data = new int(val);
    }
    // 自定义拷贝构造函数实现深拷贝
    DeepCopy(const DeepCopy& other) {
        data = new int(*other.data); // 分配新内存并复制值
        std::cout << "Deep Copy Constructor called." << std::endl;
    }
    ~DeepCopy() {
        delete data;
    }
};

void test_copy_diff() {
    std::cout << "=== 1. Shallow Copy Demo ===" << std::endl;
    ShallowCopy s1(100);
    ShallowCopy s2 = s1;
    std::cout << "s1.data address: " << (void*)s1.data << " | value: " << *s1.data << std::endl;
    std::cout << "s2.data address: " << (void*)s2.data << " | value: " << *s2.data << std::endl;
    std::cout << "Result: Addresses are SAME. (Dangerous!)" << std::endl;

    std::cout << "\n=== 2. Deep Copy Demo ===" << std::endl;
    DeepCopy d1(200);
    DeepCopy d2 = d1;
    std::cout << "d1.data address: " << (void*)d1.data << " | value: " << *d1.data << std::endl;
    std::cout << "d2.data address: " << (void*)d2.data << " | value: " << *d2.data << std::endl;
    std::cout << "Result: Addresses are DIFFERENT. (Safe!)" << std::endl;
}

int main() {
    test_copy_diff();
    return 0;
}
