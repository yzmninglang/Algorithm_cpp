#include <iostream>

/**
 * @brief 合并两个有序链表 (Merge Two Sorted Lists)
 * 
 * 核心思想：
 * 1. 使用一个虚拟头节点 (dummy node) 简化操作。
 * 2. 比较两个链表的当前节点，将较小的节点连接到结果链表。
 * 3. 移动指针，直到其中一个链表为空。
 * 4. 将剩余的链表部分直接连接到结果链表末尾。
 */

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* mergeTwoLists(Node* l1, Node* l2) {
    Node dummy(0); // 虚拟头节点
    Node* tail = &dummy;

    while (l1 && l2) {
        if (l1->data < l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // 连接剩余部分
    tail->next = l1 ? l1 : l2;

    return dummy.next;
}

void printList(Node* head) {
    while (head) {
        std::cout << head->data << " -> ";
        head = head->next;
    }
    std::cout << "NULL" << std::endl;
}

int main() {
    // 链表 1: 1 -> 3 -> 5
    Node* l1 = new Node(1);
    l1->next = new Node(3);
    l1->next->next = new Node(5);

    // 链表 2: 2 -> 4 -> 6
    Node* l2 = new Node(2);
    l2->next = new Node(4);
    l2->next->next = new Node(6);

    std::cout << "List 1: "; printList(l1);
    std::cout << "List 2: "; printList(l2);

    Node* merged = mergeTwoLists(l1, l2);
    std::cout << "Merged: "; printList(merged);

    // 释放内存
    while (merged) {
        Node* temp = merged;
        merged = merged->next;
        delete temp;
    }

    return 0;
}
