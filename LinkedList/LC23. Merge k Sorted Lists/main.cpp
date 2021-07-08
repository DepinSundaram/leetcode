#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int a) : data (a), next(NULL){}
};

class mycmp
{
    public:
    bool operator()(Node* a, Node* b)
    {
        return a->data > b->data;
    }
};
/*
class Solution {
public:
    Node* mergeKLists(vector<Node*>& lists) {

        int size = lists.size();
        Node* head = nullptr;
        Node* temp = head;
        priority_queue<Node*, vector<Node*>, mycmp> pq;

        for(int i = 0; i< size; i++)
        {
            if(lists[i]!=nullptr)
                pq.push(lists[i]);
        } 

        while(!pq.empty())
        {
            Node* curr = pq.top();
            pq.pop();
            Node* t = new Node(curr->data);

            if(head!=nullptr)
            {
                temp->next = t;
                temp=temp->next;
            }else
            {
                head = temp = t;
            }

            if(curr->next!=nullptr)
                pq.push(curr->next);
        }       

        return head;
    }
};
*/

/*
Time complexity : O(Nlogk) where k is the number of linked lists.

The comparison cost will be reduced to O(logk) for every pop and
insertion to priority queue. But finding the node with the smallest value just costs O(1) time.
There are N nodes in the final linked list.
Space complexity :

O(n) Creating a new linked list costs O(n) space.
O(k) The code above present applies in-place method which cost O(1) space.
And the priority queue (often implemented with heaps) costs O(k) space (it's far less than N in most situations).

*/

class comp
{
    public:
    bool operator()(Node* a, Node*b)
    {
        return a->data > b->data;
    }
};
class Solution1{ // 
public:
    Node* mergeKLists(vector<Node*>& list)
    {
        int size = list.size();

        priority_queue<Node*, vector<Node*>, comp> q;

        Node* res = NULL;
        Node* Itemp = NULL;
        for(int i = 0; i < size ; i++)
        {
            if(list[i]!=nullptr)
                q.push(list[i]);
        }

        while(!q.empty())
        {
            Node* top = q.top();
            q.pop();
            Node* t = new Node(top->data);

            if(res!=nullptr)
            {
                Itemp->next = t;
                Itemp = Itemp->next;
            }
            else
            {
                res = Itemp = t;
            }

            if(top->next!=nullptr)
                q.push(top->next);
        }

    return res;
    }
};

int main()
{
    int k =  3;
    Node* arr[k];

    arr[0] = new Node(1);
    arr[0]->next = new Node(3);
    arr[0]->next->next = new Node(5);

    arr[1] = new Node(2);
    arr[1]->next = new Node(4);

    arr[2] = new Node(0);
    arr[2]->next = new Node(9);
    arr[2]->next->next = new Node(10);


    vector<Node*> list;
    list.push_back(arr[0]);
    list.push_back(arr[1]);
    list.push_back(arr[2]);

    Solution1 a;
    Node* res = a.mergeKLists(list);
}