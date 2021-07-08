#include <iostream>
using namespace std;



/*

Populating Next Right Pointers in Each Node
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. 
If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Follow up:

You may only use constant extra space.
Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.
 

Example 1:

Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
 

Constraints:

The number of nodes in the given tree is less than 4096.
-1000 <= node.val <= 1000

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
// O(1) Space and O(n) Time (Iterative)
class Solution {
public:
    Node* connect(Node* root) {

        if(root == NULL)
            return root;

        Node* res = root;
        
        while(root->left)
        {
            Node* p = root;
            while(p)
            {
                p->left->next = p->right;
                if(p->next)
                    p->right->next = p->next->left;
                p = p->next;
            }
            root = root->left;
        }

        return res;
    }
};


class Solution2
{
public:
    Node* connect(Node* root) {

        if(root == NULL || root->left == NULL || root->right == NULL)
            return root;
        
        root->left->next = root->right;
        if(root->next)
            root->right->next = root->next->left;
        
        connect(root->left);
        connect(root->right);
        return root;
    }

};

class Solution3{

    void connect(TreeLinkNode *root) {
        if (!root) return; //Edge Case
        
        queue<TreeLinkNode*> q;
        
        //Trick: Push NULL to maintain depth information
        q.push(root);
        q.push(NULL);
        
        while(!q.empty())
        {
            TreeLinkNode* curr = q.front();
            q.pop();
            if (curr==NULL) 
            {
                if (q.size() > 0)
                    q.push(NULL);
            }
            else
            {
                curr->next = q.front();
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
            }
        }

    }
};