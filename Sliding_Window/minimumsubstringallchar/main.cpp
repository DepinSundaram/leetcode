#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;


string substring(string s)
{
    int min_len = INT_MAX;
    int n = s.length();

    int dist_count = 0;

    bool visited[256] = {false};

    for(int i = 0; i < n; i++)
    {
        if(visited[s[i]] == false)
        {
            visited[s[i]] = true;
            dist_count++;
        }
    }

    int left = 0, right = 0;
    int startIdx;
    int cur_count[256] = {};
    int count =0;
    for(int right = 0; right < n; right++)
    {
        cur_count[s[right]]++;

        if(cur_count[s[right]] ==1)
            count++;

        if(count == dist_count)
        {
            while(cur_count[s[left]] > 1)
            {
                if(cur_count[s[left]] >1)
                {
                    cur_count[s[left]]--;
                }
                left++;
            }

            int len_win = right - left + 1;
            if(min_len > len_win)
            {
                min_len = len_win;
                startIdx = left;
            }
        }
        
    }

    return s.substr(startIdx, min_len);
}

string findStr(string s, string t)
{

    if(t.length() == 0 || t.length() > s.length())
        return "";

    int start = 0;
    int minleft = 0;
    int count = 0;
    int len = INT_MAX;
    unordered_map<char, int> mp;
    for(char a: t)
    {
        if(mp.find(a) != mp.end())
        {
            mp[a]++;
        }
        else
            mp[a] = 1;
    }

    for(int i = 0; i< s.length(); i++)
    {
        if(mp.find(s[i])!=mp.end())
        {
            mp[s[i]]--;
            count++;
        }

        if(count == t.size())
        {
            while(count == t.size())
            {
                if(len > i - start + 1)
                {
                    len = i - start + 1;
                    minleft = start;
                }
                if(mp.find(s[start])!= mp.end())
                {
                    mp[s[start]]++;
                    if(mp[s[start]]>=0)
                        count--;
                }
                start++;
            }
        }

    }

        if(len > s.size())
            return "";
        return s.substr(minleft, len);

}
int main()
{
    string res = substring("aabcbcdbca");
    cout << res << endl;

    string res2  = findStr("ADOBECODEBANC", "ABC");
    cout << res2; 
}