#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
/*
Given two integer arrays preorder and inorder where preorder is 
the preorder traversal of a binary tree and inorder is the inorder 
traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]

*/


 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  }; 


class Solution
{

public:
    unordered_map<int, int> mp;
    TreeNode* createTreeFromPostIn(vector<int>& preorder, vector<int>& inorder, int start, int end, int idx)
    {
            if(start > end)
                return NULL;
            TreeNode* root = new TreeNode(preorder[idx]);

            int rootIdx = mp[preorder[idx]];

            root->left = createTreeFromPostIn(preorder, inorder, start, rootIdx - 1, idx + 1 );
            root->right = createTreeFromPostIn(preorder, inorder, rootIdx + 1, end, idx + rootIdx -start + 1);

            return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }

        return createTreeFromPostIn(preorder, inorder, 0, inorder.size() -1, 0);
    }
};


int main()
{
vector<int> inorder = {9,3,15,20,7};
vector<int> preorder = {3,9,20,15,7};
Solution a;
TreeNode* res = a.buildTree(preorder, inorder);

cout << "EXIT";

}