class Solution {
public:
	int majorityElement(vector<int>& nums)
	{
		unordered_map<int, int> umap;
		int maxValue = 0;
		int maxIndex = -1;
		for(int i=0; i<nums.size();++i)
		{
			umap[nums[i]]++;

			if(maxValue<umap[nums[i]])
			{
				maxValue = umap[nums[i]];
				maxIndex = nums[i];
			}
		}

		return maxIndex;
	}
};