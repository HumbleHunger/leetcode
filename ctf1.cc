#include <iostream>
#include <vector>

using namespace std;

string flag;

void fun(string str1, string str2)
{
	if (str2[0] == 'a')
	{
		cout << "return" << endl;
		return;
	}
	string tmp;
	int i = 0;
	for (i = 0; i < 15; ++i)
	{
		if (str2[i] == 'a' || str1[i] == 'a')
		{
			cout << i << endl;
			cout << "sadjaksjfl" << endl;
			return;
		}
		if (str1[i] == str2[i])
		{
			flag.push_back('0');
			tmp.push_back('0');
		}
		else
		{
			flag.push_back('1');
			tmp.push_back('1');
		}
	}
	fun(tmp, &str2[i]);
}

int main()
{
	string f = "00000000011000010111001100100000011010010111001100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000";
	string ans = "11000010111001111100010100011110011001111110010100011000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000a";
	string q =   "000000000000000";
	string p =   "11000010111001100100000011010010111001100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000011010100100000";
	cout << ans.length() << endl;
	cout << q.length() << endl;
	/*for (int i = 0; i < 15; ++i)
	{
		flag.push_back(ans[i]);
	}*/	
	fun(q, ans);
	for (auto& c : flag)
	{
		cout << c;
	}
}