class Solution {
    int height(TreeNode* root, int &Maxdia){
        if(!root) return 0;
        int leftHeight = height(root->left,Maxdia);
        int rightHeight = height(root->right,Maxdia);
        int dia = leftHeight + rightHeight;
        Maxdia = max(dia,Maxdia);
        return 1 + max(leftHeight,rightHeight);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int Maxdia = 0;
        height(root ,Maxdia);
        return Maxdia;
    }
};