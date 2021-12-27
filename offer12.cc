#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool f(vector<vector<char>>& board, string word, int i, int j, char index) {
			if (index >= word.size()) return true;
			int ret = false;
			// 上
			if (i > 0 && board[i - 1][j] == word[index]) {
				ret = f(board, word, i - 1, j, index + 1);
			}
			// 下
			if (i < board.size() - 1 && board[i + 1][j] == word[index]) {
				ret = f(board, word, i + 1, j, index + 1);
			}
			// 左
			if (j > 0 && board[i][j - 1] == word[index]) {
				ret = f(board, word, i, j - 1, index + 1);
			}
			// 右
			if (j < board.size() - 1 && board[i][j + 1] == index) {
				ret = f(board, word, i, j + 1, index + 1);
			}
			return ret;
		}

    bool exist(vector<vector<char>>& board, string word) {
			int i, j;
			int m = 0;
			for (i = 0; i < board.size(); ++i) {
				for (j = 0; j < board[0].size(); ++j) {
					if (board[i][j] == word[0]) { m = 0; break; }
				}
			}
			if (m) f(board, word, i, j, 1);
    }
};