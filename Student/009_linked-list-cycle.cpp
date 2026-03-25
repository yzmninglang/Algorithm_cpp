#include <iostream>
// using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int val): data(val),next(nullptr){}
};


void PrintNode(Node* n1){
    Node* tmp = n1;
    // std::cout<<"hello:"<<tmp->next->data<<std::endl;
    // std::cout<<tmp->data<<std::endl;
    while (tmp != nullptr)
    {
        std::cout<<tmp->data<<std::endl;
        tmp =tmp->next;
    }
    return;
}

bool cycle_check (Node* link)
{
    Node* fast_ptr;
    Node* slow_ptr;
    fast_ptr = link;
    slow_ptr = link;
    // 这个地方必须要小心fast_ptr的next为空的情况
    while (fast_ptr->next != nullptr)
    {
        fast_ptr= fast_ptr->next;
        if (fast_ptr->next !=nullptr)
        {
            fast_ptr = fast_ptr->next;
        }
        slow_ptr = slow_ptr->next;
        if (fast_ptr == slow_ptr)
        {
            return true;
        }
    }
    return false;
}

Node* find_k_reverse(int k,Node* l1)
{
    Node* tmp=l1;
    while(l1 != nullptr)
    {
        for(int i =0;i<k-1;i++)
        {
            tmp=tmp->next;
        }
        if(tmp->next == nullptr)
        {
            break;
        }
        l1=l1->next;
        tmp = l1;
    }
    return l1;
}

Node* find_k_reverse2(int k,Node* l1)
{
    Node* pre=nullptr;
    Node* current =l1;
    Node* next=current->next;
    while (current !=nullptr)
    {
        current->next = pre;
        pre = current;
        current = next;
        // 如果curren是最后的一个指针的next，那么current就没有next了
        if (current != nullptr)
        {
            next = current->next;
        }
    }
    current = pre;
    for(int i=0;i<k-1;i++)
    {
        current=current->next;
    }
    return current;
    
}

Node* Merge_Node(Node* n1, Node* n2)
{
    Node dump(0);
    Node* tail = &dump;
    // n1和n2不为空
    while (n1 && n2)
    {
       if(n1->data < n2->data)
       {
            tail->next = new Node(n1->data);
            n1 = n1->next;
       }
       else
       {
            tail->next = new Node(n2->data);
            n2 = n2->next;
       }
       tail = tail->next;
    }
    // 剩下谁就挂谁
    tail->next = n1 ? n1:n2;
    // std::cout<<dump.next->next->data<<std::endl;
    return dump.next;
}

int main()
{
    Node* head1 = new Node(1);
    Node* head2 = new Node(2);
    Node* head3 = new Node(3);
    Node* head4 = new Node(8);
    Node* Link1 = nullptr;
    head1->next = head2;
    head2->next = head3;
    head3->next = head4;
    Link1 = head1;
    
    std::cout<<"link1:"<<cycle_check(Link1)<<std::endl;

    head1 = new Node(4);
    head2 = new Node(5);
    head3 = new Node(6);
    head4 = new Node(7);
    Node* Link2 = nullptr;
    head1->next = head2;
    head2->next = head3;
    head3->next = head4;
    // head4->next = head2;
    Link2 = head1;

    std::cout<<"link2:"<<cycle_check(Link2)<<std::endl;

    Node* Link3 = Merge_Node(Link1,Link2);
    // std::cout<<"link3:"<<Link3->data<<std::endl;
    PrintNode(Link3);

    Node* reverse_link = find_k_reverse2(1,Link3);
    std::cout<<"reverse_link"<<reverse_link->data<<std::endl;

    // std::cout<<node1.data;
    return 0;
}