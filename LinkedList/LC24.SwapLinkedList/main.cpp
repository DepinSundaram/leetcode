#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node* next;
    Node(int a): val(a), next(nullptr){}
};

Node* SwapTwoLinks(Node* head)
{
    Node* dummy = new Node(-1);
    Node* prev = dummy;
    Node* current = head;

    while(current !=NULL && current->next!=NULL)
    {
        prev->next = current->next;
        current->next = current->next->next;
        prev->next->next = current;
        current = current->next;
        prev = prev->next->next;
    }

    return dummy->next;

}
int main()
{
    Node* head =  new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    Node* newList = SwapTwoLinks(head);
    cout << "DONE";
}