#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
Given a sorted integer array arr, two integers k and x, 
return the k closest integers to x in the array.
The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
 

Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
Example 2:

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]
 

Constraints:

1 <= k <= arr.length
1 <= arr.length <= 104
arr is sorted in ascending order.
-104 <= arr[i], x <= 104

*/
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if(arr.size() == 0 || k == 0)
            return vector<int>{};
        vector<int> ans;
        priority_queue<pair<int, int>> res;
        for(int i = 0; i < arr.size(); i++)
        {
            res.push(make_pair(abs(x-arr[i]), arr[i]));

            if(res.size() > k)
                res.pop();
        }

        while(res.size() > 0)
        {
            ans.push_back(res.top().second);
            res.pop();
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};


// Solution 2
// https://leetcode.com/problems/find-k-closest-elements/discuss/1059266/C%2B%2B-%3A-Accepted%3A-Binary-Search
// 
// 
// https://leetcode.com/problems/find-k-closest-elements/discuss/885196/Simple-C%2B%2B-solution-beats-97



class Solution2 {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int start = 0, endd = arr.size()-1;
        while(endd-start+1 > k) {
            if( abs(arr[start]-x) > abs(arr[endd]-x))
                start++;
            else endd--;
        }
        vector<int> ans(arr.begin()+start,arr.begin()+endd+1);
        return ans;
    }
};


class Solution3
 {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
     //modified  binary search   
     int lo = 0;
     // difference 1: note it is not arr.size()-1 ,i.e leave k elements
     int hi = arr.size()-k -1;
     while(lo <= hi)
     {
         int mid = lo+(hi-lo)/2;
         
         // difference 2: easy way to remember
         // x is mid point :
         // x = (arr[mid+k] + arr[mid +k])/2
         // abs value will not work because sign is important to handle
         
         if(x - arr[mid] > arr[mid + k] -x)
         {
                // go right
                lo = mid +1;
         }
         else
         {
             // difference 2: handle equals  and "less than" sign case with same logic 
             // go left
             hi = mid-1;
         }
        }
        
        vector<int> res(arr.begin()+ lo, arr.begin()+ lo +k);
        return res;
    }
};
int main()
{

    vector<int> arr = {1,2,3,4,5};
    Solution a;
    vector<int> res = a.findClosestElements(arr, 4, 3);

}