#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [1,3,2]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
Example 4:


Input: root = [1,2]
Output: [2,1]
Example 5:


Input: root = [1,null,2]
Output: [1,2]
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
//// Inorder Left Root Right
class Solution
{
public:
vector<int> inorderTraversal(TreeNode * root)
{
    vector<int> v;
    if(root == NULL)
        return v;
    
    stack<TreeNode*>st;

    while(1)
    {
        while(root)
        {
            st.push(root);
            root=root->left;
        }
        if(st.empty()==true)
            break;
        
        root=st.top();
        st.pop();
        v.push_back(root->val);
        root=root->right;
    }

    return v;

}

// Root left right
vector<int> preorderTraversal(TreeNode * root)
{
    vector<int> res;
    if(root == NULL)
        return res;
    stack<TreeNode*> st;

    while(1)
    {
        while(root)
        {
            res.push_back(root->val);
            st.push(root);
            root = root->left;
        }

        if(st.empty())
            break;
        
        root = st.top();
        st.pop();
        root = root->right;
    }
    return res;
}

// Root left right
vector<int> postorderTraversal(TreeNode * root)
{
    vector<int> res;
    if(root == NULL)
        return res;
    stack<TreeNode*> st;

    while(1)
    {
        while(root)
        {
            st.push(root);
            st.push(root);
            root = root->left;
        }

        if(st.empty())
            break;
        
        root = st.top();
        st.pop();
        if(st.empty() ==false && st.top()==root)
        {
            root=root->right;
        }
        else
        {
            res.push_back(root->val);
            root = NULL;
        }
    }
    return res;
}
};

class Moris {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> values;
        TreeNode *current = root;
        while(current != NULL){
            if (current->left == NULL){
                values.push_back(current->val);
                current = current->right;
            }else{
                TreeNode *predecessor = findPredecessor(current);
                if (predecessor->right == NULL){
                    predecessor->right = current;
                    values.push_back(current->val);
                    current = current->left;
                }else{
                    predecessor->right = NULL;
                    current = current->right;
                }
            }
        }
        return values;
    }
    TreeNode* findPredecessor(TreeNode* current){
        TreeNode* predecessor = current->left;
        while(predecessor->right != NULL && predecessor->right != current){
            predecessor = predecessor->right;
        }
        return predecessor;
    }
};

int main()
{
    /*TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    */

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);

    Solution a;
    vector<int> res = a.postorderTraversal(root);
    for(auto a: res)
        cout << a << endl;
    
    cout << endl; 
    vector<int> res1 = a.inorderTraversal(root);
    for(auto a: res1)
    cout << a << endl;
    
    cout << endl; 
    vector<int> res2 = a.preorderTraversal(root);

    for(auto a: res2)
        cout << a << endl;

    return 0;

}

