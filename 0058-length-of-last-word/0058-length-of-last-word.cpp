class Solution {
public:
    int lengthOfLastWord(string s)
	{
		bool isCountStart = false;
		int result = 0;
		for (int i = s.size() - 1; i >= 0; --i)
		{
			if (s[i] == ' ' && isCountStart == true)
			{
				break;
			}
			if (s[i] != ' ')
			{
				if (isCountStart == false)
				{
					isCountStart = true;
				}
				result++;
			}
		}
		return result;
    }
};