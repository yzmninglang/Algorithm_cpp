#include <iostream>
#include <cstring>

/**
 * @brief 演示拷贝构造函数 (Copy Constructor)
 * 
 * 拷贝构造函数是一种特殊的构造函数，用于创建一个新对象作为现有对象的副本。
 * 
 * 1. 默认拷贝构造函数：执行浅拷贝 (Shallow Copy)，只复制成员变量的值。
 *    如果类中有指针指向堆内存，浅拷贝会导致两个对象指向同一块内存，析构时会发生 double free。
 * 
 * 2. 自定义拷贝构造函数：通常用于实现深拷贝 (Deep Copy)，为新对象分配独立的内存。
 * 
 * 3. 禁止拷贝构造函数：使用 `= delete` 关键字，防止对象被复制。
 */

class MyString {
private:
    char* data;
public:
    MyString(const char* str) {
        if (str) {
            data = new char[strlen(str) + 1];
            strcpy(data, str);
        } else {
            data = new char[1];
            *data = '\0';
        }
        std::cout << "Constructor called for: " << data << std::endl;
    }

    // 1. 自定义拷贝构造函数 (实现深拷贝)
    MyString(const MyString& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
        std::cout << "Copy Constructor (Deep Copy) called for: " << data << std::endl;
    }

    // 2. 禁止拷贝构造函数 (如果取消下面这行的注释，编译将报错)
    // MyString(const MyString& other) = delete;

    ~MyString() {
        std::cout << "Destructor called for: " << (data ? data : "nullptr") << std::endl;
        delete[] data;
    }

    void print() const {
        std::cout << "Content: " << data << std::endl;
    }
};

void test_copy_constructor() {
    std::cout << "--- Creating s1 ---" << std::endl;
    MyString s1("Hello");

    std::cout << "\n--- Creating s2 as a copy of s1 ---" << std::endl;
    MyString s2 = s1; // 调用拷贝构造函数

    s1.print();
    s2.print();
}

int main() {
    test_copy_constructor();
    return 0;
}
