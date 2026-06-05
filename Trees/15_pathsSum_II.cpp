class Solution {
public:
    bool isLeaf(TreeNode* root){
        return (! root->left) && (! root->right);
    }
    void helper(TreeNode* root, int targetSum ,vector<vector<int>> &ans,int sum,vector<int> &v){

        if(root==NULL) {
            return;
        }

        v.push_back(root->val);

        if(isLeaf(root) && sum+root->val == targetSum){
            ans.push_back(v);
        }

        
        helper(root->left,targetSum,ans,root->val+sum,v);
        helper(root->right,targetSum,ans,root->val+sum,v);
        // backtrack step
        v.pop_back();
       
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(root,targetSum,ans,0,v);
        return ans;
    }
};

// without using backtracing

class Solution {
public:
    bool isLeaf(TreeNode* root){
        return (! root->left) && (! root->right);
    }
    void helper(TreeNode* root, int targetSum ,vector<vector<int>> &ans,int sum,vector<int> v){

        if(root==NULL) {
            return;
        }

        v.push_back(root->val);

        if(isLeaf(root) && sum+root->val == targetSum){
            ans.push_back(v);
        }
        helper(root->left,targetSum,ans,root->val+sum,v);
        helper(root->right,targetSum,ans,root->val+sum,v);

       
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(root,targetSum,ans,0,v);
        return ans;
    }
};
