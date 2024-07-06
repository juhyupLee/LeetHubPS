class Solution {
public:
    int strStr(string haystack, string needle)
    {
        auto findIndex = haystack.find(needle);

        if (findIndex == std::string::npos)
        {
            return -1;
        }

        return findIndex;
    }
};