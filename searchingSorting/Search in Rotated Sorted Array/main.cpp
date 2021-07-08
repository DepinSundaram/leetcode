#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int size = nums.size() -1 ;
        
        return searchR(nums, target, 0, size);
        
    }
    
    int searchR(vector<int>& nums, int target, int start, int end)
    {
        if(start >= end)
            return -1;
        
        int mid = start + (end-start)/2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] > target)
            return searchR(nums, target, mid+1, end);
        else
            return searchR(nums, target, start, mid);
        
    }
};


int main()
{

    vector<int> nums = {4,5,6,7,0,1,2};

    Solution a;

    cout << a.search(nums, 0);
}
