class Solution {
    void helper(TreeNode* root, int low, int high , int& sum ){
        if(root==NULL) return;
        helper(root->left,low,high,sum);
        if(root->val >= low && root->val<= high) {
            sum+=root->val;
        }
        helper(root->right,low,high,sum);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0; 
        helper(root,low,high,sum);
        return sum;   
    }
};