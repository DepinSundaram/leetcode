#include <iostream>
#include <vector>
#include <deque>
using namespace std;

void main()
{
	vector<int> nums ;
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(0);
	nums.push_back(5);/*
	nums.push_back(6);
	nums.push_back(7);*/
	//{1,3,-1,-3,5,3,6,7};
	deque<int> dq;

	int max = INT_MIN;
	vector <int> subresult;
	int size = nums.size();
	int window = 3;
	int count = 0;
	for(int i = 0; i < size; i++)
	{
		if(count!=window)
		{
			if( i == 0)
			{
				dq.push_front(nums[i]);
				count++;
			}
			else if ( dq.size()> 0 && dq.front() < nums[i])
			{
				while(dq.size()> 0 && dq.front() < nums[i])
				{
					dq.pop_front();
				}
					dq.push_front(nums[i]);
					count++;
			}
			else 
			{
				while(dq.size()> 0 && nums[i] > dq.back())
				{
					dq.pop_back();
				}
				dq.push_back(nums[i]);
				count++;
			}
		}
		if(count == window)
		{
			subresult.push_back(dq.front());
			count--;
			if(dq.front() == nums[i-(window-1)])
			{
				dq.pop_front();
				
			}
		}
	}
	cout << "EXIT";
	cin.ignore();
}