class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) 
	{
		std::unordered_map<char, int> umap;
		for (auto ch : ransomNote)
		{
			umap[ch]++;
		}
		int zeroCount = 0;

		for (auto ch : magazine)
		{
			auto iter = umap.find(ch);
			if (iter == umap.end())
			{
				continue;
			}
			if (--umap[ch] == 0)
			{
				zeroCount++;
			}
		}
		return zeroCount == umap.size();
		
	}
};