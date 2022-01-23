#include <bits/stdc++.h>
#include <fcntl.h>
#include <unistd.h>
using namespace std;

class Solution {
public:
		int hash[128] = {0};
    void func(string text) {
			for (auto c : text) {
				hash[c]++;
			}
		}

		pair<char, int> result() {
			int max = 0;
			int index = 0;
			for (int i = 0; i < 128; ++i) {
				if (hash[i] > max) {
					max = hash[i];
					index = i;
				}
			}
			return {index, max};
		}
};

int main(int argc, char** argv) {
	int fd = ::open(argv[1], O_RDONLY | O_CLOEXEC);
	char buf[1024];
	memset(buf, 0, 1024);
	Solution s;
	while (::read(fd, buf, 1024) > 0) {
		s.func(buf);
	}
	auto ret = s.result();
	cout << ret.first << " " << ret.second << endl;
	return 0;
}