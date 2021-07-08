#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    vector<string> ans;

public:

    void check(string res, int count, int n)
    {
        if(count < 0)
            return;
        if(res.size() > 2 *n) return;

        if(res.size() == 2 * n)
        {
            ans.push_back(res);
        }

        check(res +"(", count + 1, n );
        check(res +")", count - 1, n);

        return;
    }
    vector<string> generateParenthesis(int n) {
        string res = "";

        check(res, 0, n);

        return ans;
    }
};


int main()
{
    int n = 3;

    Solution a;

    vector<string> ans = a.generateParenthesis(n);

}