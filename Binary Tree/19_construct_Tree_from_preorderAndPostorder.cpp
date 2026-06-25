class Solution
{
    TreeNode *build(vector<int> &pre, int preLo, int preHi, vector<int> &post, int postLo, int postHi, unordered_map<int, int> &mp)
    {

        if (preLo > preHi || postLo > postHi)
            return NULL;
        TreeNode *root = new TreeNode(pre[preLo]);

        if (postLo == postHi)
            return root;

        int i = mp[pre[preLo + 1]];
        int leftCnt = i - postLo + 1;

        root->left = build(pre, preLo + 1, preLo + leftCnt, post, postLo, i, mp);
        root->right = build(pre, preLo + leftCnt + 1, preHi, post, i + 1, postHi - 1, mp);
        return root;
    }

public:
    TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post)
    {
        int n = pre.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
            mp[post[i]] = i;
        return build(pre, 0, n - 1, post, 0, n - 1, mp);
    }
};

