class Solution {
public:
	int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) 
	{
		int result = 0;
		for (size_t i = 0; i < startTime.size(); ++i)
		{
			if (startTime[i] <= queryTime && queryTime <= endTime[i])
			{
				++result;
			}
		}

		return result;
	}
};
