#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
    vector<vector<int>> result;
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        
        int n = nums.size();
        int limit = 1 << n;
        
        for(int i = 0; i < limit; i++)
        {
            vector<int> subset;
            
            for(int j = 0; j < n; j++)
            {
                if( (i >> j) & 1)
                {
                    cout << "index j : " << j << " index i : " << i << " \n";
                    subset.push_back(nums[j]);
                    cout << nums[j] ;
                }
                    
                
            }
            ans.push_back(subset);
            cout << endl;
        }
        
        return ans;
    }
};




int main()
{

    vector<int> nums = {1,2,3};
    Solution a;

    vector<vector<int>> res  = a.subsets(nums);
    
    for(auto a : res)
    {

    }

}