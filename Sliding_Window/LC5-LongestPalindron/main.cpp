#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    
    string find(string s, int l, int r)
    {
        while(l>=0 && r<s.size()&&s[l]==s[r] )
        {
            if( l >= 1 &&  r < s.size()-1 && s[l-1] == s[r+1])
            {
               l--;
               r++;
            }
            else
                break;
        }

        int len = r - l +1;

        return len == s.size() ? s : s.substr(l,r);
    }
    string longestPalindrome(string s) {
        if(s.length() == 0)
            return "";
        if(s.length() == 1)
            return s;
        if(s.length() ==2)
            return s[0] == s[1] ? s : s.substr(0,1);
        string res;
        int len = s.length();
        if(len%2 == 0)
        {
            int idx = len/2;
             res = find(s, idx -1, idx);
        }
        else
        {
            int idx = len/2;
             res = find(s, idx, idx);
        }
        
        return res;
    }
};

int main()
{
    string s = "ccc";
    Solution a;
    cout << a.longestPalindrome(s);
    cout << endl << a.longestPalindrome("babad");
    cout << endl << a.longestPalindrome("cbba");

}