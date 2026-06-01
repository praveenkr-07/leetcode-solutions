/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        vector<int> v;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* temp = st.top();
            st.pop();

            v.push_back(temp->val);
             if(temp->left) st.push(temp->left);
            if(temp->right) st.push(temp->right);
           
        }
        reverse(v.begin(),v.end());
        return v;
    }
};