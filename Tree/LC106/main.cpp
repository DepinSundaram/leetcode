#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
/*
  Construct Binary Tree from Inorder and Postorder Traversal

Given two integer arrays inorder and postorder where inorder
is the inorder traversal of a binary tree and postorder is the 
postorder traversal of the same tree, construct and return the binary tree.

Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]

https://www.youtube.com/watch?v=TblhNX9AQ3M&t=427s
*/


 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


class Solution {
public:
    unordered_map<int, int> mp;
    TreeNode* constructBinaryTree(vector<int>& inorder,vector<int>& postorder, int start, int end, int idx)
    {

        if(start > end) return NULL;

        TreeNode* root = new TreeNode(postorder[idx]);

        int InRootIdx = mp[postorder[idx]];

        root->left = constructBinaryTree(inorder, postorder,start, InRootIdx - 1 , idx - (end-InRootIdx) -1);
        root->right = constructBinaryTree(inorder, postorder, InRootIdx + 1, end, idx -1);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }

        return constructBinaryTree(inorder,postorder, 0,  inorder.size() -1 ,postorder.size() -1 );
    }
};


int main()
{
vector<int> inorder = {9,3,15,20,7};
vector<int> postorder = {9,15,7,20,3};
Solution a;
TreeNode* res = a.buildTree(inorder, postorder);

cout << "EXIT";

}