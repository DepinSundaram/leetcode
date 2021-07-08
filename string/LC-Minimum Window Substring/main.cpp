#include <iostream>
#include <string.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {

        if(s.length() == 0 || s.length() < t.length())
            return "";

        unordered_map<char, int> mp;

        int right = 0;
        int start = 0;
        int count = 0;
        int minLeft = 0;
        int len = INT_MAX;
        for(char c : t)
        {
            mp[c]++;
        }

        for(int i = 0; i < s.length(); i++)
        {
            if(mp.count(s[i]))
            {
                mp[s[i]]--;

                if(mp[s[i]] >=0)
                    count++;
            }

            while(count ==  t.size())
            {
                if(len > i - start + 1 )
                {
                    len = i - start + 1;
                    minLeft = start;
                }

                if(mp.find(s[start])!=mp.end())
                {
                    mp[s[start]]++;
                    if(mp[s[start]] > 0)
                        count--;
                }
                start++;
            }
        }

         if(len>s.length())
            return "";
        
        return s.substr(minLeft, len);
        
    }
};

int main()
{
    string s = "ADOBECODEBANC";

    string t = "ABC";

    Solution a;

    string res =  a.minWindow(s, t);
    cout << res;
}