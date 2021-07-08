#include <iostream>
#include <vector>

using namespace std;

/*

Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.

 

Example 1:


Input: n = 3
Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
Example 2:

Input: n = 1
Output: [[1]]
 

Constraints:

1 <= n <= 8
*/

struct TreeNode
{
    int val;
    TreeNode* left,*right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<TreeNode*> Helper(int start, int end)
    {
        vector<TreeNode*> v;
        if(start > end)
        {
            v.push_back(NULL);
            return v;
        }
        for(int i = start; i <=end; i++)
        {
            vector<TreeNode*> left = Helper(start, i-1);
            vector<TreeNode*> right = Helper(i+1, end);
            for(TreeNode* l : left)
            {
                for(TreeNode* r : right)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    v.push_back(root);
                }
            }
        }
        return v;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return vector<TreeNode*>();
        return Helper(1,n);
    }
};

int main()
{
    Solution a;
    vector<TreeNode*> res =  a.generateTrees(3);
    int s = res.size();
    cout << s;
}