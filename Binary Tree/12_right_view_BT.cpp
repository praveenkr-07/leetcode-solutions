class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return {}; 
        if(! root->left && ! root->right) return {root->val};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(! q.empty()){
            int size = q.size();
            for(int i = 0 ; i <= (size-1); i++){
                TreeNode* temp = q.front(); q.pop();
                if(i==size-1){
                    ans.push_back(temp->val);
                }
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
        }
        return ans;
    }
};