class Solution {
public:
int sum = 0;
    void helper(TreeNode* root ){
        if(root==NULL) return ;
        helper(root->right );
        root->val+=sum;
        sum=root->val;
        helper(root->left );
    }
    TreeNode* bstToGst(TreeNode* root) {
        helper(root);
        return root;
    }
};