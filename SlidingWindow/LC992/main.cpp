#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
Given an array nums of positive integers, call a (contiguous, not necessarily distinct) subarray of nums good if the number of different integers in that subarray is exactly k.

(For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.)

Return the number of good subarrays of nums.

 

Example 1:

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers:
[1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
Example 2:

Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].

*/
  
class Solution {
public:
    
    int check(vector<int>& nums , int K){
        if(K==0)
            return 0;
        int size=nums.size();
        int total=0;
        int discont=0;
        int left=0;
        vector<int>count(nums.size()+1);
        for(int right=0;right<size;right++){
            if(count[nums[right]]==0){
                discont++;
                count[nums[right]]++;
            }
            else{
                count[nums[right]]++;
            }
            if(discont<=K){
                total+=(right-left+1);
            }
            else{ 
                while(left<size && left<=right && discont>K){
                    count[nums[left]]--;
                    if(count[nums[left]]==0)
                        discont--;
                    left++;
                }
                total+=(right-left+1);
            }
        }
        return total;
    }
    
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return check(A,K)- check(A,K-1);
    }
};

int main()
{
    Solution a;
    vector<int>  nums {1, 2};
    /*
   1        1

   2        2
   12

   1        1
   21
   121

   2        2
   12
   212
   1212

   3        3
   23

    */
    int k =1;
    cout << a.subarraysWithKDistinct(nums, k);
}