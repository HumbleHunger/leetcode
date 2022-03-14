#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int u = 0;
        int d = matrix.size() - 1;
        int l = 0;
        int r = matrix[0].size() - 1;
        vector<int> ret;
        if (matrix.empty()) return ret;
        while (true) {
            for (int i = l; i <= r; ++i) ret.push_back(matrix[u][i]);
            if (++u > d) break;
            for (int i = u; i <= d; ++i) ret.push_back(matrix[i][r]);
            if (--r < l) break;
            for (int i = r; i >= l; --i) ret.push_back(matrix[d][i]);
            if (--d < u) break;
            for (int i = d; i >= u; --i) ret.push_back(matrix[i][l]);
            if (++l > r) break;
        }
        return ret;
    }
};