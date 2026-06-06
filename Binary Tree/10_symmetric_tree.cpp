class Solution {
    bool helper(TreeNode* l , TreeNode* r){
        if(l==NULL && r==NULL ) return true;
        if(l==NULL || r==NULL ) return false;
        if(l->val != r-> val) return false;
        else return (helper(l->left , r->right) && helper(l->right , r->left));
    }
public:
    bool isSymmetric(TreeNode* root) {
        return helper(root->left , root->right);
    }
};