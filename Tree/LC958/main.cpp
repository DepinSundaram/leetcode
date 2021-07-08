
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr) {};
};

class Solution
{
public:
    bool BalancedTree(TreeNode* root)
    {
        queue<TreeNode*> q;
        bool check = true;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            
            if(node == NULL)
            {
                check = false;  
            }
            else 
            {
                if(check == false)
                {
                    return false;
                }
                q.push(node->left);
                q.push(node->right);
            }
        }
        
        return true;
    }
};



int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    Solution a;
    cout << a.BalancedTree(root) << endl;
    cout << "END";
}