#include<iostream>

struct Node
{
    int data;
    Node* next;
    Node(int val): data(val), next(nullptr){};
};



class Simpledatalink
{
private:
    Node* head;
public:
    Simpledatalink():head(nullptr){};
    void add(int val){
        Node* Newnode = new Node(val);
        if(head == nullptr){
                head = Newnode;
                return;
        }
        Node* temp =head;
        while (temp->next != nullptr)
        {
           temp=temp->next;
        }
        temp->next = Newnode;
        
    };

    void print(){
        Node* temp = head;
        while (temp->next != nullptr)
        {
            std::cout<<temp->data<<std::endl;
            temp = temp->next;
        }
        std::cout<<temp->data<<std::endl;
        
    }

    void reverse();

    ~Simpledatalink()
    {
        Node* temp = head;
        while (head !=nullptr)
        {
            temp= head;
            head=head->next;
            std::cout<<"现在正在删除的是："<<temp->data<<std::endl;
            delete temp;
        }
        
    };
};

void Simpledatalink::reverse()
{
    Node *temp1 = head->next;
    Node *temp2 = temp1->next;
    head->next = nullptr;
    temp1->next = head;
    while (temp2->next != nullptr)
    {
        head = temp1;
        temp1 = temp2;
        temp2 = temp1->next;
        temp1->next = head;
    }
    temp2->next = temp1;
    head = temp2;
}

int main()
{
    Simpledatalink s1;
    s1.add(10);
    s1.add(12);
    s1.add(32);
    s1.print();
    s1.reverse();
    s1.print();

    return 0;
}