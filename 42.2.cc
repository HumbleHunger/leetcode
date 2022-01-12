#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
			int lhigh = 0;
			int rhigh = 0;
			int num = 0;
			int sum = 0;
			for (int i = 1; i < height.size() - 1; ++i) {
				lhigh = height[i];
				rhigh = height[i];
				num = 0;
				for (int j = i - 1; j >= 0; --j) {
					lhigh = max(lhigh, height[j]);
				}
				for (int j = i + 1; j < height.size(); ++j) {
					rhigh = max(rhigh, height[j]);
				}
				if (lhigh > height[i] && rhigh > height[i]) {
					num = min(lhigh, rhigh) - height[i];
				}
				sum += num;
			}
			return sum;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
			vector<int> lmax(height.size(), 0);
			vector<int> rmax(height.size(), 0);
			lmax[0] = height[0];
			rmax.back() = height.back();
			int sum = 0;

			for (int i = 1; i < height.size(); ++i) {
				lmax[i] = max(lmax[i - 1], height[i]);				
			}

			for (int i = height.size() - 2; i >= 0; --i) {
				rmax[i] = max(rmax[i + 1], height[i]);	
			}

			for (int i = 0; i < height.size(); ++i) {
				if (lmax[i] > height[i] && rmax[i] > height[i]) {
					sum += min(lmax[i], rmax[i]) - height[i];
				}
			}
			return sum;
    }
};