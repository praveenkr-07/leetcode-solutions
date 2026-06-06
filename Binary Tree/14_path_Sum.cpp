class Solution {
    bool isLeaf(TreeNode* root){
        return( ! root->left && ! root->right );
    }
    bool helper(TreeNode* root, int targetSum ,int sum ){
        if(root==NULL) return false;
        if(isLeaf(root) && (sum+root->val) ==targetSum  ) {
            return true;
        }

        bool left = helper(root->left,targetSum,sum+root->val);
        bool right = helper(root->right,targetSum,sum+root->val);

        return left || right;
    } 
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
       return helper(root,targetSum,0);
    }
}; 