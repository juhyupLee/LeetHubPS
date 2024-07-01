 class Solution {
 public:
     int removeDuplicates(vector<int>& nums)
     {
         if(nums.size() == 0)
         {
             return 0;
         }

         int checkNum = nums[0];
         vector<int> result;
         result.push_back(nums[0]);


         for(size_t i=1; i<nums.size();++i)
         {
	         if(checkNum  != nums[i])
	         {
                 result.push_back(nums[i]);
	         }

             checkNum = nums[i];
         }

         nums = result;
         return static_cast<int>(result.size());
     }
 };