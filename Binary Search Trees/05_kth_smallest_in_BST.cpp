class Solution {
    void helper(TreeNode* root , int k , int& count ,int& ans){
        if(root==NULL || count >= k ) return;
        helper(root->left,k,count,ans);
        if( count >= k) return;
        count++;
        if( k == count) {
            ans = root->val;
            return;
        }
        helper(root->right,k,count,ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int ans = 0;
        helper(root,k,count,ans);
        return ans;
    }
};