#include <iostream>
using namespace std;



/*
  Populating Next Right Pointers in Each Node II

Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 

Follow up:

You may only use constant extra space.
Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.
 

Example 1:



Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
 

Constraints:

The number of nodes in the given tree is less than 6000.
-100 <= node.val <= 100


            1 --- > NULL
        2 ----->3 --> NULL
    4 -------------> 7 --> NULL          

*/

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node* connect(Node* root) {

        if(root == NULL)
            return NULL;
        
        Node* head = root;

        while(head!=NULL)
        {
            Node* h = new Node(0);
            Node* temp = h;

            while(head!=NULL)
            {
                if(head->left)
                {
                    temp->next = head->left;
                    temp = temp->next;
                }
                if(head->right)
                {
                    temp->next = head->right;
                    temp = temp->next;
                }
                head = head->next;
            }
            head = h->next;
        }
        return root;
    }

};


int main()
{

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    Solution a;
    Node* res = a.connect(root);

    cout << "END";
}