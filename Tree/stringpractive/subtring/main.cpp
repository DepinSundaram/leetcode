#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    vector<string> res;
    string s = "abcd";

    for(int i = 0; i < s.length(); i++)
    {
        for(int j = 0; j <= s.length()-i; j++)
            res.push_back(s.substr(i,j));
    }

    for(auto c : res)
    {
        cout << c <<endl;
    }
}