#include <iostream>

using namespace std;


struct Node
{
    int val;
    Node* next;
    Node(int a): val(a), next(nullptr){}
};
Node* head;
void ReverseLinkedList(Node* p)
{

    if(p->next == NULL)
    {
        head = p;
        return ;
    }
    ReverseLinkedList(p->next);
    Node* q = p->next;
    q->next = p;
    p->next = NULL;
}
int main()
{
    Node* head =  new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    ReverseLinkedList(head);
    cout << "DONE";
}
