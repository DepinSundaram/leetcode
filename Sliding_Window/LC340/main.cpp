#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
/*
Given a string, find the length of the longest substring T that contains at most k distinct characters.
For example, Given s = “eceba” and k = 2,
T is "ece" which its length is 3.
*/
class Solution
{
public:
    int lengthOfLongestSubstringKDistinct(string &s, int k)
    {
        int maxf;
        int left =0;
        vector<int> count(26,0);
        int uniquechar = 0;
        for(int right = 0; right < s.length(); right++)
        {
            if(++count[s[right] - 'a'] == 1)
                uniquechar++;

            if(uniquechar == k)
            {
                 maxf =  max(maxf, right - left + 1);
            }
            else if(uniquechar > k)
            {
                while(uniquechar > k)
                {
                    if(count[s[left] - 'a'] == 1)
                    {
                        uniquechar--;
                    }
                    count[s[left++] -'a']--;

                }
            }

        }

        return maxf;
    }

};

int main()
{
    Solution a;
    string s = "aabacbebebe";
    cout << a.lengthOfLongestSubstringKDistinct(s, 3);
}