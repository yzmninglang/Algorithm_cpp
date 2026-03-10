#include <iostream>

/**
 * @brief 链表环检测 (Linked List Cycle Detection)
 * 
 * 核心算法：快慢指针 (Floyd's Cycle-Finding Algorithm)
 * 1. 定义两个指针：slow (慢指针) 和 fast (快指针)。
 * 2. slow 每次走 1 步，fast 每次走 2 步。
 * 3. 如果链表有环，fast 最终会追上 slow (两者相等)。
 * 4. 如果 fast 到达 NULL，说明链表无环。
 */

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

bool hasCycle(Node* head) {
    if (!head || !head->next) return false;

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;          // 走 1 步
        fast = fast->next->next;    // 走 2 步

        if (slow == fast) {         // 相遇，说明有环
            return true;
        }
    }
    return false;                   // 到达末尾，无环
}

int main() {
    // 1. 创建一个无环链表: 1 -> 2 -> 3
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    std::cout << "List 1 (1->2->3) has cycle: " << (hasCycle(head1) ? "Yes" : "No") << std::endl;

    // 2. 创建一个有环链表: 1 -> 2 -> 3 -> (回到 2)
    Node* head2 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    head2->next = node2;
    node2->next = node3;
    node3->next = node2; // 制造环
    std::cout << "List 2 (1->2->3->2) has cycle: " << (hasCycle(head2) ? "Yes" : "No") << std::endl;

    // 注意：有环链表不能直接 delete，否则会死循环。
    // 实际开发中需要先断开环再释放内存。
    node3->next = nullptr; 
    delete head1->next->next; delete head1->next; delete head1;
    delete head2->next->next; delete head2->next; delete head2;

    return 0;
}
