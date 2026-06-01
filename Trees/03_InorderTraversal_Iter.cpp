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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        stack<TreeNode* > st;
        TreeNode* node = root;
        vector<int> v;
        while(!st.empty()||node!=NULL){
            if(node!=NULL){
                st.push(node);
                node=node->left;
            }
            else{
                TreeNode* temp = st.top();
                st.pop();
                v.push_back(temp->val);
                node=temp->right;
            }
        }
        return v;
    }
};