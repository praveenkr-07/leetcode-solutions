
// O(N^2)
class Solution {
    int maxDepth(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + max(maxDepth(root->left),maxDepth(root->right));
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int rootLeft = maxDepth(root->left);
        int rootRight = maxDepth(root->right);
        if(abs(rootLeft-rootRight) <= 1) {
            return isBalanced(root->left) &&  isBalanced(root->right);
        }
        return false;
    }
};

// in 1 pass


class Solution {
    int maxDepth(TreeNode* root){
        if(root == NULL) return true;

        int leftDepth = maxDepth(root->left);
        if(leftDepth==-1) return -1;

        int rightDepth = maxDepth(root->right);
        if(rightDepth==-1) return -1;
        
        if(abs(leftDepth - rightDepth )>1) return -1;

        else return 1 + max(leftDepth , rightDepth);
    }
public:
    bool isBalanced(TreeNode* root) {
        return maxDepth(root) != -1 ;
        
    }
};


