class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int start = 0;
        int end = nums.size()-1;

        int mid = (start + end) / 2;

        while (true)
        {
          
            if (nums[mid] == target)
            {
                break;
            }
            else if (nums[mid] < target)
            {
                start = mid + 1;
                if (start > end)
                {
                    return start;
                }
            }
            else
            {
                end = mid - 1;
                if (start > end)
                {
                    return start;
                }
            }
            mid = (start + end) / 2;

        }

        return mid;
    }
};