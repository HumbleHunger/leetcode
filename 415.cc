#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
		int atoi(char c) {
			return c - '0';
		}

    string addStrings(string num1, string num2) {
				int i = num1.size() - 1;
        int j = num2.size() - 1;
				int flag = 0;
				string ret;
				while (i >= 0 && j >= 0) {
					int a = atoi(num1[i]);
					int b = atoi(num2[j]);
					int sum = a + b + flag;
					flag = sum / 10;
					int c = sum % 10;
					ret += to_string(c);
					i--;
					j--;
				}
				if (i >= 0) {
					while (flag && i >= 0) {
						int a = atoi(num1[i]);
						int sum = a + flag;
						flag = sum / 10;
						int c = sum % 10;
						ret += to_string(c);
						i--;
					}
					if (flag && i < 0) ret += to_string(flag);
					if (i >= 0) {
						string str = num1.substr(0, i + 1);
						reverse(str.begin(), str.end());
						ret += str;
					}
				} else if (j >= 0) {
					while (flag && j >= 0) {
						int a = atoi(num2[j]);
						int sum = a + flag;
						flag = sum / 10;
						int c = sum % 10;
						ret += to_string(c);
						j--;
					}
					if (flag && j < 0) ret += to_string(flag);
					if (j >= 0) {
						string str = num2.substr(0, j + 1);
						reverse(str.begin(), str.end());
						ret += str;
					}	
				} else {
					if (flag) ret += to_string(flag);
				}
				return ret;
    }
};