class Solution {
    TreeNode* iop(TreeNode* root){
        TreeNode* pred = root->left;
        while(pred->right != NULL){
            pred = pred->right;
        }
        return pred;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val==key){
            // No child => leaf Node
            if(! root->left && ! root->right) return NULL;

            // 1 child 
            else if (! root->left || ! root->right){
                if(root->left){
                    return root->left;
                }
                else {
                    return root->right;
                }
            }
            // 2 childs
            else
            {
              TreeNode* pred = iop(root);
              root->val = pred->val;
              root->left = deleteNode(root->left,pred->val);
            }
        }
        else if(root->val > key){
            root->left = deleteNode(root->left,key);
        }
        else {
            root->right = deleteNode(root->right,key);
        }
        return root;
    }
};