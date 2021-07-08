#include <iostream>

using namespace std;

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
int sum = 0;
    int inorder(TreeNode* root, int low, int high)
    {
        if(root)
        {
            inorder(root->left, low, high);
            if(root->val>=low && root->val<=high)
                sum += root->val;
            inorder(root->right, low, high);
        }
        return sum;
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        return inorder(root, low, high);
    /*
        int sum = 0;
    int rangeSumBST(TreeNode* root, int low, int high) {
         
        if(root == NULL)
            return sum;
        if(root->val < low)
            rangeSumBST(root->right, low, high);
        if(root->val > high)
            rangeSumBST(root->left, low, high);
        if(root->val >= low&& root->val <=high)
        {
            sum = sum + root->val;
            rangeSumBST(root->left,low, high);
            rangeSumBST(root->right, low, high);
        }
        return sum;
        
    }
    */
    }
};
int main()
{
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(18);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->left->left->left = new TreeNode(1);
    root->left->right->left = new TreeNode(6);
    Solution a;
    cout << a.rangeSumBST(root, 6,10);
}