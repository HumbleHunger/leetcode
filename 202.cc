#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int getsum(int n)
	{
		int sum = 0;
		while (n)
		{
			sum += (n % 10) * (n % 10);
			n /= 10;
		}
		return sum;
	}

    bool isHappy(int n) {
		unordered_set<int> set;
		
		int sum = n;
		while (1)
		{
			sum = getsum(sum);
			if (sum == 1)
			{
				return true;
			}

			if (set.find(sum) != set.end())
			{
				return false;
			}
			else
			{
				set.insert(sum);
			}
			
		}

	}
};