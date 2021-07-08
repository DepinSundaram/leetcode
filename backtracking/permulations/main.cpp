#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> result;
public:
    void permutation(vector<int>& nums, int idx)
    {
        if(nums.size() == idx)
        {
            result.push_back(nums);
            return;
        }

        for(int i = idx; i < nums.size(); i++)
        {
            swap(nums[i], nums[idx]);
            permutation(nums, idx+1);
            swap(nums[i], nums[idx]);
        }

        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {

        if(nums.size() <=1)
            return {nums};
        
        permutation(nums, 0);

        return result;

        
        /*if(nums.size() <= 1)
            return {nums};
        
        vector<vector<int>> res;
        for(int i = 0; i < nums.size(); ++i)
        {
            vector<int>  v(nums.begin(), nums.end());
            v.erase(v.begin() + i);
            auto res = permute(v);

            for(int j = 0 ; j < res.size(); j++)
            {
                vector<int> vec = res[j];
                vec.insert(vec.begin(), nums[i]);
                res.push_back(vec);
            }
        }
        return res;*/
    }
};


int main()
{
    Solution a;
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = a.permute(nums);
    cout << "END";

    
}