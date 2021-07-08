/*
We are given a binary tree (with root node root), a target node, and an integer value k.

Return a list of the values of all nodes that have a distance k from the target node.  The answer can be returned in any order.

 

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]

Explanation: 
The nodes that are a distance 2 from the target node (with value 5)
have values 7, 4, and 1.



Note that the inputs "root" and "target" are actually TreeNodes.
The descriptions of the inputs above are just serializations of these objects.

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
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
    unordered_map<TreeNode*, TreeNode*> mp;
    unordered_set<TreeNode*> visited;
    void connectParents(TreeNode* root, TreeNode* parent )
    {
        if(root == NULL) return ;

        mp[root] = parent;
        connectParents(root->left,root);
        connectParents(root->right, root);
    }

    void dfs(TreeNode* target, int k, vector<int> &res)
    {
        if(target== NULL) return;
        if(visited.count(target)==true) return ;
        visited.insert(target);
        if(k==0)
        {
            res.push_back(target->val);
            return;
        }
        dfs(target->left, k-1, res);
        dfs(target->right, k-1, res);
        dfs(mp[target],k-1, res);

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        if(root== NULL) return res;
        connectParents(root,NULL);
        dfs(target, k, res);
        return res;
    }
};
  int main()
  {

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left =  new TreeNode(0);
    root->right->right = new TreeNode(8);

    Solution a;
    vector<int> res = a.distanceK(root,root->left,2);

    for(auto a: res)
        cout << a << " ";
  }