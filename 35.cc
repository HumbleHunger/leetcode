class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int might = (left + right) / 2;
            
            if (nums[might] == target)
                return might;
            
            if (nums[might] > target)
            {
                right = might - 1;
            }         
            else if(nums[might] < target)
            {
                left = might + 1;
            }
        }
        return right + 1;
    }
};
