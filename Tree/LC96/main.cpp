/*
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.


Example 1:
Input: n = 3
Output: 5
Example 2:

Input: n = 1
Output: 1


*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if(n==1 || n == 0) return 1;
        
        vector<int> res;
        res.push_back(1);
        res.push_back(1);
        
        for(int i =2; i <= n; i++)
        {
            int sum = 0;
            for(int j = 0; j < i ; j++)
            {
                sum += res[j]*res[i-1-j];
            }
            res.push_back(sum);
        }
        return res[n];
        
    }
};
int main()
{
    Solution a;
    cout << a.numTrees(3);
}