#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
		int record[26] = {0};
		for (auto c : magazine)
		{
			record[c - 'a']++;
		}

		for (auto c : ransomNote)
		{
			cout << record[c - 'a'] << endl;
			cout << c - 'a' << endl;
			if (--record[c - 'a'] < 0)
				return false;	
		}
		return true;
    }
};

int main()
{
	Solution s;
	s.canConstruct("a", "b");
	return 0;
}