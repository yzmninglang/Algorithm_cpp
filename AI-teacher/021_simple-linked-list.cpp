#include <iostream>

/**
 * @brief 简单的单向链表实现 (Simple Singly Linked List)
 * 
 * 链表是一种物理存储单元上非连续、非顺序的存储结构。
 * 数据元素的逻辑顺序是通过链表中的指针链接次序实现的。
 */

// 1. 定义节点结构
struct Node {
    int data;       // 数据域
    Node* next;     // 指针域：指向下一个节点

    Node(int val) : data(val), next(nullptr) {}
};

// 2. 定义链表类
class SimpleLinkedList {
private:
    Node* head;     // 头指针：指向链表的第一个节点

public:
    SimpleLinkedList() : head(nullptr) {}

    // 在链表末尾添加元素
    void add(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // 遍历并打印链表
    void print() {
        Node* temp = head;
        std::cout << "List: ";
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    }

    // 析构函数：释放动态分配的内存
    ~SimpleLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            std::cout << "Deleting node with data: " << current->data << std::endl;
            delete current;
            current = next;
        }
        head = nullptr;
    }
};

int main() {
    SimpleLinkedList myList;

    // 添加一些数据
    myList.add(1);
    myList.add(2);
    myList.add(3);
    myList.add(4);

    // 打印链表
    myList.print();

    return 0;
}
