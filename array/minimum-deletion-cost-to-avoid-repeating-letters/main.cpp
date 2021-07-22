#include <iostream>
#include <vector>
#include <string>
using namespace std;

int minCost(string s, vector<int>& cost)
{
	int res = 0;
	int i = 0;

	while (i < s.size())
	{
		char c = s[i];
		int cur = 0;
		int mx = 0;

		while (c == s[i])
		{
			mx = max(mx, cost[i]);
			cur += cost[i];
			i++;
		}

		if (cur != mx)
			res += cur - mx;
	}

	return res;
}

int main()
{
    vector<int> num = {1,2,3,4,5};
    int res =  minCost("abaac", num);
    
}