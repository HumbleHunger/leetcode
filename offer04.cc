#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        int i = 0;
				int j = matrix[0].size() - 1;
        while (matrix[i][j] != target) {
            if (target < matrix[i][j]) {
                j--;
								if (j < 0) return false;
            } else if (target > matrix[i][j]) {
                i++;
								if (i >= matrix.size()) return false;
            } else return true;
        }
        return true;
    }
};