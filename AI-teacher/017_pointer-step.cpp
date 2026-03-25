#include <iostream>
#include <string>

/**
 * @brief 验证指针步长与数据类型的关系
 * 
 * 当我们对指针进行 ++ 操作时，指针移动的字节数取决于它所指向的数据类型的大小。
 * 移动字节数 = sizeof(T)
 */

void test_pointer_step() {
    int int_arr[3] = {10, 20, 30};
    char char_arr[3] = {'a', 'b', 'c'};
    double double_arr[3] = {1.1, 2.2, 3.3};

    int* p_int = int_arr;
    char* p_char = char_arr;
    double* p_double = double_arr;

    std::cout << "--- Pointer Step Size Verification ---" << std::endl;
    
    std::cout << "int size: " << sizeof(int) << " bytes" << std::endl;
    std::cout << "p_int current: " << (void*)p_int << std::endl;
    std::cout << "p_int next   : " << (void*)(p_int + 1) << " (Diff: " << (char*)(p_int + 1) - (char*)p_int << " bytes)" << std::endl;
    
    std::cout << "\nchar size: " << sizeof(char) << " byte" << std::endl;
    std::cout << "p_char current: " << (void*)p_char << std::endl;
    std::cout << "p_char next   : " << (void*)(p_char + 1) << " (Diff: " << (char*)(p_char + 1) - (char*)p_char << " bytes)" << std::endl;

    std::cout << "\ndouble size: " << sizeof(double) << " bytes" << std::endl;
    std::cout << "p_double current: " << (void*)p_double << std::endl;
    std::cout << "p_double next   : " << (void*)(p_double + 1) << " (Diff: " << (char*)(p_double + 1) - (char*)p_double << " bytes)" << std::endl;

    std::cout << "\nConclusion: Pointer increment step = sizeof(Type)" << std::endl;
}

int main() {
    test_pointer_step();
    return 0;
}
