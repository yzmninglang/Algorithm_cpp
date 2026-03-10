#include <iostream>

/**
 * @brief 链表反转 (Reverse Linked List)
 * 
 * 核心思想：
 * 1. 使用三个指针：prev (前驱), curr (当前), next (后继)。
 * 2. 遍历链表，将当前节点的 next 指向前一个节点。
 * 3. 移动指针，继续处理下一个节点。
 */

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}

    void add(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    // 链表反转函数
    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;  // 1. 保存下一个节点
            curr->next = prev;  // 2. 反转当前节点的指针
            prev = curr;        // 3. prev 向前移动
            curr = next;        // 4. curr 向前移动
        }
        head = prev;             // 5. 更新头指针
    }

    void print() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    }

    ~LinkedList() {
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};

int main() {
    LinkedList list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);

    std::cout << "Original ";
    list.print();

    std::cout << "Reversing..." << std::endl;
    list.reverse();

    std::cout << "Reversed ";
    list.print();

    return 0;
}
