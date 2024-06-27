class Solution {
public:
    bool isValid(string s) {
        stack<char> lastChStack;
        unordered_map<char, char> tempMap = { {'{','}'},{'(',')'},{'[',']'} };
        if (s.size() % 2 == 1)
        {
            return false;
        }
        if (s.size() == 0)
        {
            return false;
        }
        
        for (int i = 0; i < s.size(); i++)
        {
            if (lastChStack.empty())
            {
                if (s[i] == '}' || s[i] == ')' || s[i] == ']')
                {
                    return false;
                }
            }
            if (s[i] == '{' || s[i] == '(' || s[i] == '[')
            {
                lastChStack.push(s[i]);
            }
            else if (s[i] == '}' || s[i] == ')' || s[i] == ']')
            {
                if (tempMap[lastChStack.top()]!= s[i])
                {
                    return false;
                }
                lastChStack.pop();
            }
            else
            {
                return false;
            }
          
        }

        return lastChStack.empty();
    }
};