class Solution {
public:
    void helper(TreeNode* root , int targetSum , long long sum , int& count){
        if(root==NULL) return; 
        sum=sum+root->val;
        if(targetSum==sum) count++;
        helper(root->left,targetSum , sum ,count);
        helper(root->right,targetSum, sum ,count);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        int count = 0; 
        int sum = 0;
        helper(root,targetSum,sum,count);
       count+= pathSum(root->left , targetSum) +  pathSum(root->right ,targetSum);
        return count;
    }
};