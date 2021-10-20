#include <bits/stdc++.h>

using namespace std;

class Solution {
	bool isAnagram(string s, string t) {
		map<char, int> s_map;
		map<char, int> t_map;
		for (auto& a : s)
		{
			s_map[a]++;
		}
		
		for (auto& a : t)
		{
			t_map[a]++;
		}

		if (s_map.size() != t_map.size())
		{
			return false;
		}
		
		for (auto it1 : s_map)
		{
			auto it2 = t_map.find(it1.first);
			if (it2 == t_map.end())
			{
				return false;
			}
			else
			{
				if (it1.second != it2->second)
				{
					return false;
				}
			}
		}
		return true;
	}
};