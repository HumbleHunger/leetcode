#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
			for (auto &n : obstacleGrid) {
				for (auto &m : n) {
					if (m == 1) m = -1;
					cout << m;
				}
				cout << endl;
			}

			int m = obstacleGrid.size();
			int n = obstacleGrid[0].size();

			for (int i = 0; i < m; ++i) {
				if (obstacleGrid[i][0] == -1) break;
				obstacleGrid[i][0] = 1;
			}
			for (int i = 0; i < n; ++i) {
				if (obstacleGrid[0][j] == -1) break;
				obstacleGrid[0][j] = 1;
			}
			cout << m << " "  << n << endl;
			for (int i = 1; i < m; ++i) {
				for (int j = 1; j < n; ++j) {
					int n1 = 0;
					int n2 = 0;
					cout << obstacleGrid[i][j - 1] << "sss" << obstacleGrid[i - 1][j] << endl;
					if (obstacleGrid[i][j] == -1) continue;

					if (obstacleGrid[i][j - 1] != -1) {
						n1 = obstacleGrid[i][j - 1];
					}
					if (obstacleGrid[i - 1][j] != -1) {
						n2 = obstacleGrid[i - 1][j];
					}
					cout << n1 << "  " << n2 << endl;
					obstacleGrid[i][j] = n1 + n2;
				}
			}

			for (auto n : obstacleGrid) {
				for (auto m : n) {
					cout << m;
				}
				cout << endl;
			}
			return obstacleGrid[m - 1][n - 1];
    }

};

int main() {
	Solution s;
	vector<vector<int>> v({{0,0,0},{0,1,0},{0,0,0}});
	cout << s.uniquePathsWithObstacles(v) << endl;
}