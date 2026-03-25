// #include <iostream>

// void stackHungryFunction(int depth) {
//     // 每次递归申请约 1KB 的空间
//     char buffer[1024]; 
//     // 防止编译器优化掉 buffer
//     buffer[0] = 'a'; 

//     if (depth % 128 == 0) {
//         std::cout << "当前深度: " << depth << " KB (约 " << depth / 1024 << " MB)" << std::endl;
//     }

//     stackHungryFunction(depth + 1); // 递归调用
// }

// int main() {
//     std::cout << "开始测试栈极限..." << std::endl;
//     try {
//         stackHungryFunction(1);
//     } catch (...) {
//         // 注意：栈溢出通常直接导致 Segmentation Fault，很难被 catch 到
//         std::cout << "捕获到异常（实际通常会直接闪退）" << std::endl;
//     }
//     return 0;
// }



// #include <iostream>
// #include <vector>
// #include <new>

// int main() {
//     std::vector<char*> blocks;
//     size_t totalAllocated = 0;
//     const size_t chunkSize = 500 * 1024 * 1024; // 每次申请 500 MB

//     std::cout << "开始测试堆极限..." << std::endl;

//     try {
//         while (true) {
//             char* ptr = new char[chunkSize];
//             // 必须实际写入数据，否则操作系统可能会“偷懒”不分配物理内存（延迟分配）
//             for (size_t i = 0; i < chunkSize; i += 4096) ptr[i] = 0; 
            
//             blocks.push_back(ptr);
//             totalAllocated += chunkSize;
//             std::cout << "已分配: " << totalAllocated / (1024 * 1024) << " MB" << std::endl;
//         }
//     } catch (const std::bad_alloc& e) {
//         std::cerr << "\n内存耗尽！bad_alloc 异常: " << e.what() << std::endl;
//         std::cout << "最终堆分配总量: " << totalAllocated / (1024 * 1024.0) / 1024.0 << " GB" << std::endl;
//     }

//     // 清理内存
//     for (char* b : blocks) delete[] b;
//     return 0;
// }



// 验证栈向下生长的特点


#include <iostream>

void level2() {
    int local_var_2 = 20;
    std::cout << "  [Level 2] 局部变量地址: " << &local_var_2 << " (RSP 进一步下降)" << std::endl;
}

// ... 现有代码 ...

void level1() {
    int local_var_1 = 10;
    
    // 1. 获取地址并存入指针
    int* ptr = &local_var_1; 
    
    // 2. 打印地址本身
    std::cout << "地址: " << ptr << std::endl;
    
    // 3. 通过指针“解引用”读取该地址里的值
    std::cout << "该地址存储的值是: " << *ptr << std::endl;
}

// ... 现有代码 ...
int main() {
    int main_var = 0;
    std::cout << "[Main] 初始地址: " << &main_var << std::endl;
    
    level1();
    
    std::cout << "[Main] 从所有函数回来后，RSP 回到了初始水平线附近。" << std::endl;
    return 0;
}

// [Main] 初始地址: 0x59b55ff67c
// [Level 1] 进入函数，局部变量地址: 0x59b55ff63c  →小于原来0x40
//   [Level 2] 局部变量地址: 0x59b55ff5fc (RSP 进一步下降)
// [Level 1] 从 Level 2 回来后，局部变量地址没变: 0x59b55ff63c (RSP 依然稳在这里)
// [Main] 从所有函数回来后，RSP 回到了初始水平线附近。



