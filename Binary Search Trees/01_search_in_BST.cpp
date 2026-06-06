class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int target) {
        if(root==NULL || root->val == target) return root;
        else if(target < root->val) return searchBST(root->left, target);
        else   return searchBST(root->right, target);
    }
};