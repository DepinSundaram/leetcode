#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution
{
    vector<string> res;
public:

    unordered_map<char, string> mapping {
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}
    };

    void backtracking(string sub, string digit)
    {
        if(digit.size() == 0)
            res.push_back(sub);
        for(char c : mapping[digit[0]])
        {
            backtracking(sub+c, digit.substr(1));
        }
    }
    vector<string> letterCombinations(string digits) {
         if (!digits.size()==0)
             backtracking( "", digits);
        return res;
    }
};

int main()
{
    vector<string> res;
    string num = "23";
    Solution a;

    res = a.letterCombinations(num);

    for(auto a : res)
    {
        cout << a << endl;

    }

}