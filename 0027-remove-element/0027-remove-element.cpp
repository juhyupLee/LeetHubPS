class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {

        int insertIndex = 0;

        for (int j = 0; j < nums.size(); ++j)
        {
            if (nums[j] != val)
            {
                nums[insertIndex] = nums[j];
                ++insertIndex;
            }
        }

        return insertIndex;
    }
};