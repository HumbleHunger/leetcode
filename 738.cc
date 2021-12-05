#include <bits/stdc++.h>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
			string s = to_string(n);
			
			int flag = s.size();

			for (int i = s.size() - 1; i > 0; --i) {
				if (s[i - 1] > s[i]) {
					s[i - 1]--;
					for (int j = i; j < flag; ++j) {
						s[j] = '9';
					}
					flag = i;
				}
			}
			return stoi(s);
    }
};