class Solution { 
    void helper(TreeNode* root){
        
        //base condition
        if(root==NULL) return;

        // swapping
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        helper(root->left);
        helper(root->right);
        }
public:
    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
};