class Solution {
    void trim(TreeNode* root, int low, int high){
        if(root==NULL) return;
        while(root->left){
            if(root->left->val < low) root->left=root->left->right;
            else if(root->left->val > high) root->left=root->left->left;
            else break;

        }
        while(root->right){
            if(root->right->val > high)  root->right=root->right->left;
            else if(root->right->val < low) root->right=root->right->right;
            else break;
        }
        trim(root->left,low,high);
        trim(root->right,low,high);
    } 
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode* dummy = new TreeNode(INT_MAX);
        dummy->left = root;
        trim(dummy,low,high);
        TreeNode* newRoot = dummy->left;
        delete dummy;
        return newRoot;
    }
};


// Method 2
class Solution {
    TreeNode* trim(TreeNode* root, int low, int high){
        if(root == NULL) return NULL; 
        if(root->val < low) return trim(root->right,low,high);
        if(root->val > high) return trim(root->left,low,high);
        root->left = trim(root->left,low,high);
        root->right = trim(root->right,low,high);
        return root;
    } 
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return trim(root,low,high);
    }
};