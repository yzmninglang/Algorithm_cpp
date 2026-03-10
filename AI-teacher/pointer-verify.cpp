#include <iostream>
#include <string>

/**
 * @brief 验证指针步长与指针本身的大小
 * 
 * 1. 指针步长：指针 ++ 时移动的字节数，取决于指向的类型 (sizeof(T))。
 * 2. 指针大小：指针变量本身占用的内存，取决于系统的寻址位数（32位系统为4字节，64位系统为8字节）。
 */

struct CustomStruct {
    int a;
    double b;
    char c[10];
};

void test_pointer_properties() {
    int n = 10;
    int* p_int = &n;
    char* p_char = (char*)&n;
    double* p_double = (double*)&n;
    CustomStruct* p_struct = nullptr;

    std::cout << "=== 1. Pointer Size (Pointer itself) ===" << std::endl;
    std::cout << "Size of int*   : " << sizeof(p_int) << " bytes" << std::endl;
    std::cout << "Size of char*  : " << sizeof(p_char) << " bytes" << std::endl;
    std::cout << "Size of double*: " << sizeof(p_double) << " bytes" << std::endl;
    std::cout << "Size of void*  : " << sizeof(void*) << " bytes" << std::endl;
    std::cout << "(On 64-bit systems, this should be 8. On 32-bit, it's 4.)" << std::endl;

    std::cout << "\n=== 2. Pointer Step (Pointer Arithmetic) ===" << std::endl;
    std::cout << "int size: " << sizeof(int) << " | p_int + 1 moves: " 
              << (long long)(p_int + 1) - (long long)p_int << " bytes" << std::endl;
    
    std::cout << "char size: " << sizeof(char) << " | p_char + 1 moves: " 
              << (long long)(p_char + 1) - (long long)p_char << " bytes" << std::endl;
    
    std::cout << "double size: " << sizeof(double) << " | p_double + 1 moves: " 
              << (long long)(p_double + 1) - (long long)p_double << " bytes" << std::endl;

    std::cout << "CustomStruct size: " << sizeof(CustomStruct) << " | p_struct + 1 moves: " 
              << (long long)(p_struct + 1) - (long long)p_struct << " bytes" << std::endl;

    std::cout << "\nConclusion:" << std::endl;
    std::cout << "- All pointers have the SAME size (e.g., 8 bytes on x64) because they just store an address." << std::endl;
    std::cout << "- Pointers have DIFFERENT steps because the compiler needs to know how many bytes to skip to reach the next element." << std::endl;
}

int main() {
    test_pointer_properties();
    return 0;
}
