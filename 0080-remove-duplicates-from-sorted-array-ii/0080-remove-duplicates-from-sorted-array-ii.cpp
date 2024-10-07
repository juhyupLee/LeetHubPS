class Solution {
public:
	int removeDuplicates(vector<int>& nums)
	{
		if(nums.size() < 3)
		{
			return nums.size();
		}

		int insertIndex = 2;
		int lastNum = nums[1];
		int sameCount = nums[0] == nums[1] ? 1 : 0;

		for(int i=2; i<nums.size();++i)
		{
			if(lastNum == nums[i])
			{
				++sameCount;
			}
			else
			{
				sameCount = 0;
			}

			lastNum = nums[i];

			if(sameCount >= 2)
			{
				continue;
			}
			else
			{
				nums[insertIndex++] = nums[i];
			}
		}
		return insertIndex;
	}
};