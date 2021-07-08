#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    bool cmp(vector<int>& a ,vector<int>& b )
    {
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedList;
        if(intervals.size() == 0)
            return mergedList;

        sort(intervals.begin(), intervals.end());

        vector<int> temp =  intervals[0];

        for(auto i : intervals)
        {
            if(i[0] <= temp[1])
            {
                temp[1] = max(i[1], temp[1]);
            }else
            {
            mergedList.push_back(temp);
            temp = i;
            }

        }

        
        mergedList.push_back(temp);
        return mergedList;
        
    }
};


int main()
{
    vector<vector<int>> list = 
    {
        {1,3},
        {2,6},
        {8,10},
        {9,18}
    };

    Solution a;
    a.merge(list);

    for(auto i: list)
        for (int j : i)
            cout << j;

}
