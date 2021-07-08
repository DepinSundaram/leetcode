#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*

Find the k'th Largest or Smallest Element
Given an array arr find the k'th largest element.

Example 1:
Input:
arr = [1,2,3,4,5,6]
k = 1

Output: 6
Explanation: 6 is the 1st largest element

Example 2:
Input:
arr = [1,2,3,4,5,6]
k = 6

Output: 1
Explanation: 1 is the 6th largest element


*/

class Solution
{
public:
      int partition(vector<int>&arr, int left, int right, int pivotIndx)
      {
          int pivot = arr[pivotIndx];
          int lesseritemsIndx = left;

          swap(arr[pivotIndx], arr[right]);

          for(int i = left; i < right; i++)
          {
              if(arr[i] > pivot)
              {
                  swap(arr[left], arr[i]);
                  lesseritemsIndx++;
              }
          }

          swap(arr[lesseritemsIndx], arr[right]);

          return lesseritemsIndx;
      }


      int kthLargest(vector<int>& arr, int k)
      {
          int size = arr.size();
          int left = 0;
          int right = arr.size() -1;
          while(left  <= right)
          {

              int pivotIndxx = right;
              int finalPivotChosen = partition(arr, left, right, pivotIndxx);

              if(finalPivotChosen == size - k)
              {
                  return arr[finalPivotChosen];
              }
              else if(finalPivotChosen > size - k)
              {
                  right = finalPivotChosen - 1;
              }
              else
                left = finalPivotChosen + 1;
          }

          return -1;
      }
};
int main()
{

    vector<int> arr {1,2,3,4,5,6};
    int k = 6;

    Solution a;
    int res = a.kthLargest(arr, k);
    cout << res;
}