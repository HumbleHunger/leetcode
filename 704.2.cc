class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (right >= left) {
            int might = (right + left) / 2;
            if (nums[might] > target) {
                right = might - 1;
            } else if (nums[might] < target) {
                left = might + 1;
            } else {
                return might;
            }
        }
        return -1;
    }
};