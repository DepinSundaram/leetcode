#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> reverseClock(vector<vector<int>>& vec)
    {
        int size = vec.size();

        if(size == 0)
            return vec;
        
        for(int i = 0 ; i < size; i++)
        {
            for(int j = 0; j < i;j++)
            {
                swap(vec[i][j], vec[j][i]);
            }
        }

        for(int i = 0; i < size; i++)
        {
            reverse(vec[i].begin(), vec[i].end());
        }

        return vec;
    }

    vector<vector<int>> rotateAnti(vector<vector<int>>& vec)
    {

        int size = vec.size();

        if(size == 0)
            return vec;
        
        for(int i = 0 ; i < size; i++)
        {
            for(int j = 0; j < i;j++)
            {
                swap(vec[i][j], vec[j][i]);
            }
        }


        for(int i = 0; i < size; i++)
        {
            int len = size-1;

            for(int j = 0; j < size/2; j++)
            {
                swap(vec[j][i], vec[len-j][i]);
            }
        }

        return vec;
    }
};

int main()
{
    vector<vector<int>> num =
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    vector<vector<int>> num2(num.begin(), num.end());
    Solution a;
    //vector<vector<int>> res = a.reverseClock(num);
    vector<vector<int>> res = a.rotateAnti(num);

    for(auto r : res)
        for(auto i: r)
            cout << i;

}