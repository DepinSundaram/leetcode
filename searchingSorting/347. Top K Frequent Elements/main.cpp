#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;
        vector <int> res;
        for(int i = 0; i < nums.size();i++)
        {
            mp[nums[i]]++;
        }
        
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mh;
        
        for(auto i = mp.begin(); i !=mp.end(); i++)
        {
            mh.push({i->second, i->first});
            if(mh.size() > k)
                mh.pop();
        }
        
        while(mh.size() > 0)
        {
            res.push_back(mh.top().second);
            cout <<  mh.top().second << endl;
            mh.pop();
        }

        return res;
    }
};

int main()
{
    vector<int> nums = {1,1,1,2,2,3};
    Solution a;
    vector<int> res = a.topKFrequent(nums, 2); 
}