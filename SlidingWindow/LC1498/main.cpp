#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

#define mod 10000000
/*
vector<vector<int>> ssq;
class Solution {
public:
    
    void subseq(vector<int> &num)
    {
        int size = num.size();
        int limit = (1 << size) ;
        int j = 0;
    
        vector<vector<int>> res;
        for(int i = 1; i < limit;i++)
        {
            vector<int> subset;
            while(j < size)
            {
                if((i & (1<<j)) != 0)
                {
                    subset.push_back(num[j]);
                }
                j++;
            }
            j = 0;
            ssq.push_back(subset);
        }
    }
    
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        subseq(nums);

        for(auto i: ssq)
        {
            for(auto j : i)
            {
                cout << j;
            }
            cout << endl;
        }

        cout << endl <<endl;

        int count = 0;

        for(int i = 0; i < ssq.size();i++)
        {
            if(ssq[i].front() + ssq[i].back() <= target)
            {
                count++;
            }
        }

        return count;
    }
};
*/

class Solution
{
public:

    int numSubseq(vector<int> &num, int k)
    {
        const int MOD = 1e9 + 7;
        vector<int> exp(num.size(),1);
        for(int i = 1; i < num.size(); i++)
        {
            exp[i] = (2 * exp[i-1]) % MOD;
        }

        sort(num.begin(), num.end());

        int left = 0;
        int right = num.size() -1;
        int count = 0;
        while(left <=right)
        {
            if(num[left] + num[right] > k)
            {
                right--; 
            }
            else
            {
                count = (count + exp[right - left]) % MOD;
                left--;
            }
        }

        return count;
    }

};
int main()
{
    Solution a;
    vector<int> b{3,3,6,8};
    cout << a.numSubseq(b, 10);
}