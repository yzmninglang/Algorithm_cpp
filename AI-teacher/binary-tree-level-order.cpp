#include <iostream>
#include <queue>
#include <vector>

/**
 * @brief 二叉树层序遍历 (Binary Tree Level Order Traversal)
 * 
 * 核心思想：
 * 1. 使用队列 (Queue) 实现广度优先搜索 (BFS)。
 * 2. 将根节点入队。
 * 3. 当队列不为空时：
 *    a. 弹出队首节点。
 *    b. 访问该节点。
 *    c. 将其左子节点和右子节点（如果存在）入队。
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    TreeNode* root;
    BinaryTree() : root(nullptr) {}

    // 层序遍历
    void levelOrder() {
        if (!root) return;

        std::queue<TreeNode*> q;
        q.push(root);

        std::cout << "Level-order traversal: ";
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            std::cout << curr->val << " ";

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        std::cout << std::endl;
    }

    void destroyTree(TreeNode* node) {
        if (!node) return;
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

    ~BinaryTree() {
        destroyTree(root);
    }
};

int main() {
    BinaryTree tree;
    /* 创建如下结构的二叉树:
             1
           /   \
          2     3
         / \   / \
        4   5 6   7
    */
    tree.root = new TreeNode(1);
    tree.root->left = new TreeNode(2);
    tree.root->right = new TreeNode(3);
    tree.root->left->left = new TreeNode(4);
    tree.root->left->right = new TreeNode(5);
    tree.root->right->left = new TreeNode(6);
    tree.root->right->right = new TreeNode(7);

    tree.levelOrder(); // 预期输出: 1 2 3 4 5 6 7

    return 0;
}
