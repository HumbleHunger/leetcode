class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowp = 0;
        for (int fastp = 0; fastp < nums.size();  ++fastp)
        {
            if (val != nums[fastp])
            {
                nums[slowp++] = nums[fastp];
            }
        }
        return slowp;
    }
};
