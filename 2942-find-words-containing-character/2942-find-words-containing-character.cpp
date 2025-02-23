class Solution {
public:
	vector<int> findWordsContaining(vector<string>& words, char x) 
	{
		vector<int32_t> result;

		for (auto i = 0; i<words.size();++i)
		{
			if (words[i].find(x, 0) != std::string::npos)
			{
				result.push_back(i);
			}
		}

		return result;
	}
};