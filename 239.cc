#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    class myqueue {
    public:
        deque<int> q;

        myqueue() {}

        void pop(int val)
        {
            if (!q.empty() && val == front())
            {
                q.pop_front();
            }
        }

        void push(int val)
        {
            while (!q.empty() && val > q.back())
            {
                q.pop_back();
            }
            q.push_back(val);
        }

        int front()
        {
            return q.front();
        }

        int size()
        {
            return q.size();
        }
    };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        myqueue q;
        vector<int> ret;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i < k)
            {
                q.push(nums[i]);
                continue;
            }
            ret.push_back(q.front());
            q.pop(nums[i -k]);
            q.push(nums[i]);
        }
        ret.push_back(q.front());
        return ret;
    }
};

int main()
{
    Solution s;
    vector<int> v = {1,3,-1,-3,5,3,6,7};
    for (auto& i : s.maxSlidingWindow(v, 3))
    {
        cout << i << " ";
    }
    cout << endl;
}