class Solution {
public:

    bool Run(TreeNode* p, TreeNode* q)
    {
	    if(p == nullptr && q != nullptr)
	    {
            return false;
	    }
        if (p != nullptr && q == nullptr)
        {
            return false;
        }
        if (p == nullptr && q == nullptr)
        {
            return true;
        }

        if(p->val == q->val)
        {
            auto result1 = Run(p->left, q->left);
            auto result2 = Run(p->right, q->right);

            return result1 == true && result2 == true;
        }
        else
        {
            return false;
        }


    }
    bool isSameTree(TreeNode* p, TreeNode* q)
	{
        return Run(p, q);
    }
};