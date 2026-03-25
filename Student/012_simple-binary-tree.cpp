#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include<unordered_set>


struct treenode
{
    int data;
    treenode* left;
    treenode* right;
    treenode(int val) : data(val),left(nullptr),right(nullptr){};
};



class Tree
{
public:
    treenode* root;
    Tree():root(nullptr){};
    void PreOrder(treenode* node);
    void midOrder(treenode* node);
    void postOrder(treenode* node);
    void destorytree(treenode* node);
    void leveorder();
    treenode* findLCA(treenode* root,treenode* p ,treenode* q);
    treenode* lca(treenode* node1,treenode* node2);
    treenode* lca_iterative(treenode*p ,treenode*q);
    ~Tree();
};

void Tree::PreOrder(treenode* node)
{
    if(node==nullptr)
    {
        return;
    }
    std::cout<<node->data<<std::endl;
    PreOrder(node->left);
    PreOrder(node->right);
    return;
}
void Tree::midOrder(treenode* node)
{
    if(node==nullptr)
    {
        return;
    }
    midOrder(node->left);
    std::cout<<node->data<<std::endl;
    midOrder(node->right);
    return;
}
void Tree::postOrder(treenode* node)
{   
    if(node==nullptr)
    {
        return;
    }
    postOrder(node->left);
    postOrder(node->right);
    std::cout<<node->data<<std::endl;
    return;
}

void Tree::destorytree(treenode* node)
{
    destorytree(node->left);
    destorytree(node->right);
    delete node;
}

Tree::~Tree()
{
    destorytree(root);
}


void Tree::leveorder()
{
    if (this->root == nullptr)
    {
        return;
    }
    treenode* tmp;
    std::queue<treenode*> q;
    q.push(root);
    while (!q.empty())
    {
        tmp = q.front();
        q.pop();
        std::cout<<tmp->data;
        if(tmp->left)
        {q.push(tmp->left);}
        if(tmp->right)
        {q.push(tmp->right);}
    }
}

treenode* Tree::findLCA(treenode* root,treenode* p ,treenode* q)
{
    if(root==q || root==p || root==nullptr)
    {
        return root;
    }
    treenode* left = this->findLCA(root->left,p,q);
    treenode* right = this->findLCA(root->right,p,q);
    if(left && right)
    {
        return root;
    }
    return (left!=nullptr)? left:right;
}



treenode* Tree::lca(treenode* node1,treenode* node2)
{
    std::queue<treenode*> treequeue;
    treenode* father1 =nullptr;
    treenode* father2 = nullptr;
    treenode* temp = nullptr;
    while (father1 != father2)
    {
        treequeue.push(this->root);
        while(!treequeue.empty())  
        {
            treequeue.push(this->root);
            temp=treequeue.front();
            treequeue.pop();
            if(!temp->left)
            {treequeue.push(temp->left);}
            if(!temp->right)
            {treequeue.push(temp->right);}
            if(temp->left == node1 || temp->right ==node1)
            {
                father1=temp;
            }
            if(temp->left == node2 || temp->right ==node2)
            {
                father2=temp;
            }
        }
        node1 = father1;
        node2 = father2;
    }
    
    return father1;

}

// ... existing code ...
#include <unordered_map>
#include <unordered_set>
#include <queue>


treenode* Tree::lca_iterative(treenode*p ,treenode*q)
{
    std::queue<treenode*> temp_queue;
    std::unordered_set<treenode*> set_q;
    temp_queue.push(this->root);
    std::unordered_map<treenode*,treenode*> map_father;
    map_father[root]= nullptr;
    while (!temp_queue.empty())
    {
        /* code */
        treenode* tmp_node = temp_queue.front();
        if(tmp_node->left)
        {
            map_father[tmp_node->left] = tmp_node;
            temp_queue.push(tmp_node->left);
        }
        if (tmp_node->right)
        {
            map_father[tmp_node->right] = tmp_node;
            temp_queue.push(tmp_node->right);
        }
        temp_queue.pop();
    }
    while (q)
    {
        set_q.insert(q);
        q = map_father[q];
    }

    while (set_q.find(p)==set_q.end() && p!=nullptr)
    {
        /* code */
        p = map_father[p];
    }
    return p;

}
int main()
{
    Tree tree;
    tree.root = new treenode(1);
    tree.root->left = new treenode(2);
    tree.root->right = new treenode(3);
    tree.root->left->left = new treenode(4);
    tree.root->left->right = new treenode(5);
    treenode* node1 = tree.root->left->left;
    treenode* node2 = tree.root->left->right;
    treenode* father = tree.findLCA(tree.root,node1,node2);

    std::cout << "LCA: ";
    // tree.lca(node1,node2);
    std::cout <<father->data <<std::endl;

    father = tree.lca_iterative(node1,node2);
    std::cout << "lca_iterative: ";
    std::cout <<father->data <<std::endl;

    std::cout << "Pre-order traversal: ";
    tree.PreOrder(tree.root);
    std::cout << std::endl;

    std::cout << "mid-order traversal: ";
    tree.midOrder(tree.root);
    std::cout << std::endl;

    std::cout << "Post-order traversal: ";
    tree.postOrder(tree.root);
    std::cout << std::endl;

    std::cout << "level-order traversal: ";
    tree.leveorder();
    std::cout << std::endl;
}