class Solution {
    void helper(TreeNode* root , string str , vector<string>  &ans ){
        if(root==NULL) return;

        string app = to_string(root->val);

        if(root->left== NULL && root->right==NULL){
            str+=app;
            ans.push_back(str);
            return;
        }
        helper(root->left,str+app+"->",ans);
        helper(root->right,str+app+"->",ans);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        helper(root,"",ans);

        return ans;
        
    }
};