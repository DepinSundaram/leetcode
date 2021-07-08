#include <iostream>
#include <vector>

using namespace std;
struct Node
{
    int data;
    Node* next;
    Node(int a) : data(a), next(nullptr){}
};


Node* mergeKGroup(Node* head, int k)
{
    if(head == NULL || k == 1)
        return head;
    
    int count = 0;
    Node* dummy = new Node(0);
    dummy->next = head;
    Node* curr = dummy;
    Node* pre = dummy;
    Node* nxt = dummy;
    while(curr->next!=NULL)
    {
        curr = curr->next;
        count++;
    }

    while(count>=k)
    {
        curr = pre->next;
        nxt = curr->next;
        for(int i = 1; i <k;i++)
        {
            curr->next = nxt->next;
            nxt->next = pre->next;
            pre->next = nxt;
            nxt = curr->next;
        }
        pre=curr;
        count-=k;
    }

    return dummy->next;

}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    
    Node* res = mergeKGroup(head, 3);
    cout << "END";
}