class Solution {
public:
	string mergeAlternately(string word1, string word2)
	{
		string result;
		result.reserve(word1.size() + word2.size());
		int insertSize = 0;
		int word1Index = -1;
		int word2Index = -1;

		bool bTurn = false;

		while(insertSize != word1.size() + word2.size())
		{
			if (word1Index + 1 < word1.size())
			{
				insertSize++;
				result.push_back(word1[++word1Index]);

			}
			if(word2Index + 1 < word2.size())
			{
				insertSize++;
				result.push_back(word2[++word2Index]);
			}
		
		}

		return result;
	}
};
