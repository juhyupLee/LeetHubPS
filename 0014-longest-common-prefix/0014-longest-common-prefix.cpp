class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        if (strs.size() == 0)
        {
            return "";
        }

        string prefix = strs[0];

        for (int i = 1; i < strs.size(); ++i)
        {
            while (true)
            {
                auto result = strs[i].find(prefix);

                if (result == 0)
                {
                    break;
                }
                prefix = prefix.substr(0, prefix.size() - 1);
            }
        }

        return prefix;
    }
};