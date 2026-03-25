#include <iostream>
#include <string>

/**
 * C++ std::string 插入字符/字符串的常用方法演示
 */

using namespace std;

int main() {
    string s = "Hello";
    cout << "Original: " << s << endl;

    // 1. 在末尾添加 (最常用)
    s += '!';               // 添加单个字符
    s += " World";          // 添加字符串
    s.push_back('?');       // 在末尾添加单个字符 (类似 vector)
    s.append(" - appended"); // 在末尾追加字符串
    cout << "After append: " << s << endl;

    // 2. 在指定位置插入 (insert)
    // 语法: s.insert(pos, string/char_count, char)
    string base = "ABCDE";
    
    // 在索引 2 处插入字符串 "123" (插入后 "123" 的起始索引为 2)
    base.insert(2, "123"); 
    cout << "Insert string: " << base << endl; // AB123CDE

    // 在索引 0 处插入 3 个 '*'
    base.insert(0, 3, '*');
    cout << "Insert chars: " << base << endl; // ***AB123CDE

    // 3. 使用迭代器插入
    base.insert(base.begin() + 1, '@');
    cout << "Insert with iterator: " << base << endl; // *@**AB123CDE

    // 4. 效率提示
    // - push_back 和 += 在末尾操作通常是 O(1) 均摊时间复杂度。
    // - insert 在中间或开头操作是 O(n) 时间复杂度，因为需要移动后续字符。
    // - 如果需要频繁在开头插入，考虑使用 std::deque。

    return 0;
}
