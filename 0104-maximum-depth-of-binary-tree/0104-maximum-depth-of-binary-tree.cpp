class Solution {
public:

    int maxLev = INT32_MIN;

    void Run(int lev, TreeNode* root)
    {
        if (root == nullptr)
        {
            maxLev = max(maxLev, lev);
            return;
        }

        Run(lev+1,root->left);
        Run(lev+1,root->right);

    }
    int maxDepth(TreeNode* root) 
    {
        Run(0, root);

        return maxLev;
    }
};