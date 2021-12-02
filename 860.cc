#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
			int n5 = 0;
			int n10 = 0;
			int n20 = 0;
			for (int i = 0; i < bills.size(); ++i) {
				switch (bills[i])
				{
				case 5:
					n5++;
					break;
				case 10:
					n10++;
					n5--;
					break;
				case 20:
					n20++;
					if (n10 > 0) {n10--; n5--;}
					else n5 -= 3;
					n20++;
					break;
				default:
					break;
				}
				if (n5 < 0 || n10 < 0 || n20 < 0) {
					return false;
				}
			}
			return true;
    }
};