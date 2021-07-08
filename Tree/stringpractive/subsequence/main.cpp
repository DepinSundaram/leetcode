#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<vector<int>> res;
vector<vector<int>> subsets(vector<int>& nums) 
    {
        int n = nums.size(), p = 1 << n;
        vector<vector<int>> subs(p);
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < n; j++) {
                if (i & (1<<j)) {
                    subs[i].push_back(nums[j]);
                }
            }
        }
        return subs;
    }


void subsequence(vector<int>&num, int start, int len, vector<int>& sub)
{
    if(sub.size() == len)
    {
        res.push_back(sub);
    }

    for(int i = start; i < num.size(); i++)
    {
        sub.push_back(num[i]);
        subsequence(num, i + 1, len, sub);
        sub.pop_back();
    }
}
int main()
{
    vector<int> nums{1,2,3};
    

    vector<vector<int>> res2 = subsets(nums);

    cout << "ALL subsequence" << endl;
    for(auto a: res2)
    {
        for(auto b: a)
            cout << b ;
        cout << endl;      
    }
    vector<int> sub;
    vector<int> num{1,2,3,4,5};
    cout << "ALL subsequence with len 3" << endl;
    subsequence(num, 0, 3, sub );
    for(auto a: res)
    {
        for(auto b: a)
            cout << b ;
        cout << endl;
    }

}