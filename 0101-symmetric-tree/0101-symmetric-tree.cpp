class Solution
{
public:
    struct TreeData
    {
        TreeNode* tree;
        int lev;
    };
    bool IsMirror(vector<int>& vec)
    {
        int lastIndex = vec.size() - 1;
        for(int i=0; i<vec.size()/2;++i)
        {
	        if(vec[i] != vec[lastIndex-i])
	        {
                return false;
	        }
        }

        return true;
    }

    bool isSymmetric(TreeNode* root)
    {
        queue<TreeData> q;
        TreeData data = { root,0 };
        int curLevel = 0;
        q.push(data);
        
        vector<int> result;
        while(!q.empty())
        {
            auto data = q.front();
            q.pop();

            if(data.lev != curLevel)
            {
                if(IsMirror(result) == false)
                {
                    return false;
                }
                result.clear();
            }

            curLevel = data.lev;

            if(data.tree== nullptr)
            {
                result.push_back(INT32_MIN);
            }
            else
            {
                result.push_back(data.tree->val);
                TreeData newDataLeft = { data.tree->left,curLevel + 1 };
                TreeData newDataRight = { data.tree->right,curLevel + 1 };

                q.push(newDataLeft);
                q.push(newDataRight);
            }
        }
        return true;
    }
};