#include <iostream>
#include <vector>

/**
 * @brief 简单的二叉树实现 (Simple Binary Tree)
 * 
 * 二叉树是每个节点最多有两个子树的树结构。
 * 通常子树被称作“左子树”和“右子树”。
 */

// 1. 定义二叉树节点
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 2. 二叉树遍历 (前序、中序、后序)
class BinaryTree {
public:
    TreeNode* root;

    // 初始化一个空指针
    
    BinaryTree() : root(nullptr) {}

    // 前序遍历: 根 -> 左 -> 右
    void preOrder(TreeNode* node) {
        if (!node) return;
        std::cout << node->val << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    // 中序遍历: 左 -> 根 -> 右
    void inOrder(TreeNode* node) {
        if (!node) return;
        inOrder(node->left);
        std::cout << node->val << " ";
        inOrder(node->right);
    }

    // 后序遍历: 左 -> 右 -> 根
    void postOrder(TreeNode* node) {
        if (!node) return;
        postOrder(node->left);
        postOrder(node->right);
        std::cout << node->val << " ";
    }

    /**
     * @brief 寻找最近公共祖先 (Lowest Common Ancestor)
     *
     * 算法思路：
     * 1. 如果当前节点为空，或者当前节点就是 p 或 q，则返回当前节点。
     * 2. 递归在左子树中寻找 p 和 q。
     * 3. 递归在右子树中寻找 p 和 q。
     * 4. 如果左子树和右子树都找到了（都不为空），说明当前节点就是 LCA。
     * 5. 如果只有一边找到了，返回找到的那一边。
     */
    TreeNode* lowestCommonAncestor(TreeNode* node, TreeNode* p, TreeNode* q) {
        if (!node || node == p || node == q) return node;

        TreeNode* left = lowestCommonAncestor(node->left, p, q);
        TreeNode* right = lowestCommonAncestor(node->right, p, q);

        if (left && right) return node;
        return left ? left : right;
    }

    // 析构函数释放内存
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
         / \
        4   5
    */
    tree.root = new TreeNode(1);
    tree.root->left = new TreeNode(2);
    tree.root->right = new TreeNode(3);
    tree.root->left->left = new TreeNode(4);
    tree.root->left->right = new TreeNode(5);

    std::cout << "Pre-order traversal: ";
    tree.preOrder(tree.root);
    std::cout << std::endl;

    std::cout << "In-order traversal: ";
    tree.inOrder(tree.root);
    std::cout << std::endl;

    std::cout << "Post-order traversal: ";
    tree.postOrder(tree.root);
    std::cout << std::endl;

    // 测试 LCA
    TreeNode* p = tree.root->left->left; // 4
    TreeNode* q = tree.root->left->right; // 5
    TreeNode* lca = tree.lowestCommonAncestor(tree.root, p, q);
    if (lca) {
        std::cout << "LCA of " << p->val << " and " << q->val << " is: " << lca->val << " (Expected: 2)" << std::endl;
    }

    p = tree.root->left->left; // 4
    q = tree.root->right; // 3
    lca = tree.lowestCommonAncestor(tree.root, p, q);
    if (lca) {
        std::cout << "LCA of " << p->val << " and " << q->val << " is: " << lca->val << " (Expected: 1)" << std::endl;
    }

    return 0;
}
