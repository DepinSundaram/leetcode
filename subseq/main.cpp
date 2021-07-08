#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

/*vector<string>*/void Subsequence(string &s)
{

    set<vector<char>> res;
    //vector<vector<char>> res;
    int size = s.length();
    int limit = 1 << size;
    int j = 0;

    for(int i = 1; i < limit; ++i)
    {
        vector<char> subset;
        for(int j = 0; j < size ; ++j)
        {
            if((i & (1<<j)) !=0)
            {
                subset.push_back(s[j]);
            }
        }
        res.insert(subset);
        //res.push_back(subset);
    }

    for(auto i: res)
    {
        for(auto j : i)
        {
            cout << j ;
        }
        cout << endl;
    }

}

/*vector<vector<int>>*/ void Subsequence(vector<int> &num)
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
        res.push_back(subset);
    }
    for(auto i: res)
    {
        for(auto j : i)
        {
            cout << j ;
        }
        cout << endl;
    }
        
        
    //return res;

}

int main()
{

    string s = "aab";
    vector<string> res;
    //vector<int> t{1,2,3};
    Subsequence(s);


    return 0;
}