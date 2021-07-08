#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int>& nums, int x)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        int sum = 0;
        for(int i  = 0; i < n; ++i)
        {
            sum +=nums[i];
            mp[sum] = i;
        }

        if(sum < x)
            return -1;

        mp[0] = 0;
        int longest = 0;
        int val = 0;
        sum -=x;

        for(int i = 0; i < n; ++i)
        {
            val +=nums[i];
            if(mp.count(val-sum))
            {
                if(val - sum == 0)
                {
                    longest = max(longest, i - mp[val-sum] +1);
                }
                else
                    longest = max(longest, i - mp[val-sum]);

            }
        }
        return longest==0?(sum==0?n:-1):n-longest;
    }

};

class LC1456
{
public:
    int vowel(string& s, int k)
    {
        vector<char> v {'a','e','i','o','u'};

        int count = 0;
        int left = 0;
        int v_max = 0;
        int right = 0;
        int len= s.length();
        while(right < len)
        {
            if(std::count(v.begin(), v.end(), s[right]))
            {
                count++;  
            }

            while(right - left + 1 == k)
            {
                if(count > 0)
                {
                    v_max = max(v_max, count);
                }

                if(std::count(v.begin(), v.end(), s[left]))
                    count--;

                left++;   
            }
            right++;
        }

        return v_max;
    }
};

int main()
{
   // Solution a;
    //vector<int> nums = {3,2,20,1,1,3};
    //cout << a.minOperations(nums,10);
    LC1456 b;
    string s = "leetcode";
    cout << b.vowel(s, 3);

    return 0;

}