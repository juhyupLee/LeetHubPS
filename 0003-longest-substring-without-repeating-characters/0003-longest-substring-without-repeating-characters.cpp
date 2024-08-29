class Solution {
public:
    int lengthOfLongestSubstring(string s)
	{
        string subString = "";
        int maxCnt = INT32_MIN;

        if(s.length() == 0)
        {
            return 0;
        }

        if (s.length() == 1)
        {
            return 1;
        }

        for(int i=0; i<s.size();++i)
        {
            for(int j=i; j<s.size(); ++j)
            {
                if (subString.find(s[j]) == std::string::npos)
                {
                    subString += s[j];
                }
                else
                {
                    break;
                }
            }

            maxCnt = std::max(maxCnt, (int)subString.length());
            subString.clear();
        }

        return maxCnt;
    }
};