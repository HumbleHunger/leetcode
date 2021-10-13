class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int count = 0;
        int length = 0;
        int left = 0;
        int right = 0;
        int ret = nums.size();
        for (auto &n : nums)
        {
            count += n;
        }
        if (count < target)
        {
            return 0;
        }
        count = 0;
        for (auto &n : nums)
        {
            count += n;
            ++right;
            ++length;
            if (count >= target)
            {
                while (1)
                {
                    if (count - nums[left] >= target)
                    {
                        count -= nums[left];
                        ++left;
                        --length;
                    }
                    else 
                    {
                        break;
                    }
                }
                if (ret > length)
                {
                    ret = length;
                }
            }
        }
        return ret;
    }
};
返回该题

